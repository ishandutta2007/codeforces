/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int freq[n+1]={0}, x;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        freq[x]++;
    }

    int mx=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
        mx=max(mx,freq[i]);
        if(freq[i]>0) cnt++;
    }

    int ans=min(mx,cnt);

    if(mx==cnt) ans--;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}