#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
mt19937 rng(423978);
typedef long long ll;
typedef pair<ll,ll>pll;
const int mn=5e5+10;
vector<pair<int,char>>g[mn];
int ans[mn];
vector<pii>*v[mn];
int vesh[1<<22];
int s[mn],lar[mn],adj[mn],shi[mn];
char c[mn];
void dfs1(int x,int p){
    s[x]=1;
    for(auto w:g[x])if(w.first!=p){
        dfs1(w.first,x);
        s[x]+=s[w.first];
        if(s[w.first]>s[lar[x]])lar[x]=w.first,c[x]=w.second;
    }
}
void dfs2(int x,int p,bool pst){
    for(auto w:g[x])if(w.first!=p&&w.first!=lar[x])dfs2(w.first,x,0),ans[x]=max(ans[x],ans[w.first]);
    if(lar[x])dfs2(lar[x],x,1),adj[x]=adj[lar[x]]^(1<<(c[x]-'a')),shi[x]=shi[lar[x]]+1,v[x]=v[lar[x]],ans[x]=max(ans[x],ans[lar[x]]);
    else v[x]=new vector<pii>();
    for(auto w:g[x])if(w.first!=p&&w.first!=lar[x]){
        int alt=adj[x]^adj[w.first]^(1<<(w.second-'a'));
        for(pii y:*v[w.first]){
            v[x]->push_back({y.first^alt,y.second+shi[w.first]+1-shi[x]});
            for(int i=0;i<22;i++){
                ans[x]=max(ans[x],vesh[y.first^alt^(1<<i)]+y.second+1+shi[x]+shi[w.first]);
            }
            ans[x]=max(ans[x],vesh[y.first^alt]+y.second+1+shi[x]+shi[w.first]);
        }
        for(pii y:*v[w.first])vesh[y.first^alt]=max(vesh[y.first^alt],y.second+1-shi[x]+shi[w.first]);
    }
    ans[x]=max(ans[x],vesh[adj[x]]+shi[x]);
    for(int i=0;i<22;i++)ans[x]=max(ans[x],vesh[adj[x]^(1<<i)]+shi[x]);
    v[x]->push_back({adj[x],-shi[x]});
    vesh[adj[x]]=max(vesh[adj[x]],-shi[x]);
    if(!pst)for(pii y:*v[x])vesh[y.first]=0xc0c0c0c0;
}
int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
   int n;
   cin>>n;
   for(int i=2;i<=n;i++){
       int x;
       string c;
       cin>>x>>c;
       g[x].push_back({i,c[0]});

   }
   memset(vesh,0xc0,sizeof(vesh));
   dfs1(1,0);
   dfs2(1,0,1);
   for(int i=1;i<=n;i++)printf("%d ",ans[i]);
}