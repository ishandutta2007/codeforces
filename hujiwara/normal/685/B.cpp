#include<bits/stdc++.h>
using namespace std;

void dfs(int i,int *S,int db[300000][19],vector<vector<int> > &e)
{
  S[i]=1;
  db[i][0]=i;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    dfs(j,S,db,e);
    S[i]+=S[j];
    if(db[i][0]==i||S[db[i][0]]<S[j]){
      db[i][0]=j;
    }
  }
  for(int t=1;t<19;t++){
    db[i][t]=db[db[i][t-1]][t-1];
  }
}

int main()
{
  int n,q;
  scanf("%d%d",&n,&q);
  static int p[300000];
  vector<vector<int> > e(n);
  for(int i=1;i<n;i++){
    scanf("%d",p+i);
    p[i]--;
    e[p[i]].push_back(i);
  }
  static int S[300000],db[300000][19];
  dfs(0,S,db,e);
  for(int T=0;T<q;T++){
    int v;
    scanf("%d",&v);
    v--;
    int s=S[v],t=18;
    while(t>=0&&db[v][0]!=v){
      if(2*S[db[v][t]]>=s){
	v=db[v][t];
      }
      else{
	t--;
      }
    }
    printf("%d\n",v+1);
  }
  return 0;
}