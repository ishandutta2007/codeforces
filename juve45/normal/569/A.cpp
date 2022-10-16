#include <iostream>

using namespace std;
int d, s, t, q;
int main()
{
cin>>t>>s>>q;
d=s;
int p=0;
int ans=0;
while(d<t)
{
    d=d*q;
    ans++;

}
cout<<ans<<'\n';
    return 0;
}