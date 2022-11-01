// hloya template v24

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

bool dbg = 0;

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
#define files2 freopen("mining.out","w",stdout)
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

template<typename T>
void amax(T& x, T y) {
    x = max(x, y);
}

template<typename T>
void amin(T& x, T y) {
    x = min(x, y);
}

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

const int inf = 2e9 + 20;
const long double eps = 1e-12;
const int maxn = 1e5 + 100, base = 1e9 + 7;
const ll llinf = 4e18 + 5;

template<typename T>
T binpow(T n, T s)
{
    if (s <= 0)
        return 1LL;
    if (s % 2 == 0){
        T b = binpow(n, s / 2);
        return ( 1LL * b * b ) % base;
    } else {
        return (1LL* binpow(n, s - 1) * n) % base;
    } 
}

vector<int> g[maxn];
ll a[maxn];

int b[maxn];
int p[maxn];

ll curans;
int cnt[maxn][2];

void dfs(int v, int pred = -1) {
    // cout << v << ' ' << b[v] << endl;
    for (int to:g[v])
        if (to != pred) {
            dfs(to, v);
            curans += 1ll * cnt[v][0] * cnt[to][1];
            curans += 1ll * cnt[v][1] * cnt[to][0];
            cnt[v][b[v]] += cnt[to][0];
            cnt[v][b[v] ^ 1] += cnt[to][1];
        }
    cnt[v][b[v]]++;
    // cout << v + 1 << ' ' << cnt[v][0] << ' ' << cnt[v][1] << endl;
    curans += cnt[v][1];
}

int n;
ll solve(ll byte) {
    // cnt1[0] = cnt1[1] = cnt2[0] = cnt2[1] = 0;
    curans = 0;

    for (int i = 0; i < n; i++) {
        cnt[i][0] = cnt[i][1] = 0;
        b[i] = 0;
        if (a[i] & (1ll << byte)) {
            b[i] = 1;
        }
    }
    // cout << endl;
    dfs(0);
    // exit(0);
    // cout << cnt1[0] << ' ' << cnt1[1] << endl;
    return curans;
}

int main() {
    // files1;
    read(n);

    for (int i = 0; i < n; i++) {
        read(a[i]);
    }

    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        read(u, v);
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    // cout << solve(0) << endl;
    // cout << solve(2);
    // return 0;
    ll ans = 0;
    for (int byte = 0; byte <= 20; byte++) {
        ll x = solve(byte);
        // cout << x << endl;
        ans += (ll)(1ll << byte) * x;
    }
    // ans /= 2;
    cout << ans;
    return 0;
}