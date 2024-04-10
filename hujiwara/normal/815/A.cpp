#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  int g[100][100];
  bool X=1;
  if(n<m){
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	scanf("%d",g[j]+i);
      }
    }
    swap(n,m);
    X=0;
  }
  else{
    for(int i=0;i<n;i++){
      for(int j=0;j<m;j++){
	scanf("%d",g[i]+j);
      }
    }
  }
  int L[100];
  L[0]=0;
  bool F=0;
  for(int i=1;i<n;i++){
    L[i]=g[i][0]-g[0][0];
    for(int j=1;j<m;j++){
      if(L[i]!=g[i][j]-g[0][j]){
	F=1;
      }
    }
  }
  int G=0;
  for(int i=1;i<n;i++){
    G=min(G,L[i]);
  }
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(L[i]-G>g[i][j]){
	F=1;
      }
    }
  }
  if(F){
    puts("-1");
  }
  else{
    int N=0;
    for(int i=0;i<n;i++){
      N+=L[i]-G;
    }
    for(int j=0;j<m;j++){
      N+=g[0][j]+G;
    }
    printf("%d\n",N);
    for(int i=0;i<n;i++){
      for(int t=0;t<L[i]-G;t++){
	printf("%s %d\n",X?"row":"col",i+1);
      }
    }
    for(int j=0;j<m;j++){
      for(int t=0;t<g[0][j]+G;t++){
	printf("%s %d\n",X?"col":"row",j+1);
      }
    }
  }
  return 0;
}