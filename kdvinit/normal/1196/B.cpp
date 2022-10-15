/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,k;
    cin>>n>>k;

    int a[n+1],tot=0;
    for(int i=1;i<=n;i++) { cin>>a[i]; tot+=a[i]; }

    if(tot%2!=k%2){  cout<<"NO"<<endl; return; }

    int ans[k+1],cnt=0,sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        if(sum%2==0) continue;
        sum=0;
        if(cnt==k-1)
        {
            cout<<"YES"<<endl;
            for(int j=1;j<=k-1;j++) cout<<ans[j]<<" ";
            cout<<n<<endl;
            return;
        }
        ans[++cnt]=i;
    }
    cout<<"NO"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}