#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod=998244353;
ll dp[200009][2][2][2][2][2][2];
string s;
ll go(int x,bool mn1,bool mn2,bool mn3,int f1,int f2,int f3)
{
    if(x==s.size()) return (f1&f2&f3);
    if(dp[x][mn1][mn2][mn3][f1][f2][f3]!=-1)return dp[x][mn1][mn2][mn3][f1][f2][f3];
    dp[x][mn1][mn2][mn3][f1][f2][f3]=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<2;j++)
         for(int d=0;d<2;d++)
    {
        if((mn1==0)&&(i==1)&&(s[x]=='0'))continue;

        if((mn2==0)&&(j==1)&&(s[x]=='0'))continue;

        if((mn3==0)&&(d==1)&&(s[x]=='0'))continue;

        int u=(i^j),v=(i^d),q=(j^d);
        bool h=(s[x]=='1');
        dp[x][mn1][mn2][mn3][f1][f2][f3]+=
        go(x+1,mn1|((1-i)&h),
           mn2|((1-j)&h),mn3|((1-d)&h),f1|(u&v),f2|(u&q),f3|(v&q));
        dp[x][mn1][mn2][mn3][f1][f2][f3]%=mod;

    }

    return dp[x][mn1][mn2][mn3][f1][f2][f3];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    memset(dp,-1,sizeof dp);
    cout<<go(0,0,0,0,0,0,0);

    return 0;
}