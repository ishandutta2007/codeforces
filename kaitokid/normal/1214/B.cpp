#include <iostream>

using namespace std;
int n,b,g;
int main()
{
  ios::sync_with_stdio(0);
cin>>b>>g>>n;
int ans=0;
for(int i=0;i<=min(n,b);i++)if(n-i<=g)ans++;
cout<<ans;
    return 0;
}