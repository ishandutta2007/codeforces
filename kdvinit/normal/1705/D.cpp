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

    int a[n+1];
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        a[i]=x-'0';
    }

    int b[n+1];
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        b[i]=x-'0';
    }
    
    if(a[1]!=b[1] || a[n]!=b[n]) { cout<<-1<<endl; return; }

    int sum=0;
    for(int i=1; i<n; i++)
    {
        a[i]^=a[i+1];
        b[i]^=b[i+1];
        sum+=a[i];
        sum-=b[i];
    }

    if(sum!=0) { cout<<-1<<endl; return; }

    int f0[n+1], f1[n+1];
    f0[n]=n, f1[n]=n;

    for(int i=n-1; i>=1; i--)
    {
        f0[i]=f0[i+1];
        f1[i]=f1[i+1];

        if(a[i]==0) f0[i]=i;
        else f1[i]=i;
    }

    int pos[n+1]={0};
    int c0=0;

    for(int i=1; i<n; i++)
    {
        if(b[i]==1) continue;
        c0++;
        pos[c0]=i;
    }

    int ans=0;
    c0=0;

    for(int i=1; i<n; i++)
    {
        if(a[i]==1) continue;
        c0++;
        int cur = abs(i-pos[c0]);
        ans += cur;
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