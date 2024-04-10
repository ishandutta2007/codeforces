#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    int tmp=0,ans;

    if(n==1) { cout<<0<<endl; return; }

    tmp=sqrt(n);
    if(tmp*tmp>=n) ans= (tmp-1)+(tmp-1);
    else if( tmp*(tmp+1)>=n ) ans=(tmp-1)+(tmp+1-1);
    else ans=(tmp+1-1)+(tmp+1-1);

    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

    int t; cin>>t;
    while(t--) solve();

    return 0;
}