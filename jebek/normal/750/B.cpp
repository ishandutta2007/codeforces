#include<bits/stdc++.h>
using namespace std;

const int MAX=20000;
int a,n;

int main()
{
  cin>>n;
  a=MAX;
  for(int i=0;i<n;i++)
    {
      int x;string s;
      cin>>x>>s;
      if(s[0]=='E' || s[0]=='W')
	{
	  if(a==0 || a==MAX)
	    {
	      cout<<"NO\n";
	      return 0;
	    }
	  continue;
	}
      if(s[0]=='N')
	{
	  if(a+x<=MAX)
	    a+=x;
	  else
	    {
	      cout<<"NO\n";
	      return 0;
	    }
	}
      if(s[0]=='S')
	{
	  if(a>=x)
	    a-=x;
	  else
	    {
	      cout<<"NO\n";
	      return 0;
	    }
	}
    }
  if(a==MAX)
    cout<<"YES\n";
  else
    cout<<"NO\n";
}