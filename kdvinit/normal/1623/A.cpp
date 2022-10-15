/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int val (int x1, int x2, int n)
{
    if(x2>=x1) return (x2-x1);
    else return (2*n - x2 - x1);
}

void solve()
{
    int n, m, x1, y1, x2, y2;
    cin>>n>>m>>x1>>y1>>x2>>y2;

    int ans = min(val(x1, x2, n), val(y1, y2, m));
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}