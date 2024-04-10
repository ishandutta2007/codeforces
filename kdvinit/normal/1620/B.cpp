/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

int get_ar(int h)
{
    int k; cin>>k;
    int a[k+1];

    for(int i=1; i<=k; i++) cin>>a[i];
    sort(a+1, a+k+1);

    return(h*(a[k]-a[1]));
}

void solve()
{
    int w, h;
    cin>>w>>h;

    int ans=0;
    ans = max(ans, get_ar(h));
    ans = max(ans, get_ar(h));
    ans = max(ans, get_ar(w));
    ans = max(ans, get_ar(w));

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}