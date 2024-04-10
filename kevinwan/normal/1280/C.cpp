#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const ll mod=1e9+7;
const int mn=3e5+10;
vector<int> g[mn],d[mn];
int rem[mn],s[mn];
ll ans;
void dfs1(int x,int p){
    int mo=1;
    int tot=1;
    s[x]=1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y==p)continue;
        dfs1(y,x);
        s[x]+=s[y];
        tot+=rem[y];
        mo=max(mo,rem[y]);
        ans+=1LL*rem[y]*d[x][i];
    }
    if(mo*2<=tot)rem[x]=tot%2;
    else rem[x]=mo-(tot-mo);
}
void dfs2(int x,int p,int hail){
    bool u=0;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y==p)continue;
        int hh=min(s[y],s[x]-s[y]);
        if(hh<s[y])hh=min(hh+hail,s[y]);
        ans+=1LL*hh*d[x][i];
        dfs2(y,x,hh);
    }
}
int main(){
    int tc;
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>tc;
    while(tc--){
        int k;
        cin>>k;
        for(int i=1;i<=2*k;i++)g[i].clear(),d[i].clear(),rem[i]=0,s[i]=0;
        ans=0;
        for(int i=0;i<2*k-1;i++){
            int a,b,c;
            cin>>a>>b>>c;
            g[a].push_back(b);
            g[b].push_back(a);
            d[a].push_back(c);
            d[b].push_back(c);
        }
        dfs1(1,0);
        printf("%lld ",ans);
        ans=0;
        dfs2(1,0,0);
        printf("%lld\n",ans);
    }
}