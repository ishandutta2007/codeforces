#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

int n,m;vector<int>E[1010];

int col[1010],par[1010],val[1010];
int find(int x){
  return par[x]==x?x:par[x]=find(par[x]);
}

bool dfs(int u,int c){
  col[u]=c;
  for(int v:E[u]){
    if(col[v]==-1){
      if(!dfs(v,c^1))return 0;
    }else if(col[v]==c)return 0;
  }
  return 1;
}

void chkmax(int&x,int y){
  if(x<y)x=y;
}

int main(){
  cin>>n>>m;
  rep(i,1,n)par[i]=i;
  rep(i,1,m){
    int u,v;scanf("%d%d",&u,&v),E[u].push_back(v),E[v].push_back(u),par[find(u)]=find(v);
  }
  memset(col,-1,sizeof col);
  rep(i,1,n)if(col[i]==-1){
    if(!dfs(i,0))return puts("-1"),0;
  }
  int ans=0;
  rep(i,1,n){
    static int dis[1010],Q[1010];
    memset(dis,-1,sizeof dis);
    int l=1,r=1;Q[1]=i,dis[i]=0;
    while(l<=r){
      int u=Q[l++];
      for(int v:E[u])if(dis[v]==-1)dis[v]=dis[u]+1,Q[++r]=v;
    }
    rep(j,1,r)chkmax(val[find(i)],dis[Q[j]]);
  }
  rep(i,1,n)if(find(i)==i)ans+=val[i];
  cout<<ans<<endl;
  return 0;
}