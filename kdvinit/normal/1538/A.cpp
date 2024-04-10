/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int p1, pn;
    for(int i=1; i<=n; i++)
    {
        int x; cin>>x;
        if(x==1) p1=i;
        if(x==n) pn=i;
    }

    int ans1 = max(p1, pn);
    int ans2 = max(n+1-p1, n+1-pn);
    int ans3 = n+1-p1 + pn;
    int ans4 = n+1-pn + p1;

    int ans = min(ans1, ans2);
    ans = min(ans, ans3);
    ans = min(ans, ans4);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}