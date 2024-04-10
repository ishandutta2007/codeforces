/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin>>n>>m;

    int cnt[m+1]={0};
    for(int i=1;i<=n;i++)
    {
        int x; cin>>x;
        x%=m;
        cnt[x]++;
    }

    int ans=0;
    if(cnt[0]) ans++;

    for(int i=1; 2*i<=m; i++)
    {
        int x = cnt[i];
        int y = cnt[m-i];
        if(x==0 && y==0) continue;
        ans++;
        ans += max((int)0, abs(x-y)-1);
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