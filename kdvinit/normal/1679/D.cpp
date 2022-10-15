/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 2e5 + 100;
int n, m, k;
int w[N], eu[N], ev[N];

bool check(int mx)
{
    vector<int> out[n+1];
    int in[n+1]={0};

    for(int i=1; i<=m; i++)
    {
        int x = eu[i];
        int y = ev[i];

        if(w[x]>mx || w[y]>mx) continue;

        in[y]++;
        out[x].push_back(y);
    }

    queue<int> cur;
    vector<int> topo;

    for(int i=1; i<=n; i++)
    {
        if(in[i]==0) cur.push(i);
    }

    while(!cur.empty())
    {
        int node = cur.front();
        cur.pop();

        topo.push_back(node);
        for(auto x: out[node])
        {
            in[x]--;
            if(in[x]==0) cur.push(x);
        }
    }

    for(int i=1; i<=n; i++)
    {
        if(in[i]!=0) return true;
    }

    int dp[n+1]={0};
    int ans=0;

    for(int i=n-1; i>=0; i--)
    {
        int x = topo[i];
        for(auto y: out[x])
        {
            dp[x] = max(dp[x], 1+dp[y]);
        }
        ans=max(ans, dp[x]);
    }

    if(ans>=k-1) return true;
    else return false;
}

void solve()
{
    cin>>n>>m>>k;

    int mn=1e9 + 5;
    for(int i=1; i<=n; i++) cin>>w[i], mn = min(mn, w[i]);
    if(k==1) { cout<<mn<<endl; return; }

    for(int i=1; i<=m; i++) cin>>eu[i]>>ev[i];

    int mx = 1e9 + 1;
    int l=0, r=mx;

    while(l+1!=r)
    {
        int mid=(l+r)/2;
        if(check(mid)) r=mid;
        else l=mid;
    }

    int ans=r;
    if(r==mx) ans=-1;

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}