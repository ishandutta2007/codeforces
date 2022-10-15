/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n;
    cin>>n;

    int a[n+2];
    for(int i=1; i<=n; i++) cin>>a[i];

    int inc=n;
    for(int i=n; i>=1; i--)
    {
        if(a[i]>a[i+1]) break;
        inc=i;
    }

    int f[n+1]={0};
    int dis[n+1]={0};
    int lst[n+1]={0};

    for(int i=1; i<=n; i++)
    {
        if(f[a[i]]==0) dis[i]=1;
        f[a[i]]++;
        dis[i]+=dis[i-1];
        lst[a[i]]=i;
    }

    int lm[n+1];
    lm[0]=0;

    for(int i=1; i<=n; i++)
    {
        lm[i]=max(lm[i-1], lst[a[i]]);
    }

    for(int i=inc-1; i<=n; i++)
    {
        if(lm[i]<=i) { cout<<dis[i]<<endl; return; }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}