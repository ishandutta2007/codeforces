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

    int a[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char x; cin>>x;
            int y=x-48;
            a[i][j]=y;
        }
    }

    int v0=0,v1=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char x; cin>>x;
            int y=x-48;
            a[i][j]^=y;
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            int tmp=a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1];
            if(tmp%2==1) { cout<<"NO"<<endl; return; }
        }
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