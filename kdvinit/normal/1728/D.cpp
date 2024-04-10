/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

void solve()
{
    string s; cin>>s;
    int n = s.size();

    char a[n+1];
    for(int i=1; i<=n; i++) a[i]=s[i-1];

    int dp[n+1][n+1];       //1 = win, 0 = draw, -1=loss
    memset(dp, 0, sizeof(dp));

    for(int i=1; i<n; i++)
    {
        if(a[i]==a[i+1]) dp[i][i+1]=0;
        else dp[i][i+1]=1;
    }

    for(int l=4; l<=n; l+=2)
    {
        for(int i=1; i+l-1<=n; i++)
        {
            int j = i+l-1;
            char w = a[i];
            char x = a[i+1];
            char y = a[j-1];
            char z = a[j];

            int cntw = 0;
            int cntd = 0;
            int cntl = 0;

            //Alice takes w
            // w x . . . . . y z
            if(dp[i+2][j]==-1) cntl++;
            else if(dp[i+1][j-1]==-1) cntl++;
            else if(x<w && dp[i+2][j]==0) cntl++;
            else if(z<w && dp[i+1][j-1]==0) cntl++;
            else if(x==w && dp[i+2][j]==0) cntd++;
            else if(z==w && dp[i+1][j-1]==0) cntd++;
            else cntw++;

            //Alice takes z
            // w x . . . . . y z
            if(dp[i][j-2]==-1) cntl++;
            else if(dp[i+1][j-1]==-1) cntl++;
            else if(y<z && dp[i][j-2]==0) cntl++;
            else if(w<z && dp[i+1][j-1]==0) cntl++;
            else if(y==z && dp[i][j-2]==0) cntd++;
            else if(w==z && dp[i+1][j-1]==0) cntd++;
            else cntw++;

            if(cntw>0) dp[i][j]=1;
            else if(cntd>0) dp[i][j]=0;
            else dp[i][j]=-1;
        }
    }

    if(dp[1][n]==1) cout<<"Alice"<<endl;
    if(dp[1][n]==0) cout<<"Draw"<<endl;
    if(dp[1][n]==-1) cout<<"Bob"<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}