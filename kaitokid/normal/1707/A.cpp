#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,q,a[100009];
bool ch(int x)
{
    ll u=q;
    ll d=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]<=u){d++;continue;}
        if(u==0)continue;
        if(d+n-i-1<x)
        {
            u--;
            d++;continue;
        }
        continue;
    }
    return (d>=x);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;
        for(int i=0;i<n;i++)cin>>a[i];
        ll l=0,r=n;
        while(l<r)
        {
            int mid=(l+r+1)/2;
            if(ch(mid))l=mid;
            else r=mid-1;
        }
        ll u=q;
        ll d=0;
         for(int i=0;i<n;i++)
    {
        if(a[i]<=u){d++;cout<<1;continue;}
        if(u==0){cout<<0;continue;}
        if(d+n-i-1<l)
        {
            u--;
            cout<<1;
            d++;continue;
        }
        cout<<0;
        continue;
    }
    cout<<endl;

    }

    return 0;
}