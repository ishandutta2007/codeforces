/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1005;
int val[N];

void solve()
{
    int n, k;
    cin>>n>>k;

    int b[n+1], c[n+1], a[n+1];
    for(int i=1; i<=n; i++) cin>>b[i];
    for(int i=1; i<=n; i++) cin>>c[i];
    for(int i=1; i<=n; i++) a[i] = val[b[i]];

    int sa=0, sc=0;
    for(int i=1; i<=n; i++) sa+=a[i];
    for(int i=1; i<=n; i++) sc+=c[i];

    if(sa<=k) { cout<<sc<<endl; return; }

    int dp[k+1]={0};

    for(int i=1; i<=n; i++)
    {
        int x = a[i];
        for(int j=k; j>=0; j--)
        {
            int j2 = j+x;
            if(j2>k) continue;
            dp[j2] = max(dp[j2], dp[j]+c[i]);
        }
    }

    int ans = 0;
    for(int i=0; i<=k; i++) ans = max(ans, dp[i]);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    val[1]=0;
    for(int i=2; i<N; i++) val[i]=N+10;

    for(int i=1; i<N; i++)
    {
        for(int j=1; j<=i; j++)
        {
            int x = i/j;
            int y = i+x;
            if(y>=N) continue;
            val[y]=min(val[y], val[i]+1);
        }
    }

    int t; cin>>t;
    while(t--) solve();
    return 0;
}