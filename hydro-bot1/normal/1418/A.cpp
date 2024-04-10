// Hydro submission #6274ca8e997df5291339cbe2@1651821199424
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,x,y,i;
    long long k,s;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>x>>y>>k;
        s=k*(y+1);
        s--,x--;
        printf("%lld\n",k+s/x+(s%x?1:0));
    }
    return 0;
}