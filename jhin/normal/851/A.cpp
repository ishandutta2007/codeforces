#include <iostream>

using namespace std;
int n,k,t;
int main()
{
    cin>>n>>k>>t;
    if(t>=k&&t<=n) cout<<k;
        if(t<k) cout<<t;
    if(t>n)cout<<k-(t-n);
    return 0;
}