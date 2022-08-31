#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define pii pair<int,int>
#define pll pair<ll,ll>
#define vii vector<pii >
#define vll vector<ll >
#define cps CLOCKS_PER_SEC
#define eb emplace_back
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define print(s) cout<<#s<<" : ";for(auto i:(s))cout<<i<<" ";cout<<"\n";
#define slld(t) scanf("%lld",&(t))
#define sd(t) scanf("%d",&(t))
#define pd(t) printf("%d\n",(t))
#define plld(t) printf("%lld\n",(t))
#define endl "\n"

const int inf = 1e9 + 7;
const int N = 5005;
int dp[N][N], ind[N]; //prev.
int dp2[N][N];
vi vertices;
vi con[N];
vii con2[N];
bool vis[N];
void dfs(int s)
{
    vis[s] = 1;
    for(int u: con[s])
        if(!vis[u])
            dfs(u);
    vertices.eb(s);    
}
void DFS(int n)
{
    for(int i = n;i>=1;i--)
        if(!vis[i])
            dfs(i);   
    reverse(all(vertices)); 
    rep(i,0,n)
        ind[vertices[i]] = i;
}
int main()
{
    int n,m,T,u,v,t;
    sd(n),sd(m),sd(T);
    rep(i,0,m)
    {
        sd(u),sd(v),sd(t);
        con[u].eb(v);
        con2[v].eb(mp(u,t));
    }
    DFS(n);
    for(int i = 1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            dp2[i][j] = inf;
    dp2[1][1] = 0;
    for(int i = ind[1]+1;i<n;i++)
    {
        int node = vertices[i];
        for(int l = 2;l<=n;l++){
            for(pii p: con2[node])
            {
                int node2 = p.F;
                if(dp2[node2][l-1] + p.S < dp2[node][l])
                    dp2[node][l] = dp2[node2][l-1] + p.S,dp[node][l] = node2;
            }
        }
    }
    for(int k = n;k>=2;k--)
        if(dp2[n][k] <= T)
        {
            cout<<k<<endl;
            vector<int> vec;
            while(n!=1)
            {
                vec.eb(n);
                n = dp[n][k];
                k--;
            }
            vec.eb(1);
            for(int i = vec.size()-1;i>=0;i--)
                cout<<vec[i]<<" ";
            return 0;
        }
}