#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int r[40];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {

        ll x,n;
        cin>>x>>n;
        ll od=(n+1)/2,ev=n/2;
        ll ans=(od/2)*2;
        if(od%2)ans-=od*2-1;
        ans-=(ev/2)*2;
        if(ev%2)ans+=ev*2;
       ll u=abs(x);
       if(u%2)x-=ans;
       else x+=ans;
        cout<<x<<endl;
    }
    return 0;
}