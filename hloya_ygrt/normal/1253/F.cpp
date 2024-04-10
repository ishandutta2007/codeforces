// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
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
const int maxn = (int)1e6 + 3, base = 998244353;
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

ll dist[maxn];
int col[maxn];
vector<pair<int, ll>> g[maxn];

int par[maxn];
 
int gp(int v) {
    if (v == par[v]) {
        return v;
    }
    return par[v] = gp(par[v]);
}
 
void conn(int a, int b) {
    a = gp(a);
    b = gp(b);
    if (a != b) {
        if (rand() % 2) {
            swap(a, b);
        }
        par[a] = b;
    }
}
 
vector<int> ask[maxn];

int main() {
    // files1;
    fast_io;

    int n, m, k, que;
    cin >> n >> m >> k >> que;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        g[u].eb(v, w);
        g[v].eb(u, w);
    }

    for (int i = 0; i < n; i++) {
        dist[i] = llinf;
        col[i] = -1;
    }

    set<pair<ll, int>> q;
    for (int i = 0; i < k; i++) {
        dist[i] = 0;
        col[i] = i;
        q.insert({dist[i], i});
    }
    while (!q.empty()) {
        int v = q.begin()->s;
        q.erase(q.begin());

        for (auto ed : g[v]) {
            int to = ed.f;
            int w = ed.s;

            if (dist[to] > dist[v] + w) {
                q.erase(mp(dist[to], to));
                dist[to] = dist[v] + w;
                col[to] = col[v];
                q.insert(mp(dist[to], to));
            }
        }
    }

    for (int i = 0; i < n; i++) {
        par[i] = i;
        assert(col[i] < k && col[i] >= 0);
    }

    vector<tuple<ll, int, int>> edg;
    for (int i = 0; i < n; i++)
        for (auto ed : g[i]) {
            int to = ed.f, w = ed.s;
            if (col[i] != col[to]) {
                edg.eb(dist[i] + dist[to] + w, col[i], col[to]);
            }
        }

    sort(all(edg));

    vector<int> l(que), r(que);
    vector<int> a(que), b(que);
    for (int i = 0; i < que; i++) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        l[i] = 0, r[i] = (int)edg.size() - 1;
    }

    for (int iter = 0; ; iter++) {
        for (int i = 0; i < edg.size(); i++) {
            ask[i].clear();
        }
        for (int i = 0; i < k; i++) {
            par[i] = i;
        }
        bool have = false;
        for (int j = 0; j < que; j++) {
            if (l[j] == r[j]) {
                continue;
            }
            have = true;
            int mid = (l[j] + r[j]) / 2;
            ask[mid].pb(j);
        }
        if (!have) {
            break;
        }
        for (int i = 0; i < edg.size(); i++) {
            ll  w;
            int u, v;

            tie(w, u, v) = edg[i];
            conn(u, v);

            for (int id : ask[i]) {
                if (gp(a[id]) == gp(b[id])) {
                    r[id] = i;
                } else {
                    l[id] = i + 1;
                }
            }
        }
    }

    for (int i = 0; i < que; i++) {
        assert(l[i] == r[i]);
        ll w = get<0>(edg[l[i]]);
        cout << w << "\n";
    }
    return 0;
}