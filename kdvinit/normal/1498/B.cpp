/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, w;
    cin>>n>>w;

    map<int, int, greater<int> > mp;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        mp[x]++;
    }

    int ans=0;
    while(1)
    {
        ans++;
        int flag=1;
        int curr=w;
        for(auto &x: mp)
        {
            int cnt = x.second;
            int b = x.first;
            if(cnt==0) continue;
            flag = 0;
            while(cnt!=0 && curr>=b)
            {
                curr-=b;
                cnt--;
            }
            x.second=cnt;
        }
        if(flag==1) break;
    }
    ans--;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}