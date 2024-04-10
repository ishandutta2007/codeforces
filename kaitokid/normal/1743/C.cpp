#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[200009][2];
ll a[200009],n;
string s;
ll go(int x,int u)
{
    if(x==n)return 0;
    if(dp[x][u]!=-1)return dp[x][u];
    if(s[x]=='0')return dp[x][u]=go(x+1,0);
    dp[x][u]=a[x]+go(x+1,1);
    if(u==0)
        dp[x][u]=max(dp[x][u],a[x-1]+go(x+1,0));
    return dp[x][u];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {

     cin>>n;
     cin>>s;
     for(int i=0;i<n;i++){cin>>a[i];dp[i][0]=dp[i][1]=-1;}
     cout<<go(0,1)<<endl;
    }

    return 0;
}