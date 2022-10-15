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

    vector<array<int, 2>> inc, dec;

    for(int i=1; i<=n; i++)
    {
        int x, y;
        cin>>x>>y;

        if(x<y) inc.push_back({-y, i});
        else dec.push_back({y, i});
    }

    sort(inc.begin(), inc.end());
    sort(dec.begin(), dec.end());

    if(inc.size()>dec.size())
    {
        cout<<inc.size()<<endl;
        for(auto x: inc) cout<<x[1]<<" ";
        cout<<endl;
    }
    else
    {
        cout<<dec.size()<<endl;
        for(auto x: dec) cout<<x[1]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}