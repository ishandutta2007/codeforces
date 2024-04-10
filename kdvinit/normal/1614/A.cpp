/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, l, r, k;
    cin>>n>>l>>r>>k;

    vector<int> a;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        if(x>=l && x<=r) a.push_back(x);
    }
    sort(a.begin(), a.end());

    int ans=0;
    for(int x: a)
    {
        k-=x;
        if(k<0) break;
        ans++;
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