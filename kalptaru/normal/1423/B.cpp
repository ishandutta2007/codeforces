#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define int long long

#define all(X) (X).begin(), (X).end()
#define reset(X) memset(X, 0, sizeof(X))
#define mp(a, b) make_pair(a, b)
#define pb push_back
#define endl '\n'
#define fi first
#define se second

using namespace __gnu_pbds;
using namespace std;
const int mod = 1e9+7;
const int mod3 = 1e6 + 3;
//const int mod=998'244'353;
//const int mod=1e9+9;

const int MOD = mod;

const int INF=4e18+10;
// const int INF = 4e18 + 10;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define read(n) \
    int n;      \
cin >> n;
#define readv(x, n)   \
    vector<int> x(n); \
for (auto &i : x) \
cin >> i;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef pair<int, int> pii;

template <typename T1, typename T2>
void set_min(T1 &a, T2 b){
    a = min(a, (T1)b);
}
/* template <typename T1, typename T2> */
bool sort_by_sec(pair<int, int> a, pair<int,int> b)
{
    return make_pair(a.se, a.fi)<make_pair(b.se,b.fi);
}

template<typename T>
vector<int> coordinate_compress(vector<T > a)
{
    set<T> s;
    for(T elem:a)
        s.insert(elem);

    vector<T> temp;
    for(T elem:s)
        temp.push_back(elem);
    map<T, int> counter;
    for(int i=0;i<temp.size();i++)
        counter[temp[i]] = i;
    vector<int> to_return;
    for(T elem:a)
        to_return.push_back(counter[elem]);
    return to_return;

}

int multiply(int a, int b, int in_mod) { return (int)(1LL*a * b % in_mod );}
int mult_identity(int a) { return 1; }


vector<int >multiply(const vector<int>& a, const vector<int>& b,int mod);
vector<int> mult_identity(vector<int> a)
{
    return {1};
}



int power(int a, int b, int in_mod)
{

    int prod = mult_identity(a);
    int mult = a % in_mod;
    while (b != 0)
    {
        if (b % 2)
        {
            prod = multiply(prod, mult, in_mod);
        }
        mult = multiply(mult, mult, in_mod);
        b /= 2;
    }
    return prod;
}
int mod_inv(int q, int in_mod)
{

    return power(q, in_mod - 2, in_mod);
}

struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.emplace_back(v, u, cap);
        edges.emplace_back(u, v, 0);
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }

    long long flow() {
        long long f = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};
void solve( )
{
    int n,m;
    cin>>n>>m;
    vector<pair< int, pair< int, int>> > p;
    for(int i= 0;i<m;i++)
    {
        int u, v , d;
        cin>>u>>v>>d;
        p.pb({d, {u,v+n}});
    }
    sort(all(p));


    int lo = 1, hi = m;
    while(lo<hi-1)
    {
        int mid = (lo + hi)/2;

        Dinic d(2*n+2, 0, 2*n+1);
        for(int i= 1;i<=n;i++)
            d.add_edge(0, i, 1);
        for(int i=0;i<mid;i++)
            d.add_edge(p[i].se.fi, p[i].se.se, 1);

        for(int i= 1;i<=n;i++)
            d.add_edge(n+i, 2*n+1, 1);
        int mx_flow = d.flow();
        if( mx_flow==n)
        {
            hi = mid;
        }
        else
            lo = mid +1;

    }

    int mid = lo;


        Dinic d(2*n+2, 0, 2*n+1);
        for(int i= 1;i<=n;i++)
            d.add_edge(0, i, 1);
        for(int i=0;i<mid;i++)
            d.add_edge(p[i].se.fi, p[i].se.se, 1);

        for(int i= 1;i<=n;i++)
            d.add_edge(n+i, 2*n+1, 1);
    int mx_flow = d.flow();
    if( mx_flow==n)
    {
        hi = mid;
    }
    {
    mid = hi;

        Dinic d(2*n+2, 0, 2*n+1);
        for(int i= 1;i<=n;i++)
            d.add_edge(0, i, 1);
        for(int i=0;i<mid;i++)
            d.add_edge(p[i].se.fi, p[i].se.se, 1);

        for(int i= 1;i<=n;i++)
            d.add_edge(n+i, 2*n+1, 1);
    int mx_flow = d.flow();
    if( mx_flow==n)
    {
    cout<<p[hi-1].fi<<endl;

    }
    else
        cout<<-1<<endl;
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cerr.tie(NULL);
#ifndef ONLINE_JUDGE
    if (fopen("INPUT.txt", "r"))
    {
        freopen("INPUT.txt", "r", stdin);
        freopen("OUTPUT.txt", "w", stdout);
    }
#endif
    auto clk = clock();
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    // -------------------------------------Code starts here---------------------------------------------------------------------

    int t = 1;
    // cin >> t;

    for (int test = 1; test <= t; test++)
    {
        //cout<<"Case #"<<test<<": ";
        solve();
        //cout<<endl;
    }

    // -------------------------------------Code ends here------------------------------------------------------------------

    clk = clock() - clk;
    // cerr << fixed << setprecision(6) << "Time: " << ((long double)clk) / CLOCKS_PER_SEC << "\n";
    return 0;
}