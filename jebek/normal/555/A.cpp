#include<iostream>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;

int n,k,t,ans,a;

int main()
{
  cin>>n>>k;
  ans=(n+1);
  for(int i=0;i<k;i++)
    {
      cin>>t;
      ans+=t-1;
      for(int j=0;j<t;j++)
	{
	  cin>>a;
	  if(a==j+1)
	    ans-=2;
	}
    }
  cout<<ans<<endl;
}