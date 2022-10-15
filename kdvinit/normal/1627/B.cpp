/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m;
    cin>>n>>m;

    vector<int> ans;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            int tmp = abs(i-1) + abs(j-1);
            tmp = max(tmp, abs(i-1) + abs(j-m));
            tmp = max(tmp, abs(i-n) + abs(j-m));
            tmp = max(tmp, abs(i-n) + abs(j-1));
            ans.push_back(tmp);
        }
    }

    sort(ans.begin(), ans.end());
    for(int x: ans) cout<<x<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}