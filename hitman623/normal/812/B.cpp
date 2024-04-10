#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
using namespace std;

int main()
{
    long n,m,i,j,p,ans=1e9,c,pp[20],cur,dp[20][2]={0},mm;
    string s[20];
    cin>>n>>m;
    for(i=0;i<n;++i)
    cin>>s[i];
    for(i=0;i<n;++i)
    for(j=1;j<=m;++j)
    if(s[i][j]=='1')
    dp[i][0]=j;
    for(i=0;i<n;++i)
    for(j=m;j>=1;--j)
    if(s[i][j]=='1')
    dp[i][1]=m-j+1;
    pp[0]=1;
    for(i=1;i<=n;++i)
    pp[i]=2*pp[i-1];
    mm=n-1;
    for(i=0;i<n;++i)
    if(dp[i][0]==0) mm--;
    else break;
    if(mm<0) {cout<<0;exit(0);}
    p=(1<<(mm));
    cur=0;
    for(i=0;i<p;++i)
    {
        c=0;
        cur=0;
        for(j=0;j<mm;++j)
        {
            if(pp[j]&i)
            {
                if(cur==0)
                c+=m+2;
                else c+=2*dp[n-1-j][1]+1;
                cur=1;
            }
            else
            {
                if(cur==1)
                c+=m+2;
                else c+=2*dp[n-1-j][0]+1;
                cur=0;
            }
        }
        if(cur==0)
        c+=dp[n-1-j][0];
        else c+=dp[n-1-j][1];
        ans=min(ans,c);
    }
    cout<<ans;
    return 0;
}