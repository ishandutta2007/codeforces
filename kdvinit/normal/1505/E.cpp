/*
K.D. Vinit  |,,|
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int r, c;
    cin>>r>>c;

    int a[r+2][c+2];

    for(int i=1; i<=r+1; i++)
    {
        for(int j=1; j<=c+1; j++)
        {
            if(i==r+1 || j==c+1) { a[i][j]=-1; continue; }

            char x; cin>>x;
            if(x=='.') a[i][j]=0;
            else a[i][j]=1;
        }
    }

    int pr = 1, pc = 1;
    int ans = 0;
    while(1)
    {
        ans+=a[pr][pc];
        if(pr==r && pc==c) break;
        if(a[pr][pc+1]==-1) { pr++; continue;}
        if(a[pr+1][pc]==-1) { pc++; continue;}
        if(a[pr+1][pc]==1) { pr++; continue;}
        if(a[pr][pc+1]==1) { pc++; continue;}
        pc++;
    }
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}