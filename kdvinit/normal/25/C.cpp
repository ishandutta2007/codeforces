/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 301;
int d[N][N];
int n;

void update()
{
    int a, b, ab;
    cin>>a>>b>>ab;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            d[i][j] = min(d[i][j], d[i][a]+ab+d[b][j]);
            d[i][j] = min(d[i][j], d[i][b]+ab+d[a][j]);
        }
    }
}

void print_sum()
{
    int sum=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++) sum+=d[i][j];
    }
    cout<<sum<<" ";
}

void solve()
{
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++) cin>>d[i][j];
    }

    int k;
    cin>>k;
    while(k--)
    {
        update();
        print_sum();
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}