/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin>>n>>m;

    multiset<char> ms[m+1];
    char x;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cin>>x, ms[j].insert(x);
    }

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<=m; j++) cin>>x, ms[j].erase(ms[j].find(x));
    }


    for(int j=1; j<=m; j++) x=*ms[j].begin(), cout<<x;
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}