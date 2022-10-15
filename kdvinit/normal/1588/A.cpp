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

    int a[n+1], b[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) cin>>b[i];

    sort(a+1, a+n+1);
    sort(b+1, b+n+1);

    for(int i=1; i<=n; i++)
    {
        int dif = b[i]-a[i];
        if(dif==0 || dif==1) continue;
        cout<<"NO"<<endl;
        return;
    }

    cout<<"YES"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}