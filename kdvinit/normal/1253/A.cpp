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

    int a[n+1],b[n+1];
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];

    int diff;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>b[i]) { cout<<"NO"<<endl; return; }
    }

    for(int i=1;i<=n;i++)
    {
        if(a[i]==b[i]) continue;

        diff=b[i]-a[i];
        int j=i;
        while(j<=n && b[j]-a[j]==diff) j++;

        for(int k=j;k<=n;k++)
        {
            if(a[k]!=b[k]) { cout<<"NO"<<endl; return; }
        }
        break;
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