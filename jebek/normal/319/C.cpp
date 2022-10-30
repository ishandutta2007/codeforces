#include<iostream>
#include<algorithm>
#include<deque>
#define X first
#define Y second

using namespace std;

const long long MAXN=200000;
typedef pair<long long,long long> pii;
long long dp[MAXN],a[MAXN],b[MAXN],n;
deque<pii>dq;

long long update(long long i,long long j)
{
  return dp[i]+a[j]*b[i];
}

long long when(long long i,long long j,long long e)
{
  long long l=j+1,r=e;
  while(1<r-l)
    {
      long long mid=(l+r)/2;
      //   cout<<l<<"->"<<r<<endl;
      if(update(i,mid)<update(j,mid))
	l=mid;
      else
	r=mid;
    }
  return r;
}

int main()
{
  cin>>n;
  for(long long i=0;i<n;i++)
    cin>>a[i];
  for(long long i=0;i<n;i++)
    cin>>b[i];
  dp[0]=0;
  dq.push_back(pii(0,1));
  for(long long i=1;i<n;i++)
    {
      while(dq.size()>1 && dq[1].Y<=i)
	dq.pop_front();
      dp[i]=update(dq.front().X,i);

      long long e=n;
      while(dq.size()>1 && update(dq.back().X,dq.back().Y)>=update(i,dq.back().Y))
	e=dq.back().Y,dq.pop_back();
      long long tmp=when(dq.back().X,i,e);
      if(tmp<n)
	dq.push_back(pii(i,tmp));
      //cout<<dp[i]<<" "<<tmp<<" "<<e<<endl;
    }
  cout<<dp[n-1]<<endl;
}