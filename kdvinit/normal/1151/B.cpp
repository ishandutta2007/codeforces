/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void print(int c[], int n)
{
    cout<<"TAK"<<endl;
    for(int i=1; i<=n; i++) cout<<c[i]<<" ";
    cout<<endl;
}

void solve()
{
    int n, m;
    cin>>n>>m;

    int a[n+1][m+1];
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cin>>a[i][j];
    }

    int c[n+1], val=0;
    for(int i=1; i<=n; i++)
    {
        c[i]=1;
        val^=a[i][1];
    }

    if(val!=0)
    {
        print(c, n);
        return;
    }

    int dif=0;

    for(int i=1; i<=n; i++)
    {
        for(int j=2; j<=m; j++)
        {
            if(a[i][j]==a[i][1]) continue;
            c[i]=j;
            print(c, n);
            return;
        }
    }

    cout<<"NIE"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}