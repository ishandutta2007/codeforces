/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, A, B;
    cin>>n>>A>>B;
    int a[n+1];
    for(int i=1; i<=n; i++) { char x; cin>>x; a[i]=x-'0'; }
    int cnt=1;
    for(int i=2; i<=n; i++) { if(a[i]!=a[i-1]) cnt++; }
    cnt = (cnt/2)+1;
    int ans = n*A;
    if(B<0) ans+=(cnt*B);
    else ans+=(n*B);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}