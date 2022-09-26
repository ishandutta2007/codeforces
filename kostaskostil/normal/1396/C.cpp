#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second

using namespace std;

const int nmax=1e6+100;
typedef long long ll;
#define int ll

int n, r1, r2, r3, d;
int a[nmax];
int one[nmax];
int two[nmax];

void onef(int i)
{
    one[i]=a[i]*r1+r3;
}

void twof(int i)
{
    two[i]=min(r2+r1, r1*(a[i]+2));
}

int dp[nmax];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>r1>>r2>>r3>>d;
    for (int i=1; i<=n; i++)
        cin>>a[i];
    for (int i=1; i<=n; i++)
        onef(i), twof(i);
    dp[0]=-d;
    for (int i=1; i<=n; i++)
    {
        dp[i]=dp[i-1]+d+one[i];
        if (i>=2)
            dp[i]=min(dp[i], dp[i-2]+4*d+two[i-1]+two[i]);
        if (i>=3)
            dp[i]=min(dp[i], dp[i-3]+7*d+two[i-2]+two[i-1]+two[i]);
    }
    int ans=dp[n];

    int suf=0;
    for (int i=n-1; i>=1; i--)
    {
        suf+=two[i];
        ans=min(ans, (2*(n-i)+1)*d+dp[i-1]+suf+one[n]);
        ans=min(ans, (2*(n-i)+3)*d+dp[i-1]+suf+two[n]);
    }

    cout<<ans<<"\n";

}