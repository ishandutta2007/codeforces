#include<bits/stdc++.h>
using namespace std;

int main()
{
  int qw;
  cin>>qw;
  while(qw--)
    {
      int n,a;
      cin>>n>>a;
      bool eq=true;
      for(int i=1;i<n;i++)
	{
	  int tmp;
	  cin>>tmp;
	  if(tmp!=a)
	    eq=false;
	}
      if(eq)
	cout<<n<<endl;
      else
	cout<<1<<endl;
    }
}