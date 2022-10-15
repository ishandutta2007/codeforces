/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int mod = 1e9 + 7;

void solve()
{
    int n;
    cin>>n;

    int a[n+1], b[n+1], c[n+1], pos[n+1];
    for(int i=1; i<=n; i++) cin>>a[i], pos[a[i]]=i;
    for(int i=1; i<=n; i++) cin>>b[i];
    for(int i=1; i<=n; i++) cin>>c[i];

    int vis[n+1]={0}, ans=1;
    for(int i=1; i<=n; i++)
    {
        if(vis[i]==1) continue;

        int mul=2, j=i, len=0;
        while(vis[j]!=1)
        {
            vis[j]=1;
            if(c[j]!=0) mul=1;
            int x = b[j];
            j = pos[x];
            len++;
        }

        if(len==1) mul=1;
        ans*=mul;
        ans%=mod;
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