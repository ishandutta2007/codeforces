/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, s;
    cin>>n>>s;

    int sum=0;
    int pre[n+1]={0};
    int ans=n;

    pre[0]=0;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        sum+=x;
        if(x==1) pre[sum]=i;

        if(sum>=s)
        {
            int tmp = pre[sum-s]+n-i;
            ans=min(ans, tmp);
        }
    }

    if(sum<s) ans=-1;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}