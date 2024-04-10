/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,x;
    cin>>n>>x;

    int a[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];

    int mx=35*n;
    int b[mx+1],cnt[mx+1];
    for(int i=1;i<=n;i++)
    {
        b[i]=a[i];
        cnt[i]=1;
    }

    int ind=n,i=1;
    while(i<=ind)
    {
        if(b[i]%x!=0) break;
        int y=b[i]/x;
        ind++;
        b[ind]=y;
        cnt[ind]=(x*cnt[i]);
        i++;
    }

    int ans=0;
    for(int i=1;i<=ind;i++) ans+=(b[i]*cnt[i]);
    cout<<ans<<endl;

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}