/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m;
    cin>>n>>m;

    int a[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cin>>a[i][j];
    }

    int b[n+1][m+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) b[i][j]=4;;
    }

    for(int i=1;i<=n;i++)
    {
        b[i][1]=3;
        b[i][m]=3;
    }

    for(int j=1;j<=m;j++)
    {
        b[1][j]=3;
        b[n][j]=3;
    }

    b[1][1]=2;
    b[1][m]=2;
    b[n][1]=2;
    b[n][m]=2;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]>b[i][j])
            {
                cout<<"NO"<<endl;
                return;
            }
        }
    }

    cout<<"YES"<<endl;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cout<<b[i][j]<<" ";
        cout<<endl;
    }

}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}