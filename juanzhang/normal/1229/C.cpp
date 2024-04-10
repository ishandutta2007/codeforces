#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

typedef long long ll;
const int maxn=1e5+10;
int n,m,q,din[maxn],pos[maxn],deg[maxn],tmp[maxn];

struct edge{
  int u,v;
}G[maxn];

vector<int>gr[maxn];

int main(){
  cin>>n>>m;
  set<pair<int,int>>vis;
  rep(i,1,m){
    int u,v;scanf("%d%d",&u,&v);
    if(u>v)swap(u,v);
    G[i]={u,v},deg[u]++,deg[v]++,gr[u].push_back(v),din[u]++;
  }
  cin>>q;
  ll ans=0;
  rep(i,1,n)ans+=1ll*din[i]*(deg[i]-din[i]),pos[i]=i;
  cout<<ans<<endl;
  rep(_,1,q){
    int u;scanf("%d",&u);
    ans-=1ll*din[u]*(deg[u]-din[u]),din[u]=0;
    for(int v:gr[u]){
      ans+=deg[v]-2*(din[v]++)-1,gr[v].push_back(u);
    }
    pos[u]=n+_,gr[u].clear();
    printf("%lld\n",ans);
  }
  return 0;
}