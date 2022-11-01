#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  static int d[400][400]={0};
  for(int i=0;i<m;i++){
    int v,u;
    scanf("%d%d",&v,&u);
    v--,u--;
    d[u][v]=d[v][u]=1;
  }
  queue<pair<int,int> > Q[2];
  static int D[2][400][400];
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      D[0][i][j]=(i==0&&j==0?0:-1);
      D[1][i][j]=-1;
    }
  }
  bool b=0;
  Q[b].push(make_pair(0,0));
  while(!Q[b].empty()||!Q[!b].empty()){
    if(Q[b].empty()){
      b=!b;
    }
    int i=Q[b].front().first,j=Q[b].front().second;
    Q[b].pop();
    //printf("%d %d %d\n",b,i,j);
    if(!b){
      if(i<n-1){
	for(int k=0;k<n;k++){
	  if(d[i][k]==0&&D[1][k][j]==-1){
	    D[1][k][j]=D[0][i][j]+1;
	    Q[!b].push(make_pair(k,j));
	  }
	}
      }
      else{
	if(D[1][i][j]==-1){
	  D[1][i][j]=D[0][i][j]+1;
	  Q[!b].push(make_pair(i,j));
	}
      }
    }
    else{
      if(j<n-1){
	for(int k=0;k<n;k++){
	  if(d[j][k]==1&&D[0][i][k]==-1&&(k==n-1||i!=k)){
	    D[0][i][k]=D[1][i][j];
	    Q[!b].push(make_pair(i,k));
	  }
	}
      }
      else{
	if(D[0][i][j]==-1){
	  D[0][i][j]=D[1][i][j];
	  Q[!b].push(make_pair(i,j));
	}
      }
    }
  }
  printf("%d\n",D[0][n-1][n-1]);
  return 0;
}