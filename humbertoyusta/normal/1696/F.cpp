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
const int maxn = 110;
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

bool eq[maxn][maxn][maxn];

void dfs(int u,const vector<vector<int>> &graph,vector<int> &dist)
{
    for (auto v : graph[u])
    {
        if (dist[v] == -1)
        {
            dist[v] = dist[u] + 1;
            dfs(v, graph, dist);
        }
    }
}

vector<pair<int, int>> try_(int firstChild,int n)
{
    vector<pair<int, int>> edges;
    vector<pair<int, int>> emptyVector;

    vector<int> p(n, -1);
    p[0] = firstChild;
    p[firstChild] = 0;
    edges.push_back({0, firstChild});

    queue<int> q;
    q.push(0);
    q.push(firstChild);

    while   (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v=0; v<n; v++)
        {
            if (p[v] != -1)
                continue;
            if (eq[p[u]][u][v])
            {
                p[v] = u;
                edges.push_back({u, v});
                q.push(v);
            }
        }
    }

    vector<vector<int>> graph(n);
    for (auto i : edges)
    {
        graph[i.f].push_back(i.s);
        graph[i.s].push_back(i.f);
    }

    vector<vector<int>> dist(n, vector<int>(n, -1));
    for (int i=0; i<n; i++)
    {
        dist[i][i] = 0;
        dfs(i, graph, dist[i]);
    }

    bool possible = (edges.size() == n - 1);

    for (int i=0; i<n; i++)
        for (int j=0; j<n; j++)
            if(dist[i][j] == -1)
                possible = false;



    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            for (int k=0; k<n; k++)
            {
                if (dist[i][k] == dist[k][j] && !eq[i][k][j]){
                    //db(i)db(k)db(j)
                    possible = false;
                }

                if (dist[i][k] != dist[k][j] && eq[i][k][j]){
                    //db("E")db(i)db(k)db(j)
                    possible = false;
                }
            }
        }
    }

    if (possible)
        return edges;
    else
        return emptyVector;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.setf(ios::fixed); cout.precision(12);
    srand(time(0));

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        for (int i=0; i<n; i++)
        {
            for (int j=i+1; j<n; j++)
            {
                string s;
                cin >> s;
                for (int k=0; k<n; k++)
                {
                    if (s[k] == '1')
                    {
                        //db("Eq")db(i)db(k)db(j)
                        eq[i][k][j] = 1;
                        eq[j][k][i] = 1;
                    }
                    else
                    {
                        eq[i][k][j] = 0;
                        eq[j][k][i] = 0;
                    }
                }
            }
        }

        vector<pair<int, int>> ans;
        for (int i=1; i<n; i++)
        {
            ans = try_(i, n);
            if (!ans.empty())
                break;
        }
        if (ans.empty())
        {
            cout << "No\n";
        }
        else
        {
            cout << "Yes\n";
            for (auto i : ans)
                cout << i.f + 1 << ' ' << i.s + 1 << '\n';
        }
    }


    return 0;
}