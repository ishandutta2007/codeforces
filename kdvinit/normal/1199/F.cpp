/*
K.D. Vinit  |,,|
*/
#include <iostream>
#include <cmath>
#include<bits/stdc++.h>

using namespace std;
#define int long long

int a[51][51];
int dp[52][52][52][52];
int sir[51][51];    //sum_in_row
int sic[51][51];    //sum_in_column

int value(int c1,int c2,int c3,int c4)
{
    int temp=-1;
    int mxl=max(c2+1-c1,c4+1-c3);

    if(dp[c1][c2][c3][c4]!=-1)
    {
        //cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<": value -> "<<0<<endl;
        //cout<<"DP Used -> ";
        return dp[c1][c2][c3][c4];
    }

    for(int i=c1;i<=c2;i++)
    {
        if(sir[i][c3-1]!=sir[i][c4]) continue;

        //cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<": breaks at row -> "<<i<<endl;
        int x=dp[c1][i-1][c3][c4];
        int y=dp[i+1][c2][c3][c4];

        if(x==-1) x=value(c1,i-1,c3,c4);
        if(y==-1) y=value(i+1,c2,c3,c4);

        int temp2=x+y;
        if(temp==-1) temp=temp2;
        else temp=min(temp,temp2);
    }

    for(int j=c3;j<=c4;j++)
    {
        if(sic[c1-1][j]!=sic[c2][j]) continue;

        //cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<": breaks at column -> "<<j<<endl;
        int x=dp[c1][c2][c3][j-1];
        int y=dp[c1][c2][j+1][c4];

        if(x==-1) x=value(c1,c2,c3,j-1);
        if(y==-1) y=value(c1,c2,j+1,c4);

        int temp2=x+y;
        if(temp==-1) temp=temp2;
        else temp=min(temp,temp2);
    }

    temp=min(temp,mxl);
    if(temp!=-1)
    {
        //cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<": value -> "<<temp<<endl;
        dp[c1][c2][c3][c4]=temp;
        return temp;
    }
    else
    {
        //cout<<c1<<" "<<c2<<" "<<c3<<" "<<c4<<": value -> "<<mxl<<endl;
        dp[c1][c2][c3][c4]=mxl;
        return mxl;
    }
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            char x; cin>>x;
            if(x=='#') a[i][j]=1;
            else a[i][j]=0;
        }
    }

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            sir[i][j]=0;
            sic[i][j]=0;
        }
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            sir[i][j]=sir[i][j-1]+a[i][j];
        }
    }

    for(int j=1;j<=n;j++)
    {
        for(int i=1;i<=n;i++)
        {
            sic[i][j]=sic[i-1][j]+a[i][j];
        }
    }

    for(int i1=1;i1<=51;i1++)
    {
        for(int i2=1;i2<=51;i2++)
        {
            for(int i3=1;i3<=51;i3++)
            {
                for(int i4=1;i4<=51;i4++)
                {
                    if(i1>i2 || i3>i4) dp[i1][i2][i3][i4]=0;
                    else dp[i1][i2][i3][i4]=-1;
                }
            }
        }
    }

    int ans=value(1,n,1,n);
    cout<<ans<<endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}