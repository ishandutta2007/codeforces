#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
vector<int> g[mn];
bool vis[mn];
int d[mn];
bool gud;
ll t[2];
void dfs(int x,int p){
    vis[x]=1;
    t[d[x]&1]++;
    for(int y:g[x]){
        if(y==p)continue;
        if(vis[y]){
            if((d[x]&1)==(d[y]&1))gud=1;
        }
        else{
            d[y]=d[x]+1;
            dfs(y,x);
        }
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,i,a,b;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    if(m==0){
        printf("3 %lld",1LL*n*(n-1)*(n-2)/6);
        return 0;
    }
    bool a2=1;
    for(i=1;i<=n;i++)if(g[i].size()>1)a2=0;
    if(a2){
        printf("2 %lld",1LL*m*(n-2));
        return 0;
    }
    ll tot=0;
    for(i=1;i<=n;i++)if(!vis[i])t[0]=t[1]=0,dfs(i,0),tot+=t[0]*(t[0]-1)+t[1]*(t[1]-1);
    if(gud)printf("0 1");
    else printf("1 %lld",tot/2);
}