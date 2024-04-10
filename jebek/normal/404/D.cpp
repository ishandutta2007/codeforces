#include <iostream>
#include<algorithm>
#include<string>

using namespace std;

const int MOD=1000000007;
string s;
long long dp[1000100][5];

int main()
{
    cin>>s;
    if(s[0]=='0' || s[0]=='?')
        dp[0][0]=1;
    if(s[0]=='1' || s[0]=='?')
    {
        if(0<s.size()-1)
            dp[0][3]=1;
    }
    if(s[0]=='2' || s[0]=='?')
    {
        dp[0][2]=0;
    }
    if(s[0]=='*' || s[0]=='?')
    {
        dp[0][4]=1;
    }
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='0' || s[i]=='?')
            dp[i][0]=(dp[i-1][0]+dp[i-1][1])%MOD;
        if(s[i]=='1' || s[i]=='?')
        {
            dp[i][1]=dp[i-1][4];
            if(i<s.size()-1)
                dp[i][3]=(dp[i-1][0]+dp[i-1][1])%MOD;
        }
        if(s[i]=='2' || s[i]=='?')
        {
            if(i<s.size()-1)
                dp[i][2]=dp[i-1][4];
        }
        if(s[i]=='*' || s[i]=='?')
        {
            dp[i][4]=(dp[i-1][3]+dp[i-1][2]+dp[i-1][4])%MOD;
        }
       // cout<<i<<"*"<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<" "<<dp[i][4]<<endl;
    }
    cout<<(dp[s.size()-1][0]+dp[s.size()-1][1]+dp[s.size()-1][2]+dp[s.size()-1][3]+dp[s.size()-1][4])%MOD<<endl;
}