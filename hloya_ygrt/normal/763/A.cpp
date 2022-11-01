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

// clock_t start_time = clock();
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
const int maxn = 1e5 + 12, base = 1e9 + 7;
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
int c[maxn];
bool ok = 1;

int start;

void dfs(int v, int p = -1) {
    if (p == -1)
        start = v;
    if (p != -1 && p != start && c[v] != c[p]) {
        ok = 0;
    }
    for (int j = 0; j < g[v].size(); j++) {
        if (g[v][j] != p)
            dfs(g[v][j], v);
    }
}

int main() {
    int n;
    read(n);

    for (int i = 1; i < n; i++) {
        int u, v;
        read(u, v);
        u--, v--;

        g[u].pb(v);
        g[v].pb(u);
    }

    for (int i = 0; i < n; i++) {
        read(c[i]);
    }

    int v1 = -1, v2 = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < g[i].size(); j++)
            if (c[i] != c[g[i][j]]) {
                v1 = i;
                v2 = g[i][j];
            }
    }

    if (v1 == -1)
        return cout << "YES\n" << 1, 0;

    ok = 1;
    dfs(v1);
    if (ok)
        return cout << "YES\n" << v1 + 1, 0;

    ok = 1;
    dfs(v2);
    if (ok)
        return cout << "YES\n" << v2 + 1, 0;
    cout << "NO";

    return 0;
}