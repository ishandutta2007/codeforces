#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long double ld;
typedef long long ll;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int maxn = 400010;
const int mod = 1000000007;
const ll INF = 1ll * mod * mod;
const int mod2 = 998244353;
const double eps = 1e-9;
// Quick Functions------------------------------------------
ll qpow(ll b,int e){
    if( !e ) return 1;
    if( e & 1 ) return qpow(b,e-1) * b % mod;
    int pwur = qpow(b,e>>1);
    return pwur * pwur % mod;
}
mt19937_64 rnd(time(0));
ll rng (ll a, ll b){
    return uniform_int_distribution<ll>(a,b)(rnd);
}
// Problem starts here

struct DSU{
    vector<int> p;
    void init(int n) {
        p.clear();
        for (int i=0; i<n; i++)
            p.push_back(i);
    }
    int find_(int x)
    {
        return (p[x] == x) ? x : p[x] = find_(p[x]);
    }
    bool addEdge(int u,int v)
    {
        int a = find_(u);
        int b = find_(v);
        if (a == b)
            return false;
        else
        {
            p[b] = a;
            return true;
        }
    }
};

int l[maxn], r[maxn], cnt, lca[maxn][20], lv[maxn], invl[maxn];

void dfs(int u,int p,const vector<vector<int>> &G)
{
    for (int i=1; i<20; i++)
        lca[u][i] = lca[lca[u][i-1]][i-1];

    invl[cnt] = u;
    l[u] = r[u] = cnt ++;
    for (auto v : G[u])
    {
        if (v != p)
        {
            lv[v] = lv[u] + 1;
            lca[v][0] = u;
            dfs(v, u, G);
            r[u] = max(r[u], r[v]);
        }
    }
}

int LCA(int a,int b) {
    if (lv[a] < lv[b])
        swap(a, b);
    for (int i=19; i>=0; i--)
        if (lv[a] - (1<<i) >= lv[b])
            a = lca[a][i];
    if (a == b)
        return a;
    for (int i=19; i>=0; i--)
        if (lca[a][i] != lca[b][i])
            a = lca[a][i], b = lca[b][i];
    return lca[a][0];
}

int parentChild(int a,int b)
{
    for (int i=19; i>=0; i--)
        if (lv[a] - (1<<i) > lv[b])
            a = lca[a][i];
    return a;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc = 1;
    //cin >> tc;
    while (tc--)
    {
        int n, m;
        cin >> n >> m;

        DSU dsu;
        dsu.init(n);

        vector<vector<int>> G(n);

        vector<pair<pair<int, int>, int>> edges(m);
        for (int i=0; i<m; i++)
        {
            cin >> edges[i].f.f >> edges[i].f.s;
            edges[i].f.f --;
            edges[i].f.s --;

            edges[i].s = dsu.addEdge(edges[i].f.f, edges[i].f.s);

            if (edges[i].s)
            {
                G[edges[i].f.f].push_back(edges[i].f.s);
                G[edges[i].f.s].push_back(edges[i].f.f);
            }
        }

        dfs(0, 0, G);

        vector<int> psum(n+10);

        for (int i=0; i<m; i++)
        {
            if (!edges[i].s)
            {
                int u = edges[i].f.f;
                int v = edges[i].f.s;
                int lcaUV = LCA(u, v);

                if (lcaUV == u)
                    swap(u, v);

                if (lcaUV == v)
                {
                    int pch = parentChild(u, v);
                    psum[l[pch]] ++;
                    psum[r[pch]+1] --;

                    psum[l[u]] --;
                    psum[r[u]+1] ++;
                }
                else
                {
                    psum[l[0]] ++;
                    psum[r[0]+1] --;

                    psum[l[u]] --;
                    psum[r[u]+1] ++;

                    psum[l[v]] --;
                    psum[r[v]+1] ++;
                }
            }
        }

        string ans(n, 'p');
        for (int i=0; i<n; i++)
        {
            if (i)
                psum[i] += psum[i-1];
            if (psum[i] == 0)
                ans[invl[i]] = '1';
            else
                ans[invl[i]] = '0';
        }
        cout << ans << '\n';
    }

    return 0;
}