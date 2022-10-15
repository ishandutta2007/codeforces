/*
K.D. Vinit  /,,/
Problem  - D
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int b2(int x)
{
    int b = 0;
    int odd=0;
    while(x!=0)
    {
        if(x%2==1) odd++;
        x/=2;
        b++;
    }
    if(odd==1) b--;
    return b;
}

int n2(int x)
{
    int b = b2(x);
    int ans=1;
    while(b--) ans*=2;
    return ans;
}

int c2(int x)
{
    int y = n2(x);
    int ans = y-x;
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int f[n+2]={0};
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        f[x]++;
    }

    int p2[21]={0}, cost[21]={0};
    for(int i=0; i<=20; i++) p2[i]=-1;

    int sum[n+2]={0};
    int ans = n*5;

    for(int i=0; i<=n+1; i++)
    {
        if(i!=0) sum[i]=sum[i-1];
        sum[i]+=f[i];

        int nn = n2(sum[i]);
        int bb = b2(sum[i]);
        p2[bb] = i;
        cost[bb] = nn-sum[i];

        for(int j=0; j<=20; j++)
        {
            if(p2[j]==-1) continue;
            int ii = p2[j];
            int tmp = cost[j] + c2(sum[i]-sum[ii]) + c2(n-sum[i]);
            ans = min(ans, tmp);
        }
    }

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}