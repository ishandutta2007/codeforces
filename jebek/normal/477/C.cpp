#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

string s,p;
long long dp[3000][3000],dp1[3000][3000];

int main()
{
    cin>>s>>p;
    for(long long i=0;i<s.size();i++)
        for(long long j=0;j<p.size();j++)
            dp[i][j]=-1;
    if(s[0]==p[0])
        dp[0][0]=0;
    for(long long i=1;i<s.size();i++)
    {
        dp[i][0]=dp[i-1][0];
        if(s[i]==p[0])
            dp[i][0]=i;
        for(long long j=1;j<p.size();j++)
        {
            dp[i][j]=dp[i-1][j];
            if(s[i]==p[j])
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
        //    cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<dp[i][0]<<endl;
        }
    }
    if(p.size()==1 && s[0]==p[0])
        dp1[0][0]=1;
    for(long long i=0;i<s.size();i++)
        for(long long j=0;j<=s.size();j++)
        {
            if(j>i+1)
            {
                dp1[i][j]=-1000000000;
                continue;
            }
            long long zero=0;
            dp1[i][j]=max(dp1[i-1][j],zero);
            if(dp[i][p.size()-1]>-1 && j>=(i-dp[i][p.size()-1]+1-p.size()))
            {
                if(dp[i][p.size()-1]-1>=0)
                    dp1[i][j]=max(dp1[i][j],dp1[dp[i][p.size()-1]-1][j-(i-dp[i][p.size()-1]+1-p.size())]+1);
                else if(i-j+1==p.size())
                    dp1[i][j]=max(dp1[i][j],zero+1);
            }
          //  cout<<i<<" "<<j<<" "<<dp1[i][j]<<endl;
          //  cout<<i<<" "<<j<<" "<<dp[i][j]<<" "<<dp1[i][j]<<" "<<dp[i][p.size()-1]-1<<" "<<(i-dp[i][p.size()-1]+1-p.size())<<endl;
        }
    for(long long i=0;i<=s.size();i++)
        cout<<dp1[s.size()-1][i]<<" ";
}