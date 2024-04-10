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
const int N = 505+10;
bool con[N][N];
vi adj[N];
bool vis[N];
int col[N];
int comp = 0;
bool color(int node)
{
    comp++;
    queue<int> q;
    col[node] = 1;
    q.push(node);
    vis[node] = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int v:adj[u]){
            if(col[v] != 0 && col[u] != 4 - col[v])
                return 0;
            if(!vis[v])
            {
                vis[v] = 1;
                col[v] = 4-col[u];
                q.push(v);
            }
        }
    }
    return 1;
}
bool is_poss(int n)
{
    for(int i = 1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(adj[i].empty()){
                col[i] = 2;
                continue;
            }
            if(!color(i))
                return 0;
        }
    }
    if(comp > 1)
        return 0;
    return 1;
}
int main()
{
    int n,m,u,v;
    sd(n),sd(m);
    rep(i,1,m+1)
    {
        sd(u),sd(v);
        con[u][v] = con[v][u] = 1;
    }

    rep(i,1,n+1)
    rep(j,1,n+1)
    if(i!=j && !con[i][j])
        adj[i].eb(j);
    bool b = is_poss(n);
    string s;
    if(b)
    {
        for(int i = 1;i<=n;i++)
            s+= (char)(96+col[i]);
    }
    for(int i = 1;i<=n;i++)
        for(int j = i+1;j<=n;j++){
            if(!(con[i][j] ^ (abs((s[i-1]-'a')-(s[j-1]-'a')) == 2)))
                b = false;
        }
    cout<< (b?"Yes\n":"No\n");
    if(b)    
    cout<<s;
}