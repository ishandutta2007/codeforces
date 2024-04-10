#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5;
int n,ans,t,p;
char c[maxn];

int main()
{
  int qw;
  cin>>qw;
  while(qw--)
    {
      cin>>n;
      for(int i=0;i<n;i++)
	cin>>c[i];
      p=0;
      while(p<n && c[p]==c[n-1]){
	c[n+p]=c[n-1];
	p++;
      }
      if(p==n)
	{
	  cout<< (n+2)/3<<endl;
	  continue;
	}
      t=0;
      ans=0;
      for(int i=p;i<n+p;i++)
	{
	  if(i>p && c[i]!=c[i-1])
	    {
	     ans+=t/3;
	     t=0;
	    }
	  t++;
	}
      ans+=t/3;
      cout<<ans<<endl;
    }
}