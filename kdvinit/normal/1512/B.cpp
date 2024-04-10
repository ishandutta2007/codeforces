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

    char a[n+1][n+1];
    vector<int> x, y;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            if(a[i][j]=='*')
            {
                x.push_back(i);
                y.push_back(j);
            }
        }
    }

    int ax1, ax2, ay1, ay2;
    if(x[0]==x[1])
    {
        ax1 = x[0];
        ax2 = ax1%n+1;
    }
    else
    {
        ax1 = x[0];
        ax2 = x[1];
    }

    if(y[0]==y[1])
    {
        ay1 = y[0];
        ay2 = ay1%n+1;
    }
    else
    {
        ay1 = y[0];
        ay2 = y[1];
    }

    a[ax1][ay1]='*';
    a[ax1][ay2]='*';
    a[ax2][ay1]='*';
    a[ax2][ay2]='*';

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) cout<<a[i][j];
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