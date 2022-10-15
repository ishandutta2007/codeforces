/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 1e5+1;
int a[N];

int ans, tmp, k, n;

void eval(int i, int j)
{
    if(i==0 || j==0 || i==j) return;
    tmp = (i*j) - (k*(a[i]|a[j]));
    ans = max(ans, tmp);
}

void solve()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];

    ans = (-(1e18));
    for(int i=1; i<n; i++) eval(i, i+1);

    eval(1, n);

    array<int, 2> b[n+1];
    for(int i=1; i<=n; i++)
    {
        b[i] = {a[i], i};
    }
    sort(b+1, b+n+1);

    for(int i=1; i<n; i++)
    {
        int i1 = b[i][1];
        int i2 = b[i+1][1];
        eval(i1, i2);
    }
    eval(b[1][1], b[n][1]);

    int i1 = b[1][1];
    int i2 = b[n][1];

    int a1 = b[1][0];
    int a2 = b[n][0];

    for(int i=1; i<=n; i++)
    {
        eval(i, 1);
        eval(i, n);
        eval(i, i1);
        eval(i, i2);
        eval(i, k);
    }

    map<int, int> mp;
    for(int i=1; i<=n; i++) mp[a[i]]=i;

    for(int i=1; i<=n; i++)
    {
        eval(i, mp[a1]);
        eval(i, mp[a2]);
    }

    for(int i=1; i<=n; i++)
    {
        b[i] = {i-(k*a[i]), i};
    }
    sort(b+1, b+n+1);

    i1 = b[1][1];
    i2 = b[n][1];

    a1 = b[1][0];
    a2 = b[n][0];

    for(int i=1; i<=n; i++)
    {
        eval(i, i1);
        eval(i, i2);
        eval(i, mp[a1]);
        eval(i, mp[a2]);
    }

    for(int i=1; i<n; i++)
    {
        int i1 = b[i][1];
        int i2 = b[i+1][1];
        eval(i1, i2);
    }
    eval(b[1][1], b[n][1]);

    for(int i=1; i<=n; i++)
    {
        b[i] = {i-a[i], i};
    }
    sort(b+1, b+n+1);

    i1 = b[1][1];
    i2 = b[n][1];

    a1 = b[1][0];
    a2 = b[n][0];

    for(int i=1; i<n; i++)
    {
        int i1 = b[i][1];
        int i2 = b[i+1][1];
        eval(i1, i2);
    }
    eval(b[1][1], b[n][1]);

    for(int i=1; i<=n; i++)
    {
        eval(i, i1);
        eval(i, i2);
        eval(i, mp[a1]);
        eval(i, mp[a2]);
    }

    int mn = n-200;
    mn = max(mn, (int)1);
    for(int i=1; i<=n; i++)
    {
        for(int j=mn; j<=n; j++) eval(i, j);
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