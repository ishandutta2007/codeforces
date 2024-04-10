#include <iostream>

using namespace std;

int main()
{
    long long n,k,t;
    cin>>n>>k>>t;
    if(t<k){cout<<t;return 0;}
    else if(t<=n){cout<<k;return 0;}
    else cout<<n+k-t;
    return 0;
}