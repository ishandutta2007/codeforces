#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100009][34],n,k;
ll dp[100009][34];
ll go(int x,int u)
{
    if(x==n || u==32)return 0;
    if(dp[x][u]!=-1)return dp[x][u];
     return dp[x][u]=max(a[x][u+1]+go(x+1,u+1),a[x][u]+go(x+1,u)-k);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=0;i<n;i++){cin>>a[i][0];dp[i][0]=-1;for(int j=1;j<=32;j++){a[i][j]=(a[i][j-1]/2);dp[i][j]=-1;}}
        cout<<go(0,0)<<endl;
        }


    return 0;

}