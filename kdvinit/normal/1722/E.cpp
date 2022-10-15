/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1000;
int hw[N+1][N+1];

void solve()
{
    int n, q;
    cin>>n>>q;

    for(int i=1; i<=N; i++)
    {
        for(int j=0; j<=N; j++) hw[i][j]=0;
    }

    for(int i=1; i<=n; i++)
    {
        int h, w;
        cin>>h>>w;
        hw[h][w]+=w;
    }

    for(int i=1; i<=N; i++)
    {
        for(int j=1; j<=N; j++) hw[i][j]+=hw[i][j-1];
    }

    while(q--)
    {
        int h1, w1, h2, w2;
        cin>>h1>>w1>>h2>>w2;

        int ans=0;
        for(int i=h1+1; i<h2; i++)
        {
            int sumw = hw[i][w2-1] - hw[i][w1];
            int cur = (i*sumw);
            ans += cur;
        }

        cout<<ans<<endl;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}