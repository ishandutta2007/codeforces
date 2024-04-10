#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(a),i##end=(b);i<=i##end;++i)
#define per(i,a,b) for(int i=(a),i##end=(b);i>=i##end;--i)

const int maxn=1e6+10;
int n,m;

int len,ecnt=1,h[maxn],deg[maxn];
struct edges{int nxt,to;}E[maxn];bool vis[maxn];
void addline(int u,int v){E[++ecnt]={h[u],v},h[u]=ecnt,deg[u]++;}

void dfs(int u){
  for(int&i=h[u];i;i=E[i].nxt)if(!vis[i]){
    int v=E[i].to;vis[i^1]=vis[i]=1,dfs(v);
    len++,printf("%d %d\n",len&1?u:v,len&1?v:u);
  }
}

int main(){
  cin>>n>>m;
  rep(i,1,m){
    int u,v;scanf("%d%d",&u,&v),addline(u,v),addline(v,u);
  }
  int lst=-1;
  rep(i,1,n)if(deg[i]&1){
    if(lst!=-1){
      addline(i,lst),addline(lst,i),lst=-1;
    }else{
      lst=i;
    }
  }
  if(ecnt/2&1)addline(1,1);
  printf("%d\n",ecnt/2);
  rep(i,1,n)dfs(i);
  return 0;
}