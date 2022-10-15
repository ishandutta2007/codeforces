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

    int p[n+1];
    for(int i=1;i<=n;i++) cin>>p[i];

    int ans[n+1];
    int cnt=n;

    int mx=0;
    for(int i=1;i<=n;i++)
    {
        mx=p[i];
        int j=i;
        while(i<=n && p[i]<=p[j]) i++;
        i--;
        for(int k=i;k>=j;k--)
        {
            ans[cnt]=p[k];
            cnt--;
        }
    }

    for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}