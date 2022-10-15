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

    int p[n+1], q[n+1];
    for(int i=1; i<=n; i++) cin>>p[i];

    vector<pair<int, int>> q0, q1;
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        if(x=='0') q0.push_back({p[i], i});
        else q1.push_back({p[i], i});
    }

    sort(q0.begin(), q0.end());
    sort(q1.begin(), q1.end());

    int cnt=0;
    for(auto x: q0) q[x.second]=++cnt;
    for(auto x: q1) q[x.second]=++cnt;

    for(int i=1; i<=n; i++) cout<<q[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}