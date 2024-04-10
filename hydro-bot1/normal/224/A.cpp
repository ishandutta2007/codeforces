// Hydro submission #6253c65bca53060146715ffe@1649657435798
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long r,s,t,v;
    cin>>r>>s>>t;
    v=sqrt(r*s*t);
    printf("%lld\n",4*(v/r+v/s+v/t));
    return 0;
}