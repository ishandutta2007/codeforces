#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e3+10;
const ll mod=998244353;
vector<int> g[mn],d[mn];
ll ans=0;
string s;
bool vis[mn],v[mn];
bool fail=0;
void dfs(int x){
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        int l=d[x][i];
        if(vis[y])fail|=((v[x]^l)!=v[y]);
        else{
            v[y]=v[x]^l;
            dfs(y);
        }
    }
}
int main()
{
    int i,j;
    cin>>s;
    int n=s.size();
    for(i=1;i<n;i++){
        memset(vis,0,sizeof(vis));
        memset(v,0,sizeof(v));
        fail=0;
        for(j=0;j<mn;j++)g[j].clear(),d[j].clear();
        for(j=0;j<n;j++)g[j].push_back(n-j-1),d[j].push_back(0);
        for(j=i;j<n;j++)g[j+n].push_back(n+i-j-1+n),d[j+n].push_back(0);
        for(j=0;j<n;j++){
            if(s[j]=='?')continue;
            g[j].push_back(j+n);
            g[j+n].push_back(j);
            d[j].push_back(s[j]-'0');
            d[j+n].push_back(s[j]-'0');
        }
        vis[0]=v[0]=1;
        for(j=0;j<i;j++)vis[n+j]=1,v[n+j]=0;
        vis[n+i]=v[n+i]=1;
        ll t=1;
        dfs(0);
        for(j=0;j<i;j++)dfs(n+j);
        dfs(n+i);
        for(j=0;j<2*n;j++)if(!vis[j])dfs(j),t=t*2%mod;
        if(fail)t=0;
        ans=(ans+t)%mod;
    }
    printf("%lld",ans);
}