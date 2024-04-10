//           
//         
//     
//     
//        
//           
#include <bits/stdc++.h>
 
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <algorithm>
using namespace std;
 
#define fst first
#define snd second
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
 
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))
 
#define ADD_OPERATORS_IN(T, COMP) \
    bool operator < (const T& ot) const { return COMP(ot) == -1; } \
    bool operator > (const T& ot) const { return COMP(ot) == 1; } \
    bool operator == (const T& ot) const { return COMP(ot) == 0; } \
    bool operator != (const T& ot) const { return COMP(ot) != 0; }
 
#define ADD_OPERATORS_OUT(T, COMP) \
    bool operator < (const T& a, const T& b) const { return COMP(a, b) == -1; } \
    bool operator > (const T& a, const T& b) const { return COMP(a, b) == 1; } \
    bool operator == (const T& a, const T&b) const { return COMP(a, b) == 0; } \
    bool operator != (const T& a, const T&b) const { return COMP(a, b) != 0; }
 
 
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
 
mt19937_64 mt_rand(chrono::system_clock::now().time_since_epoch().count());
 
template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }
 
const int maxn = (int) 1e6 + 100;
const int maxlog = 21;
const int base = 998'244'353;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const int pp = 41;
const int INF = (int) 2e9;
const ll llinf = (ll) 1e18;
 
 
const int MOD = 2520;
 
 
int f[2222][MOD + 100];
int used[2222][MOD + 100];
 
 
void init() {
  memset(f, -1, sizeof(f));
}
 
 
int k[2222];
int n;
vector<int> e[2222];
 
vector<pii> st;
 
void upd(int & a) {
  a = (a % MOD + MOD) % MOD;
  while (a < 0) a += MOD;
  while (a >= MOD) a -= MOD;
}
 
set<int> s;
int dfs(int v, int ost) {
 
  if (f[v][ost] != -1)
    return f[v][ost];
 
  used[v][ost] = 1;
  st.push_back({v, ost});
 
  int newOst = ost + k[v];
  upd(newOst);
  int to = e[v][newOst % sz(e[v])];
 
  if (used[to][newOst] == 1) {
    s.clear();
    pii kk = {to, newOst};
    for (int i = sz(st) - 1; i >= 0; i --) {
      s.insert(st[i].first);
      if (st[i] == kk) {
        break;
      }
    }
    st.clear();
    f[v][ost] = sz(s);
    used[v][ost] = 2;
    return f[v][ost];
  } else  {
    f[v][ost] = dfs(to, newOst);
    used[v][ost] = 2;
    return f[v][ost];
  }
}
 
int dfs2(int vv, int cc) {
 
  st.eb(vv, cc);
  int res = -1;
  while (!st.empty()) {
    int v, ost;
    tie(v, ost) = st.back();
 
    if (res != -1) {
      f[v][ost] = res;
    } else if (f[v][ost] != -1) {
      res = f[v][ost];
    } else {
      used[v][ost] = 1;
      int newOst = ost + k[v];
      upd(newOst);
      int to = e[v][newOst % sz(e[v])];
 
      if (used[to][newOst] == 1) {
        s.clear();
        pii kk = {to, newOst};
        for (int i = sz(st) - 1; i >= 0; i--) {
          s.insert(st[i].first);
          if (st[i] == kk) {
            break;
          }
        }
        res = sz(s);
        f[v][ost] = res;
      } else {
        st.eb(to, newOst);
        continue;
      }
    }
    used[v][ost] = 2;
    st.pop_back();
  }
  return res;
}
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  init();
  cin >> n;
  for (int i = 1; i <= n; i ++) {
    cin >> k[i];
    upd(k[i]);
  }
  for (int i = 1; i <= n; i ++) {
    int m;
    cin >> m;
    e[i].resize(m);
    for (int j = 0; j < m; j ++) {
      cin >> e[i][j];
    }
  }
 
  int q;
  cin >> q;
  while (q --) {
    int x, y;
    cin >> x >> y;
    upd(y);
    cout << dfs2(x, y)  << '\n';
  }
 
 
  return 0;
}