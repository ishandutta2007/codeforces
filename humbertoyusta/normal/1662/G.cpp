/// Accepted Solution (Before the lecture)

/// Claim 1: In at least one optimal solution there is always a node such that
/// for all its children all the edges are directed towards the top or all edges
/// are directed towards the bottom

/// Claim 2: There is at least one solution where the node mentioned in Claim 1
/// is the centroid of the tree

#include<bits/stdc++.h>
using namespace std;
// Pragma
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline","03")
// Macros:
#define f first
#define s second
typedef long long ll;
typedef long double ld;
// debugging macros
#define db(x) cerr << #x << ": " << (x) << '\n';
#define db_v(x) cerr << #x << ": ["; for( auto i : (x) ) cerr << i << ", "; cerr << "]\n";
#define db_p(x) cerr << #x << ": " << (x).first << " " << (x).second << '\n';
// Constraints:
const int MOD = 1000000007;
const ll INF = 1ll * 1000000007 * 1000000007;

vector<vector<int>> adj;
vector<int> lvl, par, subt;
vector<ll> sumDist;
vector<int> items;

void dfs(int u)
{
    subt[u] = 1;
    sumDist[1] += lvl[u];

    for (auto v : adj[u])
    {
        if (v != par[u])
        {
            par[v] = u;

            lvl[v] = lvl[u] + 1;

            dfs(v);

            subt[u] += subt[v];
        }
    }
}

void dfs2(int u,int n)
{
    for (auto v : adj[u])
    {
        if (v != par[u])
        {
            sumDist[v] = sumDist[u] + (n - subt[v]) - subt[v];

            dfs2(v, n);
        }
    }
}

int find_centroid(int u,int n)
{
    for (auto v : adj[u])
    {
        if (v != par[u] && subt[v] > n/2)
        {
            return find_centroid(v, n);
        }
    }
    return u;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    ///cout.setf(ios::fixed); cout.precision(10);

    //freopen("a.in","r",stdin);
    //freopen("a.in","w",stdout);

    int n;
    cin >> n;

    adj.resize(n+1);
    lvl.resize(n+1);
    par.resize(n+1);
    subt.resize(n+1);
    sumDist.resize(n+1);

    for (int i=1; i<n; i++)
    {
        int u, v;
        u = i + 1;
        cin >> v;
        //v --; u --;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    /// preprocess the tree
    dfs(1);

    dfs2(1, n);

    /// Find the centroid
    int centroid = find_centroid(1, n);

    vector<int> occ(n+1);

    /// The items for the knapsack are the subtree's sizes of the children's subtrees
    for (auto v : adj[centroid])
        if (v != par[centroid])
            occ[subt[v]] ++;
    occ[n-subt[centroid]] ++;

    vector<int> items;
    /// Making batches of equal items to process them fast
    for(int i=1; i<=n; i++)
    {
        while (occ[i] >= 3)
        {
            occ[i] -= 2;
            occ[2*i] += 1;
        }
        for (int j=0; j<occ[i]; j++)
            items.push_back(i);
    }

    bitset<1000001> dp;
    dp[0] = 1;
    /// Since the weights sum up to n, there are O(sqrt(n)) batches of equal items
    for (auto item : items)
    {
        /// process each batch of equal items in O(n)
        dp |= (dp << item);
    }

    ll ans = 0;
    for (int i=0; i<n; i++)
    {
        if (dp[i])
        {
            //db(centroid)db(i)
            ans = max(ans, sumDist[centroid] + n + 1ll * (i+1) * (n-i) - 1);
        }
    }
    cout << ans - (n-1) << '\n';

    return 0;
}