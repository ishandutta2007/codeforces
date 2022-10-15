/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,m;
    cin>>n>>m;

    char a[n+1][n+1];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++) cin>>a[i][j];
    }

    if(m%2==1)
    {
        cout<<"YES"<<endl;
        for(int i=1;i<=m+1;i++)
        {
            if(i%2==1) cout<<1<<" ";
            else cout<<2<<" ";
        }
        cout<<endl;

        return;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            if(a[i][j]==a[j][i])
            {
                cout<<"YES"<<endl;
                for(int k=1;k<=m+1;k++)
                {
                    if(k%2==1) cout<<i<<" ";
                    else cout<<j<<" ";
                }
                cout<<endl;

                return;
            }
        }
    }

    if(n==2) { cout<<"NO"<<endl; return; }
    
    cout<<"YES"<<endl;

    if(a[1][2]==a[2][3] && a[2][3]==a[3][1])
    {
        for(int i=1;i<=m+1;i++)
        {
            if(i%3==1) cout<<1<<" ";
            if(i%3==2) cout<<2<<" ";
            if(i%3==0) cout<<3<<" ";
        }
        cout<<endl;

        return;
    }

    if(m%4==0)
    {
        int p;
        if(a[1][2]!=a[1][3]) p=1;
        if(a[2][1]!=a[2][3]) p=2;
        if(a[3][1]!=a[3][2]) p=3;

        int q=p%3+1;
        int r=q%3+1;

        for(int i=1;i<=m+1;i++)
        {
            if(i%4==1) cout<<p<<" ";
            if(i%4==2) cout<<q<<" ";
            if(i%4==3) cout<<p<<" ";
            if(i%4==0) cout<<r<<" ";
        }
        cout<<endl;

        return;
    }
    else
    {
        int p;
        if(a[1][2]!=a[1][3]) p=1;
        if(a[2][1]!=a[2][3]) p=2;
        if(a[3][1]!=a[3][2]) p=3;

        int q=p%3+1;
        int r=q%3+1;

        cout<<q<<" ";
        for(int i=1;i<=m-1;i++)
        {
            if(i%4==1) cout<<p<<" ";
            if(i%4==2) cout<<q<<" ";
            if(i%4==3) cout<<p<<" ";
            if(i%4==0) cout<<r<<" ";
        }
        cout<<r<<" ";
        cout<<endl;

        return;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}