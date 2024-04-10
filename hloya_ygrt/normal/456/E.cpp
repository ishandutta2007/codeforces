// hloya template v21

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

//clock_t start_time = clock();
#define current_time fixed<<setprecision(6)<<(ld)(clock()-start_time)/CLOCKS_PER_SEC

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

#define ll long long
#define ld long double
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

const int inf = 2e9;
const long double eps = 1e-12;
const int maxn = 3e5 + 12, base = 1e9 + 7;
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

int p[maxn], d[maxn];
vector<int> g[maxn];

int fs(int v) {
    if (v == p[v])
        return v;
    return p[v] = fs(p[v]);
}

int used[maxn], timer;

pair<int, int> b(int v) {
    timer++;

    queue<pair<int, int> > q;
    pair<int, int> ans = mp(0, v);
    q.push(ans);
    used[v] = timer;

    while (!q.empty()) {
        pii cur = q.front();
        q.pop();
        ans = max(ans, cur);

        int v = cur.s, len = cur.f;
        for (int to:g[v])
            if (used[to] != timer) {
                used[to] = timer;
                q.push(mp(len + 1, to));
            }
    }
    return ans;
}

void calcD(int v) {
    int y = b(v).s;
    int ans = b(y).f;
    d[fs(v)] = ans;
}

int main() {
    int n, m, q;
    read(n, m, q);

    for (int i = 0; i < n; i++)
        p[i] = i;

    for (int i = 0; i < m; i++) {
        int u, v;
        read(u, v);
        u--, v--;

        g[u].pb(v);
        g[v].pb(u);

        if (rand() % 2)
            swap(u, v);
        p[fs(u)] = fs(v);
    }

    for (int i = 0; i < n; i++) {
        if (d[fs(i)] == 0)
            calcD(i);
    }

    for (int i = 0; i < q; i++) {
        int type;
        read(type);
        if (type == 2) {
            int u, v;
            read(u, v);
            u--, v--;

            u = fs(u), v = fs(v);
            if (u == v)
                continue;

            if (rand() % 2)
                swap(u, v);
            p[u] = v;
            d[v] = max(d[u], max(d[v], (d[u] + 1) / 2 + (d[v] + 1) / 2 + 1));
        } else {
            int v;
            read(v);
            v--;

            printf("%d\n", d[fs(v)]);
        }
    }
    return 0;
}