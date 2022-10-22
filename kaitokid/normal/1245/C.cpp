#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod =1e9+7;
ll dp[200009];
int main()
{
    ios::sync_with_stdio(0);
dp[0]=1;
dp[1]=1;
for(int i=2;i<=100000;i++)dp[i]=(dp[i-1]+dp[i-2])%mod;
string s;
cin>>s;
ll ans=1, u=0,n=0;
for(int i=0;i<s.size();i++)
{
    if(s[i]=='u')u++;else {ans=(ans*dp[u])%mod;u=0;}
 if(s[i]=='n')n++;else {ans=(ans*dp[n])%mod;n=0;}
if(s[i]=='m'||s[i]=='w'){cout<<0;return 0;}
}
ans=(ans*dp[u])%mod;
ans=(ans*dp[n])%mod;
cout<<ans;
    return 0;
}