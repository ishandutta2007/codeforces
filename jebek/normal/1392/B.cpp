#include<bits/stdc++.h>
using namespace std;

const int inf=1e9,maxn=3e5;
int n,MAX,MIN,a[maxn];
long long k;

int main()
{
  int qw;
  cin>>qw;
  while(qw--)
    {
      cin>>n>>k;
      MIN=inf, MAX=-inf;
      for(int i=0;i<n;i++)
	{
	  cin>>a[i];
	  MAX=max(MAX,a[i]);
	  MIN=min(MIN,a[i]);
	}
      if(k%2==1)
	{
	  for(int i=0;i<n;i++)
	    cout<<MAX-a[i]<<" ";
	}
      else
	{
	  for(int i=0;i<n;i++)
	    cout<<a[i]-MIN<<" ";
	}
      cout<<endl;
    }
}