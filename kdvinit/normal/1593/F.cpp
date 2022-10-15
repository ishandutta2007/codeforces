/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve()
{
    int n, a, b;
    cin>>n>>a>>b;

    int s[n+1];
    for(int i=1; i<=n; i++)
    {
        char x; cin>>x;
        s[i] = (x-'0');
    }

    bool dp[n+1][n+1][a][b];     //bool - (len)(len r)(mod a)(mod b)
    memset(dp, 0, sizeof(dp));

    dp[0][0][0][0]=1;

    int prv[n+1][n+1][a][b];
    int pa[n+1][n+1][a][b];
    int pb[n+1][n+1][a][b];

    memset(prv, 0, sizeof(prv));

    for(int i=1; i<=n; i++)
    {
        int x = s[i];
        for(int j=0; j<i; j++)
        {
            for(int ma=0; ma<a; ma++)
            {
                for(int mb=0; mb<b; mb++)
                {
                    if(dp[i-1][j][ma][mb]==0) continue;
                    int ma2 = (ma*10+x)%a;
                    int mb2 = (mb*10+x)%b;
                    dp[i][j+1][ma2][mb]=1;  prv[i][j+1][ma2][mb]=1; pa[i][j+1][ma2][mb]=ma;
                    dp[i][j][ma][mb2]=1; pb[i][j][ma][mb2]=mb;
                }
            }
        }
    }

    int ans = n+1;
    int ind = 0;

    for(int i=1; i<n; i++)
    {
        if(dp[n][i][0][0]==0) continue;
        int tmp = abs(i-(n-i));
        if(tmp<ans)
        {
            ans=tmp;
            ind=i;
        }
    }

    if(ans>n) { cout<<-1<<endl; return; }

    char col[n+1];

    int rl=ind, ma=0, mb=0;
    for(int i=n; i>=1; i--)
    {
        int x = prv[i][rl][ma][mb];
        int y = s[i];

        if(x==0) col[i]='B';
        else col[i]='R';

        if(x==1) { ma = pa[i][rl][ma][mb]; rl--; }
        else mb = pb[i][rl][ma][mb];
    }

    for(int i=1; i<=n; i++) cout<<col[i];
    cout<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}