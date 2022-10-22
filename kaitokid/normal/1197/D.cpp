#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n,m,k,ans;
ll a[300009];
int main()
{
    ios::sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<min(n,m);i++)
    {
        ll x=i,y=i,sum=0;
        while(y<n)
        {
            sum+=a[y];
            ll res= sum-k*((y-x+m)/m);
            ans=max(ans,res);
            y++;
            if(((y-x)%m==0)&&res<0){x=y;sum=0;}
        }


    }
    cout<<ans;

    return 0;
}