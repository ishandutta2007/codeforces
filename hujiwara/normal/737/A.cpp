#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n,k;
  long long s,t;
  scanf("%d%d%I64d%I64d",&n,&k,&s,&t);
  static pair<long long,long long> P[200000];
  for(int i=0;i<n;i++){
    scanf("%I64d%I64d",&(P[i].first),&(P[i].second));
  }
  sort(P,P+n);
  int N=0;
  for(int i=0;i<n;i++){
    if(N==0||P[N-1].second<P[i].second){
      P[N]=P[i];
      N++;
    }
  }
  static long long g[200002];
  g[0]=0;
  for(int i=0;i<k;i++){
    scanf("%I64d",g+i+1);
  }
  g[k+1]=s;
  sort(g,g+k+2);
  int L=-1,R=N;
  while(L+1<R){
    int d=(L+R)/2;
    long long F=P[d].second;
    long long T=0;
    for(int i=0;i<k+1;i++){
      long long D=g[i+1]-g[i];
      if(D>F){
	T=-1;
	break;
      }
      T+=(2*D<=F?D:3*D-F);
    }
    if(T==-1||T>t){
      L=d;
    }
    else{
      R=d;
    }
  }
  printf("%I64d\n",R==N?-1:P[R].first);
  return 0;
}