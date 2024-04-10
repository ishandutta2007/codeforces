// Hydro submission #6274d670bda16328ffbb0248@1651824241020
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,a,i,j;
    long long s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=0;
        for(j=0;j<n;j++)
        {
            cin>>a;
            s+=a;
        }
        printf("%lld\n",(s%n)*(n-s%n));
    }
    return 0;
}