#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[50009],n,x,dp[500009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++)cin>>a[i];
        cin>>x;
        for(int i=1;i<=n;i++)a[i]-=x;
        ll ans=0,ls=0,sum=0;
        for(int i=1;i<=n;i++)
        {
            if(ls==0){ans++;sum+=a[i];ls++;continue;}
            if(sum+a[i]<0){sum=0;ls=0;continue;}
            sum+=a[i];
            sum=min(sum,a[i]);
            ls++;
            ans++;

        }
        cout<<ans<<endl;

    }

    return 0;
}