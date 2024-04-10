// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <list>
 
// hloya template v25
  
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
#include <valarray>
using namespace std;
  
clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC
  
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
  
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
  
template<typename T>
void upmax(T& x, T y) {
    x = max(x, y);
}
  
template<typename T>
void upmin(T& x, T y) {
    x = min(x, y);
}
 
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
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-6;
const int maxn = (int)2e5 + 12;//, base = 1e9 + 7;
const ll llinf = 2e18 + 5;
const double PI = acos(-1.0);
 
const int mod = 1e9 + 7;
const int mod2 = 1e9 + 9;
  
template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % mod;
    } else {
        return (1LL* binpow(n, s - 1) * n) % mod;
    }
}


vector<int> tmp;
int used[200000];
vector<vector<int>> kek;

vector<int> st;
vector<pii> g[maxn];
map<pii, int> sot;

int getEdge(int u, int v) {
    return sot[minmax(u, v)];
}

void dfs(int v, int p = -1) {
    used[v] = 2;
    st.pb(v);

    for (auto [to, w] : g[v]) {
        if (to == p) continue;

        if (used[to] == 2) {
            tmp.clear();
            for (int i = st.size() - 1; st[i] != to; i--) {
                tmp.pb(getEdge(st[i], st[i - 1]));
            }
            tmp.pb(w);
            kek.pb(tmp);
        } else if (used[to] == 0) {
            dfs(to, v);
        }
    }

    st.pop_back();
    used[v] = 1;
}

int poly[45][140000];
int poly2[45][140000];

void transform(int id, int from, int to)
{ 
    if(to - from == 1) 
        return;
    int mid = from + (to - from) / 2; 
    transform(id, from, mid); 
    transform(id, mid, to); 
    for(int i = 0; i < mid - from; i++) 
    {
        int a = poly[id][from + i];
        int b = poly[id][mid + i];
        poly[id][from + i] = (a + b) % mod;
        poly[id][mid + i] = ((a - b) % mod + mod) % mod;

        a = poly2[id][from + i];
        b = poly2[id][mid + i];
        poly2[id][from + i] = (a + b) % mod2;
        poly2[id][mid + i] = ((a - b) % mod2 + mod2) % mod2;
    }
}

int inv(int x) {
    return binpow(x, mod - 2);
}

int main() {
    fast_io;
    // files1;

    int n, m;
    cin >> n >> m;  

    int x = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].pb({v, w});
        g[v].pb({u, w});
        sot[minmax(u,v)] = w;
        x ^= w;
    }

    for (int i = 0; i < n; i++) if (!used[i]) dfs(i);

    assert(kek.size() < 43);

    if (kek.size() == 0) {
        cout << x << ' ' << 1 << endl;
        return 0;
    }

    for (int i = 0; i < kek.size(); i++) {
        for (int j : kek[i]) {
            poly[i][j]++;
            poly2[i][j]++;
        }
        transform(i, 0, (1 << 17));

        for (int j = 0; j < (1 << 17); j++) {
            if (i == 0) poly[43][j] = poly[i][j];
            else {
                poly[43][j] = 1ll * poly[43][j] * poly[i][j] % mod;
            }
        }
        for (int j = 0; j < (1 << 17); j++) {
            if (i == 0) poly2[43][j] = poly2[i][j];
            else {
                poly2[43][j] = 1ll * poly2[43][j] * poly2[i][j] % mod2;
            }
        }
    }

    transform(43, 0, (1 << 17));
    int re = mod, mda;

    for (int i = 0; i < (1 << 17); i++) {
        if (poly[43][i] || poly2[43][i]) {
            poly[43][i] = 1ll * poly[43][i] * inv(1 << 17) % mod;

            if ((i ^ x) < re) {
                re = i ^ x;
                mda = poly[43][i];
            }
        }
    }
    cout << re << ' ' << mda;
    return 0;
}