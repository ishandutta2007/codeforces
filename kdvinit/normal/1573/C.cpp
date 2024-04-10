/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    vector<int> out[n+1];
    int in[n+1]={0}, dp[n+1];

    for(int i=1; i<=n; i++) dp[i]=-1;

    for(int i=1; i<=n; i++)
    {
        int k; cin>>k;
        while(k--)
        {
            int x;
            cin>>x;

            in[i]++;
            out[x].push_back(i);
        }
    }

    queue<int> cur;

    for(int i=1; i<=n; i++)
    {
        if(in[i]==0)
        {
            cur.push(i);
            dp[i]=1;
        }
    }


    while(!cur.empty())
    {
        int node = cur.front();
        cur.pop();

        for(auto x: out[node])
        {
            in[x]--;
            int y = dp[node];
            if(x<node) y++;

            dp[x]=max(dp[x], y);
            if(in[x]==0) cur.push(x);
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(in[i]!=0) { cout<<-1<<endl; return; }
    }

    int ans = 0;
    for(int i=1; i<=n; i++) ans = max(ans, dp[i]);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}