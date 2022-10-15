/*
K.D. Vinit  /,,/
Problem - C
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int sum2(int n)
{
    int ans = (n*(n+1))/2;
    return ans;
}

void solve()
{
    int n;
    cin>>n;

    int k[n+1], h[n+1];
    for(int i=1; i<=n; i++) cin>>k[i];
    for(int i=1; i<=n; i++) cin>>h[i];

    vector<pair<int, int>> pos;
    for(int i=1; i<=n; i++)
    {
        int cur = k[i]-h[i]+1;
        pos.push_back({cur, i});
    }
    sort(pos.begin(), pos.end());

    int ans = 0, strt=0, lst=0;
    for(auto x: pos)
    {
        int cur = x.first;
        int i = x.second;

        if(cur<=lst) lst=max(lst, k[i]);
        else
        {
            int len = lst-strt+1;
            if(strt!=0) ans += sum2(len);
            strt = cur;
            lst = k[i];
        }
    }

    int len = lst-strt+1;
    if(strt!=0) ans += sum2(len);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}