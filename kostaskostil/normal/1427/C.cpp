#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

typedef long long ll;
#define int ll

const int nmax=5e5+100;

int x[nmax];
int y[nmax];
int t[nmax];
int dp[nmax];
int mx[nmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    int ___;
//    cin>>___;
//    for (int _=0; _<___; _++)
//    {
//
//    }
    int r, n;
    cin>>r>>n;
    for (int i=1; i<=n; i++)
        cin>>t[i]>>x[i]>>y[i];
    x[0]=1;
    y[0]=1;
    t[0]=0;
    dp[0]=0;

    for (int i=1; i<=n; i++)
    {
        dp[i]=-1e9;
        for (int j=max(0ll, i-1010); j<i; j++)
        {
            if (t[j]+abs(x[j]-x[i])+abs(y[j]-y[i]) <= t[i])
                dp[i]=max(dp[i], dp[j]+1);
        }
        if (i>1005)
            dp[i]=max(dp[i], mx[i-1005]+1);
//        cout<<i<<" "<<dp[i]<<"\n";
        mx[i]=max(mx[i-1], dp[i]);
    }
    int ans=0;
    for (int i=0; i<=n; i++)
        ans=max(ans, dp[i]);
    cout<<ans<<"\n";
}