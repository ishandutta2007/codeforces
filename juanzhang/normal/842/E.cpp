#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=3e5+10;
int q,dep[maxn],fa[19][maxn];set<int>S1,S2;

int qlca(int u,int v){
  if(dep[u]<dep[v])swap(u,v);
  per(i,18,0)if(dep[fa[i][u]]>=dep[v])u=fa[i][u];
  if(u==v)return u;
  per(i,18,0)if(fa[i][u]!=fa[i][v])u=fa[i][u],v=fa[i][v];
  return fa[0][u];
}
int qdis(int u,int v){
  return dep[u]+dep[v]-dep[qlca(u,v)]*2;
}

int main(){
  cin>>q,dep[1]=1;int n=1,cur=0;S1.insert(1),S2.insert(1);
  while(q--){
    int f;scanf("%d",&f),dep[++n]=dep[f]+1,fa[0][n]=f;
    rep(i,1,18)fa[i][n]=fa[i-1][fa[i-1][n]];
    int d1=qdis(n,*S1.begin()),d2=qdis(n,*S2.begin());
    if(d1>cur){
      cur=d1;
      for(int x:S2)if(qdis(n,x)==d1)S1.insert(x);
      S2.clear(),S2.insert(n);
    }else if(d2>cur){
      cur=d2;
      for(int x:S1)if(qdis(n,x)==d2)S2.insert(x);
      S1.clear(),S1.insert(n);
    }else if(d1==cur)S2.insert(n);
    else if(d2==cur)S1.insert(n);
//    printf("S1 : ");for(int x:S1)printf("%d ",x);puts("");
//    printf("S2 : ");for(int x:S2)printf("%d ",x);puts("");
//    printf("#%d\n",cur);
    printf("%d\n",(int)(S1.size()+S2.size()));
  }
  return 0;
}