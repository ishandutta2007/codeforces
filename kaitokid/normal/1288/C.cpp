#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll mod=1e9+7;
ll dp[30][1009];
int n,m;
ll go(int x,int num)
{
    if(x==2*m)return 1;
    if(dp[x][num]>0)return dp[x][num];
    ll ans=0;
    for(int i=num;i<=n;i++)
        ans=(ans+go(x+1,i))%mod;
    return dp[x][num]=ans;
}
int main()
{
ios::sync_with_stdio(0);
cin>>n>>m;
cout<<go(0,1);
    return 0;
}