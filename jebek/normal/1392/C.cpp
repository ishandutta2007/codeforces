#include<bits/stdc++.h>
using namespace std;

const int maxn=3e5;
int n,a[maxn];
long long ans;

int main()
{
  int qw;
  cin>>qw;
  while(qw--)
    {
      cin>>n;
      ans = 0;
      for(int i=0;i<n;i++)
	{
	  cin>>a[i];
	  if(i>0)
	    ans+=max(0,a[i-1]-a[i]);
	}
      cout<<ans<<endl;
    }
}