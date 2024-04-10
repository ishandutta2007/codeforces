// Hydro submission #6274cc9fbda16328ffbaf978@1651821728214
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,x,a,i,j;
    long long mx,mn;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n>>x;
        mx=0,mn=0;
        for(j=0;j<n;j++)
        {
            cin>>a;
            mn+=a,mx+=(a-1)/x+1;
        }
        printf("%lld %lld\n",(mn-1)/x+1,mx);
    }
    return 0;
}