#include <bits/stdc++.h>
using namespace std;

const int M=100000;

int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  pair<pair<int,int>,int> P[M];
  for(int i=0;i<m;i++){
    scanf("%d%d",&(P[i].first.first),&(P[i].first.second));
    P[i].first.second*=-1;
    P[i].second=i;
  }
  sort(P,P+m);
  int k=1,I=2,J=1;
  static int A[M],B[M];
  bool F=0;
  for(int t=0;t<m;t++){
    int j=P[t].second;
    if(P[t].first.second==-1){
      A[j]=0,B[j]=k;
      k++;
    }
    else{
      if(I>=k){
	F=1;
	break;
      }
      A[j]=J,B[j]=I;
      J++;
      if(I==J){
	I++;
	J=1;
      }
    }
  }
  if(F){
    puts("-1");
  }
  else{
    for(int j=0;j<m;j++){
      printf("%d %d\n",A[j]+1,B[j]+1);
    }
  }
  return 0;
}