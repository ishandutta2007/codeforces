/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, k;
    cin>>n>>k;

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; b[i]=a[i]; }
    sort(b+1, b+n+1);

    int mxa = 1e9;
    if(k==n) { cout<<mxa<<endl; return; }
    int mn = b[k+1];

    if(k>1)
    {
        if(n>3) 
        { 
            int cur = 2*b[k];
            
            for(int i=1; i<=n; i++)
            {
                if(a[i]<=b[k]) a[i]=mxa;
            }
            
            int t2 = 0;
            for(int i=1; i<n; i++)
            {
                t2=max(t2, min(a[i], a[i+1]));
            }
            
            t2 = min(t2, 2*b[k+1]);
            cur = max(cur, t2);
            
            cout<<min(cur, mxa)<<endl; return; 
        }
        else
        {
            int ans = max(2*a[1], 2*a[3]);
            ans = max(ans, a[2]);
            ans = min(ans, mxa);
            cout<<ans<<endl;
            return;
        }
    }

    int mn2[n+1]={0};
    for(int i=1; i<n; i++)
    {
        mn2[i]=min(a[i], a[i+1]);
    }

    int pre[n+1]={0};
    int suf[n+1]={0};

    for(int i=1; i<n; i++)
    {
        pre[i]=max(pre[i-1], mn2[i]);
    }

    for(int i=n-1; i>=1; i--)
    {
        suf[i]=max(suf[i+1], mn2[i]);
    }

    int ans = 0;
    for(int i=1; i<=n; i++)
    {
        int rmn = b[1];
        if(a[i]==b[1]) rmn=b[2];

        int mx2=0;
        if(i>1) mx2 = max(mx2, a[i-1]);
        if(i<n) mx2 = max(mx2, a[i+1]);
        if(i>2) mx2 = max(mx2, pre[i-2]);
        if(i<n) mx2 = max(mx2, suf[i+1]);

        int cur = min(2*rmn, mx2);
        ans = max(ans, cur);
    }

    ans = min(ans, mxa);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}