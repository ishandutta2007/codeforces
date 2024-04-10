/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int cnt(int n, int x)
{
    n++;
    int l = n/x;
    int m = (n-(l*x));
    int ans = (l/2)*x;
    if(l%2==1) ans+=m;
    return ans;
}

void solve()
{
    int l, r;
    cin>>l>>r;

    int tot = r-l+1;
    int ans = tot-1;

    //if(tot==1)  { cout<<0<<endl; return; }

    int p2=1;
    while(p2<=r)
    {
        int tmp = cnt(r, p2) - cnt(l-1, p2);
        tmp = tot-tmp;
        ans=min(ans, tmp);
        p2*=2;
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