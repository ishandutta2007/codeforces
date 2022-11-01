#include<iostream>
#include<algorithm>

using namespace std;

int x,ans;
string s;

int main()
{
  int a[]={31,29,31,30,31,30,31,31,30,31,30,31};
  cin>>x>>s;
  cin>>s;
  if(s=="month")
    {
      for(int i=0;i<12;i++)
	if(a[i]>=x)
	  ans++;
    }
  else
    {
      int sum=0;
      for(int i=0;i<12;i++)
	sum+=a[i];
      x--;
      int k=4;
      for(int i=0;i<sum;i++)
	{
	  if(k==x)
	    ans++;
	  k=(k+1)%7;
	}
    }
  cout<<ans<<endl;
}