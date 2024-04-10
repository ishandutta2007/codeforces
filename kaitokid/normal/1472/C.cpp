#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[200009];
ll a[200009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++){cin>>a[i];dp[i]=0;}
        for(int i=n-1;i>=0;i--)
        {
            if(i+a[i]>=n){dp[i]=a[i];continue;}
            dp[i]=a[i]+dp[i+a[i]];

        }
       ll ans=0;
       for(int i=0;i<n;i++)ans=max(dp[i],ans);
       cout<<ans<<endl;

     }
    return 0;
}