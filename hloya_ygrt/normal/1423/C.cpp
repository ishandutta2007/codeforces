#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Ofast")
 
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
 
bool dbg = 0;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
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
 
// #define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]
 
void bad(string mes = "NO"){cout << mes;exit(0);}
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
    228// chrono::system_clock::now().time_since_epoch().count()
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
const int maxn = (int)10004 + 3, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
const int mod = 1e9 + 7;

int binpow (int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = 1ll * res * a % base;
        a = 1ll * a * a % base;
        n >>= 1;
    }
    return res;
}


vector<int> g[maxn];
bool deleted[maxn];
 
int sizeOfTree[maxn];
 
void getTreeSizes(int v, int p = -1) {
    sizeOfTree[v] = 1;    
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != p && !deleted[to]) {
            getTreeSizes(to, v);
            sizeOfTree[v] += sizeOfTree[to];
        }
    }
}
 
int cntLayers = 0; 
// pair<int, int> layers[maxn][23]; // pair( layer, dist)
 
vector<pair<int, int>> ans;

void fixingWays(int v, int p, int& l, int depth = 0, bool f = false) {
    // int curSz = ++layers[v][0].f;
    // layers[v][curSz] = make_pair(l, depth);

    if (depth > 1 + f) {
      ans.push_back({l, v});
    }

    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (to != p && !deleted[to]) {
            fixingWays(to, v, l, depth + 1, f);
        }
    }
}
 
void buildingDfs(int start) {
    getTreeSizes(start);
 
    int centroid = -1;
    int N = sizeOfTree[start];
 
    int p = -1, v = start;
    while (centroid == -1) {
        pair<int, int> maxSon = mp(0, -1);
        for (int i = 0; i < g[v].size(); i++) {
            int to = g[v][i];
            if (!deleted[to] && to != p) {
                maxSon = max(maxSon, mp(sizeOfTree[to], to));
            }
        }
        if (maxSon.first > N / 2) {
            p = v;
            v = maxSon.second;
        } else centroid = v;
    }
 
    int curLayer = cntLayers++;

    if (N > 4) {
      bool f = true;
      for (auto to : g[centroid]) {
        if (!deleted[to]) {
          fixingWays(to, centroid, centroid, 1, f);
          f = false;
        }
      }
    }
 
    deleted[centroid] = 1;
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i];
        if (!deleted[to])
            buildingDfs(to);
    }
}
 
void buildCentroid(int& n) {
    cntLayers = 0;
    for (int i = 0; i < n; i++) {
        // layers[i][0] = mp(0, 0);
        deleted[i] = 0;
    }
    buildingDfs(0);
}
 
int main() {
  fast_io;
  // files1;

  // ofstream cout("input.txt");
  // cout << 10000 << ' ' << 3 << "\n";
  // for (int i = 0; i + 1 < 10000; i++) {
  //   cout << i + 1 << ' ' << i + 2 << "\n";
  // }

  // return 0;

  int n, k;
  cin >> n >> k;

  for (int i = 0; i + 1 < n; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    g[u].pb(v);
    g[v].pb(u);
  }

  buildCentroid(n);

  cout << ans.size() << "\n";
  for (auto [u, v] : ans) {
    cout << u + 1 << ' ' << v + 1 << "\n";
  }
  return 0;
}