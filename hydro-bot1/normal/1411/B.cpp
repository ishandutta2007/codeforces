// Hydro submission #6274ca33997df5291339ca97@1651821107988
#include<bits/stdc++.h>
using namespace std;
bool f(long long x)
{
    long long m=x;
    while(m>0)
    if(m%10&&x%(m%10))
    return false;
    else m/=10;
    return true;
}
int main()
{
    long long n,s;
    int t,i;
    cin>>t;
    for(i=0;i<t;i++)
    {
        cin>>n;s=n;
        while(!f(s)) s++;
        printf("%lld\n",s);
    }
    return 0;
}