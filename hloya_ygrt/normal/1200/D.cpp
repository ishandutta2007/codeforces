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
 
const int maxn = (int) 5e5 + 100;
const int maxlog = 21;
const int base = 998'244'353;
const ld eps = (ld) 1e-9;
const ld PI = acos(-1.);
const int pp = 41;
const int INF = (int) 2e9;
const ll llinf = (ll) 1e18;
 
int fw[2222][2222];
 
int n, k;
 
int N = 2111;
 
int sum (int x, int y)
{
  int result = 0;
  for (int i = x; i >= 0; i = (i & (i+1)) - 1)
    for (int j = y; j >= 0; j = (j & (j+1)) - 1)
      result += fw[i][j];
  return result;
}
 
void inc (int x, int y, int delta)
{
  for (int i = x; i < N; i = (i | (i+1)))
    for (int j = y; j < N; j = (j | (j+1)))
      fw[i][j] += delta;
}
 
void upd(int x1, int y1, int x2, int y2) {
  inc(x1, y1, +1);
  inc(x1, y2 + 1, -1);
  inc(x2 + 1, y1, -1);
  inc(x2 + 1, y2 + 1, +1);
}
 
char a[2222][2222];
 
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> k;
  for (int i = 1; i <= n; i ++) {
    cin >> (a[i] + 1);
  }
 
  for (int i = 1; i <= n; i ++) {
 
    int le = n + 1;
    int ri = 1;
    for (int j = 1; j <= n; j ++) {
      if (a[i][j] == 'B') {
        upmin(le, j);
        upmax(ri, j);
      }
    }
 
    if (ri - le + 1 > k) continue;
    if (ri < le) {
      upd(1, 1, n, n);
      continue;
    }
 
    int upX = max(1, i - k + 1);
    int leY = max(1, ri - k + 1);
    int doX = i;
    int riY = le;
 
    upd(upX, leY, doX, riY);
  }
 
  for (int i = 1; i <= n; i ++) {
 
    int le = n + 1;
    int ri = 1;
    for (int j = 1; j <= n; j ++) {
      if (a[j][i] == 'B') {
        upmin(le, j);
        upmax(ri, j);
      }
    }
 
    if (ri - le + 1 > k) continue;
    if (ri < le) {
      upd(1, 1, n, n);
      continue;
    }
 
    int upX = max(1, i - k + 1);
    int leY = max(1, ri - k + 1);
    int doX = i;
    int riY = le;
 
    upd( leY,upX, riY,doX);
  }
  int ans = 0;
 
  for(int i = 1; i <= n - k + 1; i ++) {
    for (int j = 1; j <= n - k + 1; j ++) {
      upmax(ans, sum(i, j));
    }
  }        
  cout << ans << '\n';
 
  return 0;
}