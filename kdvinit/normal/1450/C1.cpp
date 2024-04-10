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
            if(x=='.') a[i][j]=0;
            else a[i][j]=1;
        }
    }

    int cnt[3]={0};
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            int x = (i+j)%3;
            cnt[x]+=a[i][j];
        }
    }

    int req=0;
    for(int i=0;i<3;i++)
    {
        if(cnt[i]<=cnt[req]) req=i;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==0) { cout<<"."; continue; }
            int x = (i+j)%3;
            if(x==req) cout<<"O";
            else cout<<"X";
        }
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