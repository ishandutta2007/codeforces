#include <bits/stdc++.h>
using namespace std;
int nxt[2010],dp[2010][2010];
int main()
{
    int n,m,i,j;
    string s,p;
    cin>>s>>p;
    n=s.size(),m=p.size();
    s=" "+s;
    for(i=0;i<n;i++){
        int cur=0;
        for(j=i+1;j<=n;j++){
            if(s[j]==p[cur])cur++;
            if(cur==m)break;
        }
        nxt[i]=j;
    }
    memset(dp,0xc0,sizeof(dp));
    dp[0][0]=0;
    for(i=0;i<n;i++){
        for(j=0;j<=n;j++){
            if(j!=n)dp[i+1][j+1]=max(dp[i+1][j+1],dp[i][j]);
            dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
            if(nxt[i]!=n+1)dp[nxt[i]][j+m]=max(dp[nxt[i]][j+m],dp[i][j]+1);
        }
    }
    for(i=n;i>=0;i--)printf("%d ",dp[n][i]);
}