#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mn=2e5+10;
ll c[mn],s[mn],sc[mn],tot;
vector<int> g[mn];
int n;
void dfs(int x,int p){
    s[x]=c[x];
    for(int y:g[x]){
        if(y==p)continue;
        dfs(y,x);
        s[x]+=s[y];
    }
}
void dfs2(int x,int p){
    for(int y:g[x]){
        if(y==p)continue;
        sc[y]=sc[x]+tot-2*s[y];
        dfs2(y,x);
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int i,a,b;
    cin>>n;
    for(i=1;i<=n;i++)cin>>c[i],tot+=c[i];
    for(i=0;i<n-1;i++){
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(1,0);
    for(i=2;i<=n;i++)sc[1]+=s[i];
    dfs2(1,0);
    ll ans=0;
    for(i=1;i<=n;i++)ans=max(ans,sc[i]);
    printf("%lld",ans);
}