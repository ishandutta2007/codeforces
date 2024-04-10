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

    int a[n+1], b[n+1]={0};

    int cnta=0;
    int cntb=0;
    int cntdif=0;

    for(int i=1; i<=n; i++) { cin>>a[i]; cnta+=a[i]; }
    for(int i=1; i<=n; i++) { cin>>b[i]; cntb+=b[i]; }
    for(int i=1; i<=n; i++) if(a[i]!=b[i]) cntdif++;

    int ans = abs(cnta-cntb);
    if(ans!=cntdif) ans++;
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}