// Hydro submission #6274ce41997df5291339d646@1651822146479
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,i;
    long long p,a,b,c;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>p>>a>>b>>c;
        printf("%lld\n",min(min((a-p%a)%a,(b-p%b)%b),(c-p%c)%c));
    }
    return 0;
}