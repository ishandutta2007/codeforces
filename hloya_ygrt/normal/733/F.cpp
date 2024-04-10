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

struct edge
{
    int a,b,it;
    ll cost;

    edge(int _a,int _b,ll _cost, int p)
    {
        a=_a;
        b=_b;
        cost=_cost;
        it = p;
    }

    bool operator < (const edge &i) const
    {
        return (this->cost) < (i.cost);
    }

};

ll tin[maxn],tout[maxn],lca[20][maxn],worst[20][maxn];
int timer;

vector<edge> edges,ns_edges, printMe;//non-sorted

int parent[maxn],_rank[maxn];

void make_set(int x)
{
    parent[x]=x;
    _rank[x]=0;
}

int find_set(int x)
{
    if (parent[x]==x)
        return x;
    else
        return parent[x]=find_set (parent[x] );
}

void union_set(int a,int b)
{
    a=find_set(a);
    b=find_set(b);

    if (a!=b)
    {
        if (_rank[a]<_rank[b])
            swap(a,b);

        parent[b]=a;

        if (_rank[a]==_rank[b])
            _rank[a]++;
    }
}

set<int> mstset;
vector<vector<pair<int,ll> > > mstg(maxn);
int n,m;

int find_root()
{
    int dist[maxn],used[maxn],pred[maxn];

    memset(used,0,sizeof(used));
    dist[0]=0;

    queue<pair<int,int> > q;
    q.push(mp(0,dist[0]));

    while(!q.empty())
    {
        int v=q.front().first,d=q.front().second;
        dist[v]=d;
        used[v]=1;

        for (int i=0;i<mstg[v].size();i++)
        {
            int to=mstg[v][i].first;//,len=mstg[v][i].second;
            if (!used[to])
            {
                used[to]=1;
          //      pred[to]=v;
                q.push(mp(to,d+1));
            }
        }
        q.pop();
    }

    int y=0;
    for (int i=0;i<n;i++)
    {
        if (dist[i]>dist[y])
            y=i;
    }

    memset(dist,0,sizeof(dist));
    memset(used,0,sizeof(used));

    q.push(mp(y,0));

    while(!q.empty())
    {
        int v=q.front().first,d=q.front().second;
        dist[v]=d;
        used[v]=1;

        for (int i=0;i<mstg[v].size();i++)
        {
            int to=mstg[v][i].first;//,len=mstg[v][i].second;
            if (!used[to])
            {
                used[to]=1;
                pred[to]=v;
                q.push(mp(to,d+1));
            }
        }
        q.pop();
    }

    int z=y;
    for (int i=0;i<n;i++)
        if (dist[z]<dist[i])
            z=i;

    int need=dist[z];
    need/=2;

    while (need)
    {
        z=pred[z];
        need--;
    }

    int root=z;
    return root;
}

void _fill(int v)
{
    for (int i=1;i<20;++i)
    {
        lca[i][v] = lca[i-1][lca[i-1][v]];
        worst[i][v]= max(worst[i-1][v],worst[i-1][lca[i-1][v]]);
    }
}

void dfs(int v,int par,ll got)
{
    tin[v]=++timer;
    worst[0][v]=got;
    lca[0][v]=par;

    _fill(v);

    for (int i=0;i<mstg[v].size();i++)
    {
        int to= mstg[v][i].first;
        ll len=mstg[v][i].second;

        if (to!=par)
        {
            dfs(to,v,len);
        }
    }
    tout[v]=++timer;
}

bool upper(int a,int b)
{
    return tin[a]<=tin[b]&&tout[a]>=tout[b];
}

int get_lca(int a,int b)
{
    if (upper(a,b))
        return a;

    if (upper(b,a))
        return b;

    for (int i=19;i>=0;i--)
    {
        if (!upper(lca[i][a],b))
            a=lca[i][a];
    }
    return lca[0][a];
}

ll go(int a,int b)
{
    ll ans=(long long) (-1)*llinf;

    if (a==b)
        return ans;
    else
    {

        for (int i=19;i>=0;i--)
        {
            if (!upper(lca[i][a],b))
            {
                ans=max(ans,worst[i][a]);
                a = lca[i][a];
            }
        }
    }
    return max(ans,worst[0][a]);
}

ll w[maxn], c[maxn];

int main()
{
    read(n, m);

    for (int i = 0; i < m; i++)
        read(w[i]);
    for (int i = 0; i < m; i++)
        read(c[i]);

    for (int i=0;i<m;i++)
    {
        int a,b;
        read(a, b);
        a--;
        b--;
        edges.pb(edge(a,b,w[i], i));
        ns_edges.pb(edge(a,b,w[i], i));
    }

    ll s;
    read(s);

    for (int i=0;i<n;i++)
        make_set(i);

    sort(edges.begin(),edges.end());

    ll mstcost=0;

    for (int i=0;i<m;i++)
    {
        int a=edges[i].a,b=edges[i].b;
        ll c=edges[i].cost;

        if (find_set(a)!=find_set(b))
        {
            union_set(a,b);
            mstset.insert(edges[i].it);
            mstcost+=c;
            mstg[a].push_back(make_pair(b,c));
            mstg[b].push_back(make_pair(a,c));

            printMe.pb(edges[i]);
        }
    }

    //int root=find_root();

    timer=0;
    dfs(0,0,(long long)(-1)*inf);

    pair<ll, int> res = mp(llinf, -1);

    for (int i=0;i<m;i++)
    {
        edge t=ns_edges[i];

        if (mstset.count(t.it)!=0) {
            res = min(res, mp(mstcost - s / c[i], i));
        }
        else
        {
            int lca1=get_lca(t.a,t.b);
            ll ans=mstcost+t.cost;
            ll worst1=max(go(t.a,lca1),go(t.b,lca1));
            res = min(res, mp(ans - worst1 - s / c[i], i));
        }
    }

    printf("%lld\n", res.f);
    for (int i = 0; i < n; i++)
        make_set(i);

    int kek = res.s;
    ns_edges[kek].cost -= s / c[kek];

    printMe.pb(ns_edges[res.s]);
    sort(all(printMe));
    assert(printMe.size() == n);

    for (int i = 0; i < n; i++) {
        int a = printMe[i].a, b = printMe[i].b,
            it = printMe[i].it;
        ll cost = printMe[i].cost;
        if (find_set(a) != find_set(b)) {
            union_set(a, b);
            printf("%d %lld\n", it + 1, cost);
        } 
    }
    return 0;
}