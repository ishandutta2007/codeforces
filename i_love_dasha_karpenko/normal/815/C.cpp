//#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
typedef long long ll;
typedef long double ld;
const int N = 5000+7;
const ll INF = 1E18+7;
ll dp[N][2][N];
int sz[N];
int n;
ll b;
pair<int,int> A[N];
vector<int> G[N];
bool mc(int a,int b){
    return sz[a]>sz[b];
}
void dfs(int v,int par){
    sz[v] = 1;
    dp[v][0][1] = A[v].first;
    dp[v][1][1] = 0;
    dp[v][1][0] = dp[v][0][0] = 0;
    for(int to:G[v]){
        if (to==par)
            continue;
        dfs(to,v);
    }
    sort(G[v].begin(),G[v].end(),mc);
    for(int to:G[v]){
        if (to==par)
            continue;

        for(int c = 0;c<2;++c)
        for(int w1 = sz[v];w1>=0;--w1){
            for(int w2 = 0;w2<=sz[to];++w2){
                if (dp[v][c][w1+w2]==-1)
                    dp[v][c][w1+w2] = INF;
                ll val = dp[to][c][w2];
                if (c==1)
                    val = min(val,dp[to][c^1][w2]);
                dp[v][c][w1+w2] = min(dp[v][c][w1+w2],dp[v][c][w1]+val);
            }
        }
        sz[v]+=sz[to];
    }
    for(int i = 1;i<=sz[v];++i){
        dp[v][1][i]+=A[v].first-A[v].second;
    }
}
void solve(){
    memset(dp,-1,sizeof(dp));
    cin>>n>>b;
    for(int i = 1;i<=n;++i){
        cin>>A[i].first>>A[i].second;
        if (i>1){
            int x;
            cin>>x;
            G[x].push_back(i);
        }
    }
    dfs(1,1);
    int res = 0;
    for(int w = 1;w<=n;++w){
        if (dp[1][1][w]<=b)
            res = w;
        if (dp[1][0][w]<=b)
            res = w;
    }
    cout<<res<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    int t;
    t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}