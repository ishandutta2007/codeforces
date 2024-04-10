// Hydro submission #6274d65f997df5291339e3bc@1651824223540
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    long long a,b,m,n;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>a>>b;
        m=abs(a-b);
        n=m?min(b%m,m-b%m):0;
        printf("%lld %lld\n",m,n);
    }
    return 0;
}