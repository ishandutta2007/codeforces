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
const int maxn = 2e2 + 12, base = 1e9 + 7;
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

template<typename T>
struct Flow
{
    vector<vector<T> > f, c;
    vector<int> d, lastNotUsed;
    const T inf = (T)1e9;
    
    int s, t, n;

    Flow() {}
    Flow(int _n, int s, int t):s(s), t(t) {
        n = _n;
        c = f = vector<vector<T> >(n, vector<T>(n, 0));
    }

    void addEdge(int u, int v, T e) {
        // cout << u << ' ' << v << ' ' << e << endl;
        c[u][v] += e;
    }

    bool bfs() {
        queue<int> q;
        d = vector<T>(n, -1);
        q.push(s);
        d[s] = 0;

        while (!q.empty()) {
            int v = q.front();
            q.pop();

            for (int i = 0; i < n; i++) {
                if (d[i] == -1 && f[v][i] < c[v][i]) {
                    d[i] = d[v] + 1;
                    q.push(i);
                }
            }
        }

        return d[t] != -1;
    }

    T dfs(int v, T flow) {
        if (v == t || flow == 0) // if double fix
            return flow;
        for (int& i = lastNotUsed[v]; i < n; i++) {
            if (d[i] == d[v] + 1) {
                T pushed = dfs(i, min(flow, c[v][i] - f[v][i]));
                if (pushed) {
                    f[v][i] += pushed;
                    f[i][v] -= pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    T dinic() {
        T flow = 0;
        while (1) {
            if (!bfs())
                break;
            lastNotUsed = vector<T>(n, 0);
            while (T curFlow = dfs(s, inf))
                flow += curFlow;
        }

        return flow;
    }
};

int a[maxn], b[maxn];

int main() {
    int n, m;
    read(n, m);

    Flow<int> flow(2 * n + 2, 2 * n, 2 * n + 1);

    int s = 0;
    for (int i = 0; i < n; i++) {
        read(a[i]);
        s += a[i];
        flow.addEdge(flow.s, i, a[i]);
    }

    int sum = 0;
    for (int i = 0; i < n; i++) {
        read(b[i]);
        flow.addEdge(i + n, flow.t, b[i]);
        sum += b[i];
        flow.addEdge(i, i + n, inf);
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        read(u, v);
        u--, v--;
        flow.addEdge(u, v + n, inf);
        flow.addEdge(v, u + n, inf);
    }
    // return 0;

    if (s != sum)
        bad("NO");
    int k = flow.dinic();
    if (k != sum)
        bad("NO");

    cout << "YES\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            int cur = flow.f[i][j + n];
            cout << cur << ln(j, n);
        }
    return 0;
}