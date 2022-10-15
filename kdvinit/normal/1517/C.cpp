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

    int a[n+2][n+2];

    for(int i=1; i<=n+1; i++)
    {
        for(int j=1; j<=n+1; j++)
        {
            a[i][j]=0;
            if(i==n+1) a[i][j]=1;
        }
    }

    for(int i=1; i<=n; i++) cin>>a[i][i];

    for(int i=n; i>0; i--)
    {
        int x = a[i][i];
        int curi = i, curj=i;

        int tmp = x-1;
        while(tmp--)
        {
            if(a[curi+1][curj]==0) curi++;
            else curj--;

            a[curi][curj]=x;
        }
    }


    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=i; j++) cout<<a[i][j]<<" ";
        cout<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}