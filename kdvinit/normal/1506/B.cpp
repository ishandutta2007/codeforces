/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, k;
    cin>>n>>k;

    char a[n+1];
    for(int i=1; i<=n; i++) cin>>a[i];

    int strt=1;
    int nd=n;

    while(a[strt]=='.') strt++;
    while(a[nd]=='.') nd--;

    if(strt==nd)
    {
        cout<<1<<endl;
        return;
    }

    int ans=2;
    for(int i=strt; i<=nd; i++)
    {
        if(i+k>=nd) break;

        ans++;
        int j=i+k;
        while(a[j]=='.') j--;
        i=j-1;
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