#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[200009],b[200009];
bool ch(ll x)
{
    for(int i=0;i<n;i++)
    b[i]=a[i];
    for(int i=n-1;i>1;i--)
    {
        if(b[i]<x)return false;
        ll d=min(a[i],b[i]-x);
        d/=3;
        b[i-1]+=d;
        b[i-2]+=2*d;
    }
    if(b[0]<x || b[1]<x)return false;
    return true;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)cin>>a[i];
        ll l=0,r=1000000000;
        while(l<r)
        {
            ll mid=(l+r+1)/2;
            if(ch(mid))l=mid;
            else r=mid-1;
        }
        cout<<l<<endl;

    }
    return 0;
}