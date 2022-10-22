#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int dp[2009][2009];
int a[2009];
int go(int x,int d)
{
    if((x==0)&& (d==0))return 0;
    if((x==0)||(d<0))return -10000000;
    if(dp[x][d]!=-1)return dp[x][d];
    return dp[x][d]=max(go(x-1,d)+(a[x]==x-d),go(x-1,d-1));
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=0;i<=n+1;i++)
            for(int j=0;j<=n+1;j++)dp[i][j]=-1;
        for(int i=1;i<=n;i++)cin>>a[i];
        int res=-1;
        for(int i=0;i<=n;i++)
        {
            if(go(n,i)>=k){res=i;break;}
        }
        cout<<res<<endl;
    }
    return 0;
}