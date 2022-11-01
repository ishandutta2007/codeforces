#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>

using namespace std;

long long ans,t,a,b,c,x,y,z;

int main()
{
  cin>>a>>b>>c>>x>>y>>z;
  t=1;
  ans=-a-x;
  for(int i=0;i<=b+c;i++)
    {
      ans+=2*a;
      if(i==b)
	t--;
      if(i==z)
	t--;
      a+=t;
    }
  cout<<ans<<endl;
}