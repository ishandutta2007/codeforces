#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e6+10;
vector<int> g[mn];
bool vis[mn],fir,fail,kill[mn];
void dfs(int x,int r){
    bool flag=0;
    vis[x]=1;
    if(kill[x])flag=1;
    for(int y:g[x]){
        flag=1;
        if(!vis[y])dfs(y,r);
    }
    if(x!=r)return;
    if(flag){
        if(!fir)fail=1;
        else fir=0;
    }
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,i,a,b;
    cin>>n>>m;
    int slf=0;
    for(i=0;i<m;i++){
        cin>>a>>b;
        if(a!=b)g[a].push_back(b);
        if(a!=b)g[b].push_back(a);
        else slf++,kill[a]=1;
    }
    fir=1;
    for(i=1;i<=n;i++)if(!vis[i])dfs(i,i);
    if(fail){
        printf("0");
        return 0;
    }
    ll ans=0;
    for(i=1;i<=n;i++)ans+=1LL*g[i].size()*(g[i].size()-1);
    ans+=2LL*slf*(m-slf);
    ans+=1LL*slf*(slf-1);
    printf("%lld",ans/2);
}