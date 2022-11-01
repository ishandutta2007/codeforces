#include <bits/stdc++.h>
using namespace std;

const int MN=100000,MA=10,BS=17;

void mg(int *a,int *b,int *c)
{
  for(int i=0,j=0,k=0;k<MA;k++){
    if(j==MA||a[i]<=b[j]){
      c[k]=a[i];
      i++;
    }
    else{
      c[k]=b[j];
      j++;
    }
  }
}

int main()
{
  int n,m,q;
  scanf("%d%d%d",&n,&m,&q);
  static vector<int> e[MN];
  for(int i=0;i<n-1;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    u--,v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  static vector<int> P[MN];
  for(int i=0;i<m;i++){
    int c;
    scanf("%d",&c);
    c--;
    P[c].push_back(i);
  }
  static int pr[MN],dep[MN];
  for(int i=0;i<n;i++){
    dep[i]=-1;
  }
  stack<int> S;
  S.push(0);
  dep[0]=0;
  static int dfs[MN];
  int N=0;
  while(!S.empty()){
    int i=S.top();
    S.pop();
    dfs[N]=i;
    N++;
    for(int x=0;x<e[i].size();x++){
      int j=e[i][x];
      if(dep[j]!=-1)continue;
      pr[j]=i;
      dep[j]=dep[i]+1;
      S.push(j);
    }
  }
  static int Pa[MN][MA];
  for(int i=0;i<n;i++){
    sort(P[i].begin(),P[i].end());
    for(int t=0;t<MA;t++){
      Pa[i][t]=(t<P[i].size()?P[i][t]:m);
    }
  }
  static int db[MN][BS],dbp[MN][BS][MA];
  for(int ti=0;ti<n;ti++){
    int i=dfs[ti];
    db[i][0]=(i==0?0:pr[i]);
    for(int t=0;t<MA;t++){
      dbp[i][0][t]=(i==0?m:Pa[i][t]);
    }
    for(int t=1;t<BS;t++){
      db[i][t]=db[db[i][t-1]][t-1];
      mg(dbp[i][t-1],dbp[db[i][t-1]][t-1],dbp[i][t]);
    }
  }
  for(int T=0;T<q;T++){
    int u,v,a;
    scanf("%d%d%d",&u,&v,&a);
    u--,v--;
    if(dep[u]>dep[v]){
      swap(u,v);
    }
    int ret[2][MA];
    bool b=0;
    for(int t=0;t<MA;t++){
      ret[b][t]=m;
    }
    int t=BS-1;
    while(dep[v]>dep[u]){
      //printf("%d %d %d %d\n",u+1,v+1,dep[u],dep[v]);
      if(dep[db[v][t]]>=dep[u]){
	mg(ret[b],dbp[v][t],ret[!b]);
	b=!b;
	v=db[v][t];
      }
      else{
	t--;
      }
    }
    t=BS-1;
    while(u!=v){
      if(t==0||db[u][t]!=db[v][t]){
	mg(ret[b],dbp[u][t],ret[!b]);
	b=!b;
	u=db[u][t];
	mg(ret[b],dbp[v][t],ret[!b]);
	b=!b;
	v=db[v][t];
      }
      else{
	t--;
      }
    }
    mg(ret[b],Pa[u],ret[!b]);
    b=!b;
    int k=0;
    while(k<a&&ret[b][k]<m){
      k++;
    }
    printf("%d",k);
    for(int t=0;t<k;t++){
      printf(" %d",ret[b][t]+1);
    }
    putchar('\n');
  }
  return 0;
}