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
 
#define endl '\n'
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
const int maxn = (int)150000 + 3, base = 998244353;
const ll llinf = 2e18 + 5;
 
int binpow(int a, int s) { 
    int res = 1;
    while (s) {
        if (s % 2) {
            res = 1ll * res * a % base;
        }
        a = 1ll * a * a % base;
        s /= 2;
    }
    return res;
}
 
vector<int> g[maxn];
const int buben = 100;
 
int timer;
int tin[maxn], tout[maxn];
int sz[maxn];
int p[maxn];
 
void dfs(int v, int par = -1) {
    timer++;
    tin[v] = timer - 1;
    sz[v] = 1;
    p[v] = par;
 
    for (auto to : g[v]) {
        if (to != par) {
            dfs(to, v);
            sz[v] += sz[to];
        }
    }
    tout[v] = timer - 1;
}
 
bool big[maxn];
int added[maxn];
 
int cmp[buben + 2][maxn];
int bigid[maxn];
 
void dfs2(int pos, int v, int par, int val) {
    cmp[pos][v] = val;
    for (auto to : g[v]) {
        if (to != par) {
            dfs2(pos, to, v, val);
        }
    }
}
 
int vald;
ll tree[maxn];
 
void add(int pos, ll val) {
    pos++;
    val = val * vald;
    while (pos < maxn) {
        tree[pos] += val;
        pos += pos & -pos;
    }   
}
 
ll get(int r) {
    r++;
    ll ans = 0;
    while (r > 0) {
        ans += tree[r];
        r -= r & -r;
    }
    return ans;
}
 
int main() {
    // files1;
    fast_io; 
    // cout << (sizeof(cmp)) / 1024. / 1024.;
    // return 0;   
 
    int n, q;
    cin >> n >> q;

    vector<int> ord(n);
    for (int i = 0; i < n; i++) {
        ord[i] = i;
    }
 
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
 
        g[u].pb(v);
        g[v].pb(u);
    }

    sort(all(ord), [](auto a, auto b){return g[a].size() > g[b].size();});
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[ord[i]] = i;
    }
 
    int inv = binpow(n, base - 2);
 
    dfs(0);
 
    int cntbig = 0;
    vector<int> bgs;
 
    for (int i = 0; i < n; i++) {
        if (pos[i] < buben) {
            big[i]  = true;
            bigid[i] = cntbig++;
            bgs.pb(i);
 
            for (auto to : g[i]) {
                if (to == p[i]) {
 
                } else {
                    dfs2(bigid[i], to, i, n - sz[to]);
                }
            }
 
            if (p[i] != -1) {
                dfs2(bigid[i], p[i], i, sz[i]);
            }
        }
    }
 
    for (int i = 0; i < q; i++) {
        int tp;
        cin >> tp;
 
        if (tp == 1) {
            int v, d;
            cin >> v >> d;
            v--;
 
            ::vald = d;
 
            added[v] += d;
            if (added[v] >= base)
                added[v] -= base;
 
            if (big[v]) {
            } else {
                for (auto to : g[v]) {
                    if (to != p[v]) {
                        add(tin[to], n - sz[to]);
                        add(tout[to] + 1, -(n - sz[to]));
                    }
                }
                add(0, sz[v]);
                add(tin[v], -sz[v]);
                add(tout[v] + 1, sz[v]);
                // add(n, -sz[v]);
            }
        } else {
            int v;
            cin >> v;
            v--;
 
            int val1 = get(tin[v]) % base;
            if (val1 < 0) {
                val1 += base;
            }
            int val2 = 1ll * added[v] * n % base;
            int val3 = 0;
 
            for (int b : bgs) {
                if (b != v) {
                    val3 += 1ll * cmp[bigid[b]][v] * added[b] % base;
                    if (val3 >= base)
                        val3 -= base;
                }
            }
 
            val1 += val2;
            if (val1 >= base)
                val1 -= base;
            val1 += val3;
 
            if (val1 >= base)
                val1 -= base;
 
            cout << 1ll * val1 * inv % base << "\n";
        }
    }
    return 0;
}