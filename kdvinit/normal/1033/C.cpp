/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int dp[n+1], a[n+1], pos[n+1];
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        pos[a[i]]=i;
    }

    for(int i=n; i>=1; i--)
    {
        int x = pos[i]%i;
        if(x==0) x+=i;

        dp[i]=0;

        for(int j=x; j<=n; j+=i)
        {
            if(a[j]>i && dp[a[j]]==0) dp[i]=1;
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(dp[a[i]]==1) cout<<"A";
        else cout<<"B";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}