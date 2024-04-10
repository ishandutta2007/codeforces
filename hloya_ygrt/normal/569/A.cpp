#include <iostream>

using namespace std;

int main()
{
    int s,t,q;
    int ans=0;
    cin>>t>>s>>q;
    while (s<t)
    {
        s*=q;
        ans++;
    }
    if (ans==0) ans=1;
    cout<<ans;
    return 0;
}