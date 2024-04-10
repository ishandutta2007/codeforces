#include <bits/stdc++.h>
using namespace std;

const int N=1000000;
const double EPS=1e-8;
int dp[N];
long long ans[N];

pair<int,long long> sol(long long m)
{
  if(m<N){
    return make_pair(dp[m],ans[m]);
  }
  pair<int,long long> p(0,0ll);
  long long s=(long long)(pow((double)m,1./3.)+EPS);
  for(long long i=s;i>=s-1;i--){
    long long r=min(m-i*i*i,3*i*i+3*i);
    pair<int,long long> q=sol(r);
    q.first++;
    q.second+=i*i*i;
    p=max(p,q);
  }
  return p;
}

int main()
{
  long long m;
  scanf("%lld",&m);
  dp[0]=0;
  for(int i=1;i<N;i++){
    int j=(int)(pow((double)i,1./3.)+EPS);
    dp[i]=dp[i-j*j*j]+1;
  }
  ans[0]=0;
  for(int i=1;i<N;i++){
    if(dp[i-1]>dp[i]){
      dp[i]=dp[i-1];
      ans[i]=ans[i-1];
    }
    else{
      ans[i]=i;
    }
  }
  pair<int,long long> p=sol(m);
  printf("%d %lld\n",p.first,p.second);
  return 0;
}