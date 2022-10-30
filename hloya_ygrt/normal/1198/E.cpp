// #pragma GCC target("sse,sse2,sse3,ssse3,sse4")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

// hloya template v27

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
  
void bad(string mes = "Impossible") {cout << mes;exit(0);}
void bad(int mes) {cout << mes;exit(0);}
  
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

inline int popcount(int x){
    int count = 0;
    __asm__ volatile("POPCNT %1, %0;":"=r"(count):"r"(x):);
    return count;
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

template<typename T>
T gcd (T a, T b) { while (b) { a %= b; swap (a, b); } return a; }
  
template<typename T> void read(T& a) { a = input<T>(); }
template<typename T> void read(T& a, T& b) { read(a), read(b); }
template<typename T> void read(T& a, T& b, T& c) { read(a, b), read(c); }
template<typename T> void read(T& a, T& b, T& c, T& d) { read(a, b), read(c, d); }
  
const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-12;
const int maxn = (int)1e5 + 450, base = 1e9 + 7;
const ll llinf = 2e18 + 5;

template<typename T>
struct Flow
{
    vector<vector<T> > f, c;
    vector<ll> d, lastNotUsed;
    const T inf = (T)1e18;
    
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
        for (T& i = lastNotUsed[v]; i < n; i++) {
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

int main() {
    // files1;
    fast_io;

    int n, m ;
    cin >> n >> m;

    if (!m)
        bad(0);

    vector<tuple<int,int,int,int> > e;
    vector<int> a, b;

    for (int i = 0; i < m; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        e.eb(x1,y1,x2,y2);
        a.pb(x1);
        a.pb(x2 + 1);
        b.pb(y1);
        b.pb(y2 + 1);
    }
    a.pb(1);
    a.pb(n + 1);
    b.pb(1);
    b.pb(n + 1);

    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    // for (auto e : a)
    //     cout << e << ' ';
    // return 0;
    sort(all(b));
    b.resize(unique(all(b)) - b.begin());

    int cnt;
    int cntl = a.size() - 1;
    Flow<ll> mf(cnt = (a.size() - 1 + b.size() - 1 + 2), 0, 1);

    for (auto& [x1, y1, x2, y2] : e) {
        for (int i = 0; i + 1 < a.size(); i++) {
            if (a[i] >= x1 && a[i + 1] - 1 <= x2) {
                for (int j = 0; j + 1 < b.size(); j++) {
                    if (b[j] >= y1 && b[j + 1] - 1 <= y2) {
                        mf.addEdge(i + 2, j + 2 + cntl, inf);
                    }
                }
            }
        }
    }

    for (int i = 0; i + 1 < a.size(); i++) {
        mf.addEdge(0, i + 2, a[i + 1] - a[i]);
    }
    for (int j = 0; j + 1 < b.size(); j++) {
        mf.addEdge(j + 2 + cntl, 1, b[j + 1] - b[j]);
    }

    cout << mf.dinic();
    return 0;
}