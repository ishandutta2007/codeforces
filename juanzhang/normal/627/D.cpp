#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

#define mem(a) memset((a),0,sizeof(a))

const int maxn=2e5+10;
int n,k,as,A[maxn],can[maxn],vis[maxn],all[maxn],ano[maxn],chk[maxn],ano2[maxn],F[maxn],G[maxn];vector<int>E[maxn];

void dfs1(int u,int f){
  vis[u]=1,all[u]=1,F[u]=1,ano[u]=0,chk[u]=0,ano2[u]=0;
  for(int v:E[u])if(v!=f){
    if(!can[v])all[u]=0;
    else{
      dfs1(v,u);
      if(all[v])F[u]+=F[v];
      else{
        if(ano[u]<F[v])ano2[u]=ano[u],ano[u]=F[v],chk[u]=v;
        else if(ano2[u]<F[v])ano2[u]=F[v];
        all[u]=0;
      }
    }
  }
  F[u]+=ano[u],as=max(as,F[u]);
//  printf("(%d %d)\n",u,F[u]);
}
void dfs2(int u,int f,int flg){
  int ct=0,su=0,zzh=0;
  for(int v:E[u])if(v!=f){
    if(!can[v]){
      zzh++;
      continue;
    }
    if(all[v]){
      su+=F[v];
    }else{
      ct++;
    }
  }
//  printf("(%d) (%d) (%d %d)\n",u,ano2[u],flg,G[u]);
  as=max(as,G[u]+1+su);
  as=max(as,(flg?G[u]:0)+F[u]);
  for(int v:E[u])if(v!=f&&can[v]){
    G[v]=0;
    G[v]=max(G[u]+1+su-(all[v]?F[v]:0),su-(all[v]?F[v]:0)+1+(flg?G[u]:0)+(chk[u]==v?ano2[u]:ano[u]));
    dfs2(v,u,flg&&(!ct||(ct==1&&!all[v]))&&!zzh);
  }
}

int main(){
  cin>>n>>k;rep(i,1,n)scanf("%d",A+i);rep(i,2,n){
    int u,v;scanf("%d%d",&u,&v);E[u].push_back(v),E[v].push_back(u);
  }
  int l=1,r=1e6;
  while(l<r){
    mem(vis),mem(can),mem(all),mem(ano),mem(chk),mem(F),mem(G),mem(ano2);
    int mid=(l+r+1)/2,res=0;
    rep(i,1,n)can[i]=A[i]>=mid,vis[i]=0;
    rep(i,1,n)if(!vis[i]&&can[i]){
      as=0,dfs1(i,0),G[i]=0,dfs2(i,0,1),res=max(res,as);
    }
    res>=k?l=mid:r=mid-1;
  }
  cout<<r<<endl;
  return 0;
}