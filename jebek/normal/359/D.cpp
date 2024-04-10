#include<iostream>
#include<algorithm>
#include<set>

using namespace std;

long long MAX,n,a[300100],dp1[300100],dp2[300100];
set<long long>s;

int main()
{
  cin>>n;
  cin>>a[0];
  dp1[0]=0;
  dp2[0]=0;
  for(int i=1;i<n;i++)
    {
      cin>>a[i];
      dp1[i]=i;
      dp2[i]=i;
      while(dp1[i]>0 && a[dp1[i]-1]%a[i]==0)
	dp1[i]=dp1[dp1[i]-1];
      //   cout<<dp1[i]<<endl;
    }
  for(int i=n-2;i>-1;i--)
    {
       while(dp2[i]<n-1 && a[dp2[i]+1]%a[i]==0)
	dp2[i]=dp2[dp2[i]+1];
    }
  for(int i=0;i<n;i++)
    {
      //   cout<<dp1[i]<<" "<<dp2[i]<<endl;
      if(dp2[i]-dp1[i]==MAX)
	s.insert(dp1[i]);
      else if(dp2[i]-dp1[i]>MAX)
	{
	  MAX=dp2[i]-dp1[i];
	  s.clear();
	  s.insert(dp1[i]);
	}
    }
  cout<<s.size()<<" "<<MAX<<endl;;
  while(s.size())
    {
      cout<<(*(s.begin()))+1<<" ";
      s.erase(s.begin());
    }
  cout<<endl;
}