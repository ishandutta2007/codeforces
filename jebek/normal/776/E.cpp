#include<bits/stdc++.h>
using namespace std;

const int MOD=1e9+7;
long long n,k;
vector<long long>v;

long long fi(long long x)
{
  long long ret=x,xx=x;
  v.clear();
  for(long long i=2;i*i<=x;i++)
    {
      if(x%i==0)
	{
	  while(x%i==0) x/=i;
	  v.push_back(i);
	}
    }
  if(x>1) v.push_back(x);
  int m=v.size();
  for(int i=1;i<(1<<m);i++)
    {
      int tmp=__builtin_popcount(i);
      long long mul=1;
      for(int j=0;j<m;j++)
	if(i&(1<<j))
	  mul*=v[j];
      if(tmp%2) ret-=xx/mul;
      else ret+=xx/mul;
    }
  return ret;
}

int main()
{
  cin>>n>>k;
  k=(k+1)/2;
  if(k>=50)
    {
      cout<<1<<endl;
      return 0;
    }
  for(int i=0;i<k;i++)
    n=fi(n);
  cout<<n%MOD<<endl;
}