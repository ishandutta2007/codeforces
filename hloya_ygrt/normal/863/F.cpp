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
#define ld double
#define pii pair<int,int>
#define umap unordered_map<int, int>

#define files1 freopen("input.txt","r",stdin)
#define files2 freopen("data.out","w",stdout)
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

// const int inf = 1e9 + 20;
const short short_inf = 3e4 + 20;
const long double eps = 1e-15;
const int maxn = 1e5 + 12, base = (int)1e9 + 7;
const ll llinf = 1e18;

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

namespace flow {
const int inf = (1ll << 30) - 1;
const int maxn = (int) 1e5 + 10;

struct Edge{
    int from, to, cap, flow;
    ll cost;
    Edge(){
    
    }
    Edge(int _from, int _to, int _cap, ll _cost){
        from = _from;
        to = _to;
        cap = _cap;
        cost = _cost;
        flow = 0;
    }
};
vector<Edge>e;
vector<int> g[100100];
void add_edge(int from, int to, int cap, ll cost){
    g[from].pb(e.size());
    e.pb(Edge(from, to, cap, cost));
    g[to].pb(e.size());
    e.pb(Edge(to, from, 0, -cost));
}

ll phi[100100];
int par[100100];
ll d[100100];
ll INF = 1e15;
int S = 0, T = 100002;

bool djikstra(){
    for(int i = 0; i <= T; i++){
        d[i] = INF;
        par[i] = -1;
    }
    d[S] = 0;
    priority_queue<pair<ll, int> > pq;
    pq.push(mp(0, S));
    while(pq.size()>0){
        int v = pq.top().s;
        ll val = -pq.top().f;
        pq.pop();
        if(d[v] < val) continue;
        for(int i = 0; i < g[v].size(); i++){
            int ind = g[v][i];
            if(e[ind].cap == e[ind].flow) continue;
            int to = e[ind].to;
            assert(e[ind].cost - phi[to] + phi[v] >= 0);
            if(d[to] > d[v] + e[ind].cost - phi[to] + phi[v]){
                d[to] = d[v] + e[ind].cost - phi[to] + phi[v];
                par[to] = ind;
                pq.push(mp(-d[to], to));
            }
        }
    }
    return d[T] != INF;
}

pair<ll, ll> min_cost(){
    ll total_flow = 0, total_cost = 0;
    while(djikstra()){
        for(int i = 0; i <=T; i++){
            if(d[i] != INF) phi[i] += d[i];
            else phi[i] = 0;
        }
        int x = T;
        vector<int>edges;
        int flow=inf;
        while(par[x] != -1){
            int ind = par[x];
            edges.pb(ind);
            flow = min(flow, e[ind].cap - e[ind].flow);
            x = e[ind].from;
        }
        for(int i = 0; i < edges.size(); i++){
            int id = edges[i];
            total_cost += flow * 1ll * e[id].cost;
            e[id].flow+=flow;
            e[id^1].flow-=flow;
        }
        total_flow += flow;
    }
    return mp(total_flow, total_cost);
}
};

int l[maxn], r[maxn];

int main() {
    // n  / n  / 1  / 1 
    // 0..n-1/n..2n-1/2n/2n+1
    int n, q;
    fast_io;
    // files1;
    cin >> n >> q;

    flow::S = 2 * n;
    flow::T = 2 * n + 1;

    for (int i = 0; i < n; i++) {
        l[i] = 0, r[i] = n - 1;
    }
    for (int i = 0; i < q; i++) {
        int t, L, R, v;
        cin >> t >> L >> R >> v;
        L--, R--, v--;

        for (int j = L; j <= R; j++) {
            if (t == 1)
                amax(l[j], v);
            else
                amin(r[j], v);
        }
    }
    for (int i = 0; i < n; i++)
        flow::add_edge(flow::S, i, 1, 0);
    for (int i = n; i < 2 * n; i++) {
        for (int j = 0; j < n; j++) {
            int cur_cost = j * 2 + 1;
            flow::add_edge(i, flow::T, 1, cur_cost);
        }
    }
    for (int i = 0; i < n; i++) {
        if (l[i] > r[i])
            bad(-1);
        for (int j = l[i]; j <= r[i]; j++) {
            flow::add_edge(i, j + n, 1, 0);
        }
    }
    pair<ll, ll> res = flow::min_cost();
    if (res.f != n)
        bad(-1);
    cout << res.s << endl;
    return 0;
}