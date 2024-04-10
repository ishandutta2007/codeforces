/*
K.D. Vinit  /,,/
*/
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl "\n"

bool solve()
{
    int n, m, k;
    cin>>n>>m>>k;
    k++;

    int a[n+2][m+2];
    memset(a, 0, sizeof(a));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            char x; cin>>x;
            if(x=='*') a[i][j]=1;
        }
    }

    int dp1[n+2][m+2];
    memset(dp1, 0, sizeof(dp1));

    int dp2[n+2][m+2];
    memset(dp2, 0, sizeof(dp2));

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]==0) continue;
            dp1[i][j]=dp1[i-1][j-1]+1;
            dp2[i][j]=dp2[i-1][j+1]+1;
        }
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            if(a[i][j]==0) continue;

            int pos=0;
            for(int h=0; 1; h++)
            {
                int i2=i+h;
                int j2=j-h;
                if(a[i2][j2]==0) break;
                int l = min(dp1[i2][j2], dp2[i2][j2]);
                if(l>=(h+1) && l>=k) { pos=1; break; }
            }

            if(pos==1) continue;

            for(int h=0; 1; h++)
            {
                int i2=i+h;
                int j2=j+h;
                if(a[i2][j2]==0) break;
                int l = min(dp1[i2][j2], dp2[i2][j2]);
                if(l>=(h+1) && l>=k) { pos=1; break; }
            }

            if(pos==1) continue;

            return false;
        }
    }

    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t; cin>>t;
    while(t--)
    {
        if(solve()) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}