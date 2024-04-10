/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e6+1;
char a[N];
int dp[N];
int n;

void build(int i)
{
    if(2*i<n)
    {
        build(2*i);
        build(2*i+1);

        if(a[i]=='?') dp[i] = dp[2*i] + dp[2*i+1];
        if(a[i]=='1') dp[i] = dp[2*i];
        if(a[i]=='0') dp[i] = dp[2*i+1];
    }
    else
    {
        if(a[i]=='?') dp[i]=2;
        else dp[i]=1;
    }
}

void update(int i)
{
    if(2*i<n)
    {
        if(a[i]=='?') dp[i] = dp[2*i] + dp[2*i+1];
        if(a[i]=='1') dp[i] = dp[2*i];
        if(a[i]=='0') dp[i] = dp[2*i+1];
    }
    else
    {
        if(a[i]=='?') dp[i]=2;
        else dp[i]=1;
    }
    if(i==1) return;
    update(i/2);
}

void solve()
{
    int k;
    cin>>k;

    n = 1<<k;
    for(int i=1; i<n; i++) cin>>a[n-i];

    build(1);

    int q; cin>>q;
    int p; char c;

    while(q--)
    {
        cin>>p>>c;
        a[n-p]=c;
        update(n-p);
        cout<<dp[1]<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}