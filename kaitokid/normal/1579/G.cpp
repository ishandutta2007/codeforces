#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[10009];
int n,mx;
int dp[2009][10009];
int go(int x,int u)
{
    if(u==n)return 1;
    if(dp[x][u]!=-1)return dp[x][u];
    if(x+a[u]<=mx && go(x+a[u],u+1))return dp[x][u]=1;
    if(x-a[u]>=0 && go(x-a[u],u+1))return dp[x][u]=1;
    return dp[x][u]=0;

}
bool ch(int x)
{
    for(int i=0;i<=x;i++)
        for(int j=0;j<=n;j++)dp[i][j]=-1;
    mx=x;
    for(int i=0;i<=x;i++)
        if(go(i,0))return true;
    return false;
}
int main() {
ios::sync_with_stdio(0);
cin.tie(0);
int t;
cin>>t;
while(t--)
{
    cin>>n;
    int mx=0;
    for(int i=0;i<n;i++){cin>>a[i];mx=max(mx,a[i]);}
    int l=1,r=2*mx;
    while(l<r)
    {
        int mid=(l+r)/2;
        if(ch(mid))r=mid;
        else l=mid+1;

    }
    cout<<l<<endl;

}
return 0;
}