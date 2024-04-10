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

    vector< array<int, 2> > ab(n+1);
    ab[0][0]=-1; ab[0][1]=-1;

    for(int i=1; i<=n; i++) cin>>ab[i][0]>>ab[i][1];
    sort(ab.begin(), ab.end());

    int dp[n+1], a[n+1], b[n+1];
    for(int i=0; i<=n; i++)
    {
        a[i]=ab[i][0];
        b[i]=ab[i][1];
    }

    dp[0]=0;
    for(int i=1; i<=n; i++)
    {
        int x = a[i];
        int y = b[i];
        x-=y;
        x--;

        int ind = upper_bound(a, a+n+1, x) - a;
        if(ind !=0) ind--;
        dp[i] = dp[ind] + (i-ind-1);
    }

    int ans=n;
    for(int i=1; i<=n; i++)
    {
        int tmp = dp[i]+(n-i);
        ans=min(ans, tmp);
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}