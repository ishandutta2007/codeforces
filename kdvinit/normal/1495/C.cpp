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
        for(int j=1;j<=m;j++)
        {
            char x; cin>>x;
            if(x=='X') a[i][j]=1;
            else a[i][j]=0;
        }
    }

    for(int i=1;i<=n;i+=3)
    {
        for(int j=1;j<=m;j++) a[i][j]=1;
    }

    for(int i=1;i<=n;i+=3)
    {
        int ind = 1;
        if( (i+2)>n ) break;
        if(n%3==0 && i+2 == n) break;
        for(int j=1;j<=m;j++)
        {
            if(a[i+1][j]==1) ind = j;
            if(a[i+2][j]==1) ind = j;
        }
        a[i+1][ind]=1;
        a[i+2][ind]=1;
    }

    if(n%3==0)
    {
        for(int j=1; j<=m; j++) a[n][j]=1;

        int cnt=0;
        for(int j=1; j<=m; j++) cnt+=a[n-1][j];

        int fur=1;
        if(cnt==0)
        {
            a[n-1][1]=1;
            fur=0;
        }

        if(fur==1)
        {
            int lst;
            for(int j=1; j<=m; j++)
            {
                if(a[n-1][j]==1) { lst=j; break; }
            }

            for(int j=lst+1; j<=m; j++)
            {
                if(a[n-1][j]==1)
                {
                    a[n][lst+1]=0;
                    lst=j;
                }
            }
        }
    }

    /*
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    */

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1) cout<<'X';
            else cout<<'.';
        }
        cout<<endl;
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}