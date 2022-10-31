#pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

// hloya template v26

// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp> //  .
#include <ext/pb_ds/tree_policy.hpp> //   tree_order_statistics_node_update

using namespace __gnu_pbds;


typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

//bool dbg = 0;

clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC

#define f first
#define s second
#define mpzalupa make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define sz(v) ((int)(v).size())
#define sqr(x) ((x) * (x))


#define ull unsigned long long
#define ll long long
#define ld long double
#define pii pair<int,int>
#define umap unordered_map<int, int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

//#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "Impossible"){cout << mes;exit(0);}
void bad(int mes){cout << mes;exit(0);}

template<typename T>
string bin(T x, int st = 2){
  string ans = "";
  while (x > 0){
    ans += char('0' + x % st);
    x /= st;
  }
  reverse(ans.begin(), ans.end());
  return ans.empty() ? "0" : ans;
}

mt19937_64 mt_rand(
    chrono::system_clock::now().time_since_epoch().count()
);

template<typename T1, typename T2> inline bool upmax(T1& a, T2 b) { return (a < b ? (a = b, true) : false); }
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b) { return (b < a ? (a = b, true) : false); }

// inline int popcount(int x){
//     int count = 0;
//     __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
//     return count;
// }

template<typename T>
T input(){
  T ans = 0, m = 1;
  char c = ' ';

  while (!((c >= '0' && c <= '9') || c == '-')) {
    c = getchar();
  }

  if (c == '-')
    m = -1, c = getchar();
  while (c >= '0' && c <= '9'){
    ans = ans * 10 + (c - '0'), c = getchar();
  }
  return ans * m;
}

template<typename T>
T gcd (T a, T b) { while (b) { a %= b; swap (a, b); } return a; }

template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }

const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)2e5 + 1, base = 998244353;
const ll llinf = 2e18 + 5;

#define next asflkasjlf

vector<pair<ll, int>> que[maxn];
int to[maxn];

int inc[maxn];
vector<int> g[maxn];

int timer;
int tin[maxn], tout[maxn];
vector<int> lay[maxn];

int get(int w, int l, int r) {
  int ps = lower_bound(all(lay[w]), l) - lay[w].begin();
  return lay[w].size() - ps;
}

int ans[maxn];

void dfs(int v, int& mxd, int d = 0) {
  upmax(mxd, d);

  tin[v] = timer;
  lay[d].pb(timer);
  timer++;

  for (auto e : g[v]) {
    if (!inc[e]) {
      dfs(e, mxd, d + 1);
    }
  }

  tout[v] = timer;

  if (d != 0) {
    for (auto [m, id]: que[v]) {
      if (m + d >= maxn) {
        ans[id] = 0;
      } else {
        ans[id] = get(m + d, tin[v], tout[v]);
      }
    }
  }
}

vector<int> mda[maxn];
ordered_set c[maxn]; // ordered_set

void dbg(int valueadd) {
  cout << valueadd << "\n";
  for (int i = 0; i < 3; i++) {
    for (auto x : c[i]) {
      cout << x <<  ' ';
    }
    cout << std::endl;
  }
}

void solve(vector<int> fc) {
  int C = fc.size();
  int it = 0;

  for (int i = 0; i < C; i++) {
    c[i].clear();
  }

  int valueadd = 0;

  for (int v : fc) {
    int mxd = 0;
    dfs(v, mxd);
    mda[it].clear();

    for (int i = 0; i <= mxd; i++) {
      for (int j = 0; j < lay[i].size(); j++) {
        mda[it].pb(i);
      }
      lay[i].clear();
    }

    for (auto e : mda[it]) {
      c[((e - valueadd) % C + C) % C].insert(e - valueadd);
    }

    valueadd += 1;
    it++;
  }

//  cout << "HERE\n";
//  dbg(valueadd);

//  valueadd = -1;

  for (int it = 0; it < fc.size(); it++) {
    for (auto e : mda[it]) {
      int rem = ((e - valueadd) % C + C) % C;
      auto ITER = c[rem].lower_bound(e - it);
      ITER --;
//      cout << rem << ' ' << e - it << endl;
//      for (auto to : c[rem]) {
//        cout << to << ' ';
//      }
//      cout << endl;
      assert(ITER != c[rem].end() && *ITER == e - it);

      c[rem].erase(ITER);
      c[rem].insert(e - valueadd);
    }
//    exit(0);
//    cout << "MDA";
//    dbg(valueadd);

    for (auto [m, id]: que[fc[it]]) {
      int needmod = m % C;
      needmod = ((needmod - valueadd) % C + C) % C;
      ans[id] = c[needmod].order_of_key((int)min((ll)2 * maxn, m + 1 - valueadd));
    }
    valueadd += 1;
  }

//  exit(0);
}

vector<int> st;
int used[maxn];
int goes[maxn];

void dfs2(int v) {
  used[v] = 2;
  st.pb(v);

  int e = to[v];

  if (!used[e]) {
    dfs2(e);
    if (goes[v] == -1) {
      goes[v] = goes[e] + 1;
    }
  } else if (used[e] == 1) {
    goes[v] = goes[e] + 1;
  } else if (used[e] == 2) {
    // commit cycle
    int j = -1;
    for (int i = (int)st.size() - 1; i >= 0;i--) {
      if (st[i] == e) {
        j = i;
        break;
      }
    }
    assert(j != -1);
    int len = st.size() - j;

    vector<int> fc;
    for (int i = j; i < st.size(); i++) {
      goes[st[i]] = len;
      inc[st[i]] = 1;
      fc.pb(st[i]);
    }

    solve(fc);
  }

  used[v] = 1;
  st.pop_back();
}

int main()
{
  srand(time(0));
//  files1;
  fast_io;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> to[i];
    goes[i] = -1;
    to[i]--;
    g[to[i]].pb(i);
//    cout << i << ' ' << to[i] << endl;
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    ll m;
    int y;
    cin >> m >> y;

    y--;
    que[y].pb({m, i});
  }

  for (int i = 0; i < n; i++)
    if (!used[i]) {
      dfs2(i);
    }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << "\n";
  }
  return 0;
}