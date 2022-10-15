/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    int a, b, c;
    cin>>a>>b>>c;

    a+=c;
    b+=c;

    int x = min(a, b);

    int ans = x+x+1;
    ans = min(ans, a+b);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}