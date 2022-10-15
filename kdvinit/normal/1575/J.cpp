/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

const int N = 1005;
int a[N][N];
int n, m, k;
int cnt[N]={0};

int col(int c)
{
    int i=1;
    int j=c;

    while(1)
    {
        if(cnt[j]==n) return j;
        if(i==n+1) return j;
        if(a[i][j]==2) { i++; continue; }
        if(a[i][j]==1) { a[i][j]=2; cnt[j]++; j++; continue; }
        if(a[i][j]==3) { a[i][j]=2; cnt[j]++; j--; continue; }
    }
}

void solve()
{
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            cin>>a[i][j];
            if(a[i][j]==2) cnt[j]++;
        }
    }

    for(int i=1; i<=k; i++)
    {
        int x; cin>>x;
        cout<<col(x)<<" ";
    }
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}