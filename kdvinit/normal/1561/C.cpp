/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    vector<array<int, 2>> mng;
    for(int i=1; i<=n; i++)
    {
        int k; cin>>k;
        int tmp = 0;
        for(int j=0; j<k; j++)
        {
            int x; cin>>x;
            x-=j;
            x++;
            tmp = max(tmp, x);
        }
        mng.push_back({tmp, k});
    }
    sort(mng.begin(), mng.end());

    int pow=0, ans=0;
    for(int i=0; i<n; i++)
    {
        pow -= mng[i][0];
        ans = min(ans, pow);
        pow += mng[i][0];
        pow += mng[i][1];
    }
    ans*=-1;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}