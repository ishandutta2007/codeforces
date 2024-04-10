#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll pw10[15];
ll ans(ll x,int y)
{
    if(x==0)
        return 0ll;
    if(x<2050||y<0)
        return 1e18;
    ll res=1e18;
    for(int i=y;i>=0;i--)
        if(pw10[i]*2050ll<=x)
            res=min(res,ans(x%(pw10[i]*2050ll),i-1)+x/(pw10[i]*2050ll));
    return res;
}
int main()
{
    pw10[0]=1;
    for(int i=1;i<15;i++)
        pw10[i]=pw10[i-1]*10ll;
    int T;
    cin>>T;
    while(T--)
    {
        ll x;
        cin>>x;
        ll res=ans(x,14);
        if(res==1e18)
            puts("-1");
        else    cout<<res<<endl;
    }
    return 0;
}