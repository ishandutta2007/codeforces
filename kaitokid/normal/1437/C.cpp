#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[209],dp[209][509],n;
int go(int x,int tm)
{
   // cout<<x<<" "<<tm<<endl;
    if(x==n)return 0;
    if(tm>=2*n)return 1e8;
    if(dp[x][tm]!=-1)return dp[x][tm];
int ans1=abs(a[x]-tm)+go(x+1,tm+1);
int ans2=go(x,tm+1);
return dp[x][tm]=min(ans1,ans2);
}
int main()
{
    ios::sync_with_stdio(0);
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=2*n;j++)dp[i][j]=-1;
    cout<<go(0,1)<<endl;
    }
    return 0;
}