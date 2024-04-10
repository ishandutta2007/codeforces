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
    for(int i=1; i<=n; i++) cin>>a[i];

    map<int, int> mp;
    multiset<int> ms;
    for(int i=1; i<=n; i++) { mp[a[i]]++; ms.insert((a[i]-1)/2); }

    int ans = 0;
    for(int i=n; i>=1; i--)
    {
        if(mp[i]>0) ms.erase(ms.find((i-1)/2));
        else
        {
            ans++;
            int x = *ms.rbegin();
            ms.erase(ms.find(x));
            if(x<i) { cout<<-1<<endl; return; }
        }
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