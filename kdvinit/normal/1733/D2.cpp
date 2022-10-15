/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int n, x, y;

int cost(int p1, int p2)
{
    int ans = y;
    int l = p2-p1;

    int a2 = l*x;
    ans = min(ans, a2);

    if(l==1) ans=x;
    return ans;
}

void solve()
{
    cin>>n>>x>>y;

    int a[n+1]={0};
    for(int i=1; i<=n; i++)
    {
        char tp; cin>>tp;
        a[i]=tp-'0';
    }

    vector<int> pos;
    for(int i=1; i<=n; i++)
    {
        char tp; cin>>tp;
        int tp2 = tp-'0';
        a[i]=(a[i]+tp2)%2;
        if(a[i]==1) pos.push_back(i);
    }

    int m = pos.size();

    if(m%2==1) { cout<<-1<<endl; return; }

    if(m==0) { cout<<0<<endl; return; }

    if(x>=y)
    {
        int ans = (m/2)*y;

        if(m>2) { cout<<ans<<endl; return; }

        if(pos[0]+1!=pos[1]) { cout<<ans<<endl; return; }

        ans = x;
        if(n>pos[1]+1) ans = min(ans, 2*y);
        if(1<pos[0]-1) ans = min(ans, 2*y);
        if(1<pos[0] && pos[1]<n) ans = min(ans, 3*y);

        cout<<ans<<endl;
        return;
    }

    int dp[m+5][m+5];
    memset(dp, 0, sizeof(dp));

    for(int i=0; i+1<m; i++)
    {
        int j=i+1;
        dp[i][j]=cost(pos[i], pos[j]);
    }

    for(int l=4; l<=m; l++)
    {
        for(int i=0; i+l-1<m; i++)
        {
            int j=i+l-1;
            int c1 = cost(pos[i], pos[i+1]) + dp[i+2][j];
            int c2 = cost(pos[i], pos[i+3]) + dp[i+4][j] + cost(pos[i+1], pos[i+2]);
            
            int c3 = cost(pos[i], pos[j]) + dp[i+1][j-1];
            
            int c4 = c1;
            if(j>=2) c4 = cost(pos[j-1], pos[j]) + dp[i][j-2];
            
            int c5 = c1;
            if(j>=4) c5 =  dp[i][j-4] + cost(pos[j-3], pos[j]) + cost(pos[j-2], pos[j-1]);

            dp[i][j]=min({c1, c2, c3, c4, c5});
        }
    }

    int ans =dp[0][m-1];
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}