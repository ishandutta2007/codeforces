#include <bits/stdc++.h>
using namespace std;

const int MN=100000;

void dfs(int i,int p,vector<int> *e,int *c,bool *b)
{
  b[i]=1;
  for(int x=0;x<e[i].size();x++){
    int j=e[i][x];
    if(j==p)continue;
    dfs(j,i,e,c,b);
    if(!b[j]||c[j]!=c[i]){
      b[i]=0;
    }
  }
}

int main()
{
  int n;
  scanf("%d",&n);
  static vector<int> e[MN];
  for(int i=0;i<n-1;i++){
    int u,v;
    scanf("%d%d",&u,&v);
    u--,v--;
    e[u].push_back(v);
    e[v].push_back(u);
  }
  static int c[MN];
  for(int i=0;i<n;i++){
    scanf("%d",c+i);
  }
  static bool b[MN];
  dfs(0,-1,e,c,b);
  int i=0,p=-1;
  while(1){
    int K=0,L=0,C=0,t=-1;
    for(int x=0;x<e[i].size();x++){
      int j=e[i][x];
      if(j==p)continue;
      C++;
      if(b[j]){
	K++;
      }
      if(b[j]&&c[j]==c[i]){
	L++;
      }
      else{
	t=j;
      }
    }
    if(K==C){
      puts("YES");
      printf("%d\n",i+1);
      break;
    }
    else if(L==C-1&&(p==-1||c[p]==c[i])){
      p=i;
      i=t;
    }
    else{
      puts("NO");
      break;
    }
  }
  return 0;
}