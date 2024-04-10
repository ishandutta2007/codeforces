// hloya template v24

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

#define files1 freopen(".in","r",stdin)
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
struct edge {
    long long a, b, cap, flow;
} ;

long long n, s, t, d[maxn], ptr[maxn], q[maxn];
vector<edge> e;
vector<long long> g[maxn];

int addEdge(int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
    g[a].push_back((int)e.size());
    e.push_back(e1);
    g[b].push_back((int)e.size());
    e.push_back(e2);



//    cout << a << ' ' << b << ' ' << cap << endl;
    return g[a].back();
}

bool bfs() {
    int qh = 0, qt = 0;
    q[qt++] = s;
    for(int i = 0; i < n; i++) d[i] = -1;
    d[s] = 0;
    while(qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (int i = 0; i < g[v].size(); i++) {
            int id = g[v][i];
            int to = e[id].b;
            if(d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}

long long dfs(int v, long long flow) {
    if(!flow) return 0;
    if(v == t) return flow;
    for( ; ptr[v] < (int)g[v].size(); ptr[v]++) {
        int id = g[v][ptr[v]];
        int to = e[id].b;
        if(d[to] != d[v] + 1) continue;
        int pushed = dfs(to, min(flow, e[id].cap - e[id].flow));
        if(pushed) {
            e[id].flow += pushed;
            e[id ^ 1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}

long long dinic() {
    long long flow = 0;
    for ( ; ; ) {
        if(!bfs()) break;
        for(int i = 0; i < n; i++) ptr[i] = 0;
        while(long long pushed = dfs(s, inf)) flow += pushed;
    }
    return flow;
}


int x[maxn], y[maxn];
int X[maxn], Y[maxn];

int a, b;
bool can(int k, bool print) {
    for (int i = 0; i < n; i++) {
        g[i].clear();
        d[i] = 0;
        q[i] = 0;
        ptr[i] = 0;
    }
    e.clear();
    for (int i = 0; i < b; i++) {
        addEdge(s, i, 1);
    }
//    exit(0);
    for (int i = 0; i < a; i++) {
        addEdge(i + b, t, k);
    }
    for (int i = 0; i < b; i++) {
        X[i] = addEdge(i, x[i] + b, 1);
        Y[i] = addEdge(i, y[i] + b, 1);
    }
    int res = dinic();
    int ans = res == b;
    if (print) {
        assert(ans);
        cout << k << "\n";
        for (int i = 0; i < b; i++) {
            if (e[X[i]].flow)
                cout << x[i] + 1 << ' ' << y[i] + 1 << "\n";
            else
                cout << y[i] + 1 << ' ' << x[i] + 1 << "\n";
        }
        return ans;
    }
    return ans;
}

int main() {
    fast_io;
//    files1;
    cin >> a >> b;

    ::n = a + b + 2;
    ::s = a + b;
    ::t = a + b + 1;

    for (int i = 0; i < b; i++) {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
    }

//    cout << can(1, 0);
//    return 0;

    int l = 0, r = b;
    while (r - l > 0) {
        int mid = (l + r) >> 1;
        if (can(mid, 0))
            r = mid;
        else
            l = mid + 1;
    }

    can(l, 1);
    return 0;
}