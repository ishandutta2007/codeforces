#include <bits/stdc++.h>
using namespace std;
int dp[509][509][2][2];
int go(int u ,int v,int r,int z)
{
    if((u==0)&&(v==0)&&(r==0))return 0;
    int &rt=dp[u][v][r][z];
    if(rt!=-1)return rt;
    rt=1e9;
    if(u>0)rt=min(rt,1-go(u-1,v+1,r,0));
    if(v>0)rt=min(rt,1-go(u,v-1,r,0));
    if(r>0)rt=min(rt,1-go(u,v,r-1,0));
    if((z==0)&&(v>0))rt=min(rt,-go(u,v,r,1));
    return rt;
}
int main()
{
    memset(dp,-1,sizeof dp);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string s;
        cin>>n>>s;
        int u=0,v=0;
        for(int i=0;i<(n/2);i++)
            {
                if((s[i]=='1')&&(s[n-i-1]=='1'))continue;
                if(s[i]==s[n-1-i])u++;
                else v++;
            }
            int r=0;
            if((n%2)&&(s[n/2]=='0'))r=1;
          int ans=go(u,v,r,0);
          if(ans<0){cout<<"ALICE\n";continue;}
          if(ans>0){cout<<"BOB\n";continue;}
          if(ans==0){cout<<"DRAW\n";}
    }
}