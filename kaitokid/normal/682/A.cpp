#include <iostream>

using namespace std;

int main()
{
 int n,m;
 long long  ans=0;
 cin>>n>>m;
 for(int i=1;i<=n;i++)
  {
      int d=5-i%5;
      if(d<=m){ans++;ans+=(m-d)/5;}
  }
  cout<<ans;

    return 0;
}