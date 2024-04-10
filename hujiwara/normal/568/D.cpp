#include <bits/stdc++.h>
using namespace std;

int n,k;
long long A[100000],B[100000],C[100000];
int ansa[6],ansb[6];
int V[6][100000];
int M[6];

bool rec(int t)
{
  int m=M[t];
  //printf("%d %d\n",t,m);
  if(m<=k-t){
    puts("YES");
    printf("%d\n",t+m);
    for(int x=0;x<t;x++){
      printf("%d %d\n",ansa[x]+1,ansb[x]+1);
    }
    for(int x=0;x<m;x++){
      printf("%d %d\n",V[t][x]+1,-1);
    }
    return 1;
  }
  if(k==t){
    return 0;
  }
  if(k-t>1&&m>10*(k-t)*(k-t)){
    for(int T=0;T<20;T++){
      int i=rand()%M[t],j=rand()%M[t];
      int u=V[t][i],v=V[t][j];
      long long CC=(A[u]*B[v]-B[u]*A[v]),AA=(B[u]*C[v]-C[u]*B[v]),BB=(C[u]*A[v]-A[u]*C[v]);
      if(CC==0ll){
	continue;
      }
      ansa[t]=u;
      ansb[t]=v;
      M[t+1]=0;
      for(int x=0;x<m;x++){
	int w=V[t][x];
	if(CC*C[w]+AA*A[w]+BB*B[w]!=0ll){
	  V[t+1][M[t+1]]=w;
	  M[t+1]++;
	}
      }
      if(M[t]-M[t+1]>=k-t+1){
	return rec(t+1);
      }
    }
    return 0;
  }
  for(int i=0;i<k+1;i++){
    for(int j=i+1;j<k+1;j++){
      int u=V[t][i],v=V[t][j];
      long long CC=(A[u]*B[v]-B[u]*A[v]),AA=(B[u]*C[v]-C[u]*B[v]),BB=(C[u]*A[v]-A[u]*C[v]);
      if(CC==0ll){
	continue;
      }
      ansa[t]=u;
      ansb[t]=v;
      M[t+1]=0;
      for(int x=0;x<m;x++){
	int w=V[t][x];
	if(CC*C[w]+AA*A[w]+BB*B[w]!=0ll){
	  V[t+1][M[t+1]]=w;
	  M[t+1]++;
	}
      }
      if(rec(t+1)){
	return 1;
      }
      if(m-M[t+1]>=k-t+1){
	return 0;
      }
    }
  }
  return 0;
}


int main()
{
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;i++){
    scanf("%lld%lld%lld",A+i,B+i,C+i);
  }
  M[0]=n;
  for(int i=0;i<n;i++){
    V[0][i]=i;
  }
  if(!rec(0)){
    puts("NO");
  }
  return 0;
}