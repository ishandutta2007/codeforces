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

    int a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int pos[n+1]={0};
    int pre[n+1]={0};

    for(int i=2; i<=n; i++)
    {
        if(a[i-1]<(2*a[i])) pos[i]=1;
        pre[i]=pre[i-1]+pos[i];
    }

    int ans=0;
    for(int i=1; i<=n-k; i++)
    {
        int j = i+k;
        int cur = pre[j]-pre[i];
        if(cur==k) ans++;
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