#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  long long A,B;
  scanf("%d%I64d%I64d",&n,&A,&B);
  static pair<long long,long long> P[300000];
  for(int i=0;i<n-1;i++){
    scanf("%I64d%I64d",&(P[i].first),&(P[i].second));
  }
  sort(P,P+n-1);
  priority_queue<long long> Q;
  int I=n-2;
  while(I>=0&&P[I].first>A){
    Q.push(-(P[I].second-P[I].first+1));
    I--;
  }
  int K=n-I-1,M=K;
  long long X=A,BB=0ll;
  while(1){
    long long T=(I==-1?0:P[I].first);
    BB+=X-T;
    X=T;
    while(!Q.empty()&&BB>=-Q.top()){
      BB-=-Q.top();
      Q.pop();
      K--;
    }
    //printf("%d %d\n",I,K);
    M=min(M,K);
    if(I==-1){
      break;
    }
    while(I>=0&&P[I].first==T){
      Q.push(-(P[I].second-P[I].first+1));
      K++;
      I--;
    }
  }
  printf("%d\n",M);
  return 0;
}