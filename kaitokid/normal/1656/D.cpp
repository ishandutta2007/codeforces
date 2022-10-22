#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ch(ll x,ll u)
{
    if(u>2000000000)return false;
    ll p=u*(u+1)/2;
    if(x<p)return false;
    if((x-p)%u)return false;
    return true;
}
ll ans(ll x)
{
    ll u=x,p=1;
    while(u%2==0){p*=2;u/=2;}
    if(u>1)if(ch(x,u))return u;
    p*=2;
    if(ch(x,p))return p;
    return -1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        ll x;
        cin>>x;
        cout<<ans(x)<<endl;
    }
    return 0;
}