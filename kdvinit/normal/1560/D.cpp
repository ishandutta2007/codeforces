/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mx = 1e18;

int value(string a, string b)
{
    int n = a.size();
    int m = b.size();

    int i, j=0;
    for(i=0; i<n; i++)
    {
        while(j<m && b[j]!=a[i]) j++;
        if(j==m) break;
        j++;
    }

    int cost = (n-i) + (m-i);
    return cost;
}

void solve()
{
    int n;
    cin>>n;

    string nn = to_string(n);
    string xx;

    int x=1;
    int ans = 1000;

    while(x<=mx)
    {
        xx = to_string(x);
        int tmp = value(xx, nn);
        ans = min(ans, tmp);
        x*=2;
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