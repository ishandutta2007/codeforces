/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n, m, h, v;
    cin>>n>>m>>h;
    v = ((n*m)/2)-h;

    if(n%2==1) h -= (m/2);
    if(m%2==1) v -= (n/2);

    if(h<0 || v<0) { cout<<"NO"<<endl; return; }

    if(h%2==1 || v%2==1) { cout<<"NO"<<endl; return; }

    cout<<"YES"<<endl;

    char ans[n+1][m+1];
    memset(ans, '?', sizeof(ans));

    if(n%2==1)
    {
        char x='a';
        for(int i=1; i<=m; i++)
        {
            ans[n][i]=x;
            i++;
            ans[n][i]=x;

            if(x=='a') x='b';
            else x='a';
        }
    }

    if(m%2==1)
    {
        char x='a';
        for(int i=1; i<=n; i++)
        {
            ans[i][m]=x;
            i++;
            ans[i][m]=x;

            if(x=='a') x='b';
            else x='a';
        }
    }

    int n2 = n/2;
    int m2 = m/2;

    for(int i=1; i<=n2; i++)
    {
        for(int j=1; j<=m2; j++)
        {
            char x = 'c';
            char y = 'd';
            int z = (i+j)%2;
            if(z==1) { x = 'e'; y = 'f'; }

            int ii = (i*2-1);
            int jj = (j*2-1);

            if(h!=0)
            {
                h--;
                h--;
                ans[ii][jj]=x;
                ans[ii][jj+1]=x;
                ans[ii+1][jj]=y;
                ans[ii+1][jj+1]=y;
            }
            else
            {
                ans[ii][jj]=x;
                ans[ii+1][jj]=x;
                ans[ii][jj+1]=y;
                ans[ii+1][jj+1]=y;
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++) cout<<ans[i][j];
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