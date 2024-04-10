/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int n, m, k, x, y;
    cin>>n>>m>>k;

    for(int i=1; i<=k; i++) cin>>x>>y;
    for(int i=1; i<=k; i++) cin>>x>>y;

    vector<char> ans;
    for(int i=1; i<=n-1; i++) ans.push_back('U');
    for(int i=1; i<=m-1; i++) ans.push_back('L');

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(i%2) ans.push_back('R');
            else ans.push_back('L');
        }
        if(i!=n) ans.push_back('D');
    }

    cout<<ans.size()<<endl;
    for(char x: ans) cout<<x;
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}