#include <iostream>

using namespace std;
int n, a, b;
int main()
{
cin>>n>>a>>b;
int ans=(a+b)%n;
if(ans<=0)ans+=n;
cout<<ans<<'\n';
    return 0;
}