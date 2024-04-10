#include<bits/stdc++.h>
#define X first
#define Y second
#define MP make_pair
using namespace std;
typedef long long ll;
int n,k;
string s;


int main()
{
  ios_base::sync_with_stdio(false);cin.tie(0);
  int qw;
  cin>>qw;
  while(qw--)
    {
      cin>>n>>k>>s;
      if(k%2==1)
	{
	  cout<<"NO\n";
	  continue;
	}
      bool bad=false;
      int n1=0, n2=0;
      for(int i=0;i<k;i++)
	{
	  bool one=false, zero=false;
	  for(int j=i;j<n;j+=k)
	    {
	      if(s[j]=='1')
		one=true;
	      if(s[j]=='0')
		zero=true;
	    }
	  if(one && zero)
	    bad=true;
	  if(one)
	    n1++;
	  if(zero)
	    n2++;
	}
      if(bad || n1>k/2 || n2>k/2)
	cout<<"NO\n";
      else
	cout<<"YES\n";
    }
}