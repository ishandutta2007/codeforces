/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n; cin>>n;

    map<int, int> mp;
    int ans=0;

    for(int i=1; 1; i++)
    {
        if((i*i)>n) break;
        int x = i*i;
        int y = i*i*i;

        if(x<=n && mp[x]==0) ans++;
        mp[x]=1;

        if(y<=n && mp[y]==0) ans++;
        mp[x]=1; mp[y]=1;
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