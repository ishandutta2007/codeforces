#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll h[200009];
pair<ll,ll>dp[200009];
ll go(ll x,ll y,ll z)
{
    if(y>max(x,z))return 0;
    return max(x,z)-y+1;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)cin>>h[i];
        for(int i=2;i+1<=n;i++)
        dp[i]=max(dp[i-1],make_pair(dp[i-2].first+1,dp[i-2].second-go(h[i-1],h[i],h[i+1])));
        cout<<-dp[n-1].second<<endl;
     

    }
    return 0;
}