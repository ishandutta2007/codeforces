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

    priority_queue<array<int, 2>> pq;

    int a[n+1];
    for(int i=1; i<=n; i++) { cin>>a[i]; pq.push({a[i], i}); }

    vector<array<int, 2>> ans;
    while(1)
    {
        auto x = pq.top(); pq.pop();
        auto y = pq.top(); pq.pop();

        if(y[0]==0) break;
        ans.push_back({x[1], y[1]});
        x[0]--;
        y[0]--;

        pq.push(x);
        pq.push(y);
    }

    cout<<ans.size()<<endl;
    for(auto x: ans) cout<<x[0]<<" "<<x[1]<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}