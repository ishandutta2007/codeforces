// hloya template v18

#include <bits/stdc++.h>
#include <valarray>
using namespace std;

bool dbg = 0;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
// #define ld long double
#define pii pair<int,int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("output.txt","w",stdout)
#define files files1;files2
#define fast_io ios_base::sync_with_stdio(0);cin.tie(0)

#define endl '\n'
#define ln(i,n) " \n"[(i) == (n) - 1]

void bad(string mes = "Impossible"){cout << mes;exit(0);}

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

void reads(string & s) {
    string ans = "";
    char c = endl;
    while (c == endl || c == ' ')
        c = getchar();
    while (c != endl && c != ' ' && c)
        ans += c, c = getchar();
    s = ans;
}

const int inf = 1e9;
const double eps = 1e-9;
const int maxn = 2e5 + 10, base = 1e9 + 7;
const ll llinf = 1e18 + 5;

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

int a[maxn];
multiset<ll> * sub[maxn];
ll delta[maxn];

int sz[maxn];
ll ans[maxn];
vector<pii> g[maxn];

void dfs(int v, int p) {
    sz[v] = 1;
    int mxSon = -1, mxSz = -1, l;
    
    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i].f, len = g[v][i].s;
        if (to == p)
            continue;
        dfs(to, v);
        if (sz[to] > mxSz) {
            mxSz = sz[to];
            mxSon = to;
            l = len;
        }
        sz[v] += sz[to];
    }

    if (mxSon == -1) {
        sub[v] = new multiset<ll>();
    } else {
        sub[v] = sub[mxSon];
        delta[v] = delta[mxSon] + (ll)l;
    }

    for (int i = 0; i < g[v].size(); i++) {
        int to = g[v][i].f, len = g[v][i].s;
        if (to != p && to != mxSon) {
            for (ll x:*sub[to]) {
                sub[v] -> insert(x - (ll)len - delta[to] + delta[v]);
            }
        }
    }
    while (sub[v] -> size() && (*(sub[v]->begin())) < delta[v])
        sub[v] -> erase(sub[v] -> begin());
    ans[v] = sub[v] -> size();
    sub[v] -> insert(delta[v] + a[v]);
}

void solve() {
    int n;
    read(n);
    for (int i = 0; i < n; i++) {
        read(a[i]);
        g[i].clear();
        delta[i] = 0;
    }

    for (int i = 1; i < n; i++) {
        int f, t, c;
        read(f, c);
        f--;
        t = i;

        g[f].pb(mp(t, c));
        g[t].pb(mp(f, c));
    }

    dfs(0, -1);

    for (int i = 0; i < n; i++)
        printf("%lld ", ans[i]);
    puts("");
}

int main() {
    //files1;
    // int t;
    // read(t);
    // while (t--)
    solve();
    return 0;
}