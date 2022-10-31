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
const int maxn = (int)3e5 + 3, base = 998244353;
const ll llinf = 2e18 + 5;
const int mod = base;

int binpow (int a, int n) {
    int res = 1;
    while (n) {
        if (n & 1)
            res = 1ll * res * a % mod;
        a = 1ll * a * a % mod;
        n >>= 1;
    }
    return res;
}

int mndif[maxn][2];

vector<pii> g[maxn];

int dist[maxn][2][20];
int pw2[maxn];

int main() {
    srand(time(0));

    // files1;
    fast_io;

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].eb(v, 0);
        g[v].eb(u, 1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            mndif[i][j] = inf;
        }
    }
    mndif[0][0] = 0;

    set<pair<int, pii>> q;
    q.insert({0, {0, 0}});
    while (!q.empty()) {
        auto v = q.begin()->s;
        q.erase(q.begin());

        for (auto ed : g[v.f]) {
            int newlen = mndif[v.f][v.s] + (ed.s != v.s);
            if (newlen < mndif[ed.f][ed.s]) {
                q.erase({mndif[ed.f][ed.s], ed});
                mndif[ed.f][ed.s] = newlen;
                q.insert({newlen, ed});
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j <2 ; j++) {
    //         cout << mndif[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    set<pair<int, tuple<int, int, int>>> q2; // v, clr, +delta
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 20; k++) {
                dist[i][j][k] = inf;
            }
        }
    dist[0][0][0] = 0;
    q2.insert({0, {0, 0, 0}});

    while (!q2.empty()) {
        auto [v, clr, delta] = q2.begin()->s;
        q2.erase(q2.begin());

        for (auto ed : g[v]) {
            int realdif = mndif[v][clr] + delta + (clr != ed.s);
            int delta2 = realdif - mndif[ed.f][ed.s];
            if (delta2 < 0) {
                // what
                continue;
            }
            if (delta2 >= 20) {
                // useless
                continue;
            }
            if (dist[ed.f][ed.s][delta2] > dist[v][clr][delta] + 1) {
                q2.erase({dist[ed.f][ed.s][delta2], make_tuple(ed.f, ed.s, delta2)});
                dist[ed.f][ed.s][delta2] = dist[v][clr][delta] + 1;
                q2.insert({dist[ed.f][ed.s][delta2], {ed.f, ed.s, delta2}});
            }
        }
    }

    bool fnd = false;
    int ans = mod + 1;

    pw2[0] = 1;
    for (int j = 1; j < maxn; j++) {
        pw2[j] = pw2[j - 1] * 2ll % mod;
    }

    for (int j = 0; j < 2; j++) {
        for (int delta = 0; delta < 20; delta++) {
            int realdif = mndif[n - 1][j] + delta;
            if (realdif <= 20 && dist[n - 1][j][delta] != inf) {
                ans = min(ans, pw2[realdif] - 1 + dist[n-1][j][delta]);
                fnd = 1;
            }
        }
    }

    if (!fnd) {
        pair<int, int> min_found = {inf, inf};
        for (int delta = 0; delta < 20; delta++) {
            for (int j = 0; j < 2; j++) {
                int realdif = mndif[n - 1][j] + delta;
                if (dist[n - 1][j][delta] != inf) {
                    min_found = min(min_found, mp(realdif, dist[n - 1][j][delta]));
                }
            }
        }
        ans = ((pw2[min_found.f] + min_found.s - 1) % mod + mod) % mod;
    }

    cout << ans;
    return 0;
}