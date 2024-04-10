#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll a[2009];
ll go(ll x)
{
    ll l=-1,r=0,sum=0,ans=0;
    while(r<n)
    {
        sum+=a[r];
        if(sum==x){ans=max(ans,r-l);sum=0;l=r;}
        r++;
    }
    if(sum==0)return ans;
    return n+10;

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
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        ll res=n,d=0;
        for(int i=0;i<n;i++)
        {
            d+=a[i];
            if((sum%d)==0)res=min(res,go(d));
        }
        cout<<res<<endl;
     }
    return 0;
}