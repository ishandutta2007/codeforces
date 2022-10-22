#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=998244353;
ll dp[300009];
ll pw[300009];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
pw[0]=1;
for(int i=1;i<300004;i++)
    pw[i]=(2*pw[i-1])%mod;
dp[0]=dp[1]=0;
for(int i=2;i<300004;i++)
{
    dp[i]=(dp[i-1]+dp[i-2])%mod;
    dp[i]+=dp[i-2]+pw[i-2];
    dp[i]%=mod;
}
vector<string> s;
ll n,m,ans=0,w=0;
cin>>n>>m;
for(int i=0;i<n;i++)
{
    string x;
    cin>>x;
    s.push_back(x);
    for(int j=0;j<m;j++)if(s[i][j]=='o')w++;
}
for(int i=0;i<n;i++)
{
    ll p=0;
    for(int j=0;j<m;j++)
    {
        if(s[i][j]=='o'){p++;continue;}

   ans+=dp[p]*pw[w-p];
   ans%=mod;
   p=0;
    }
   ans+=dp[p]*pw[w-p];
   ans%=mod;
}
for(int j=0;j<m;j++)
{
    ll p=0;
    for(int i=0;i<n;i++)
    {
        if(s[i][j]=='o'){p++;continue;}

   ans+=dp[p]*pw[w-p];
   ans%=mod;
   p=0;
    }
   ans+=dp[p]*pw[w-p];
   ans%=mod;
}
cout<<ans;
    return 0;
}