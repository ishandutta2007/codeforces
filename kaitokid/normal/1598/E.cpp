#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,q;
ll dp[1009][1009][2],ans,r;
bool bl[1009][1009];
void go(int x,int y,int u,ll z)
{
    if( x<1 || y<1 || bl[x][y])return;
    ans+=z;
    dp[x][y][u]+=z;
    if(u==0)go(x,y-1,1,z);
    else go(x-1,y,0,z);

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>q;
    ans=0;
    r=n*m;
    for(int i=n;i>=1;i--)
        for(int j=m;j>=1;j--)
    {
        dp[i][j][0]=1+dp[i+1][j][1];
        dp[i][j][1]=1+dp[i][j+1][0];
        ans+=dp[i][j][0]+dp[i][j][1];
    }
   // cout<<ans<<" "<<r<<endl;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        if(!bl[x][y])
        {
            go(x,y,0,-dp[x][y][0]);
            go(x,y,1,-dp[x][y][1]);
            bl[x][y]=true;
            r--;
            cout<<ans-r<<endl;
            continue;
        }
        bl[x][y]=0;
        go(x,y,0,1+dp[x+1][y][1]);
        go(x,y,1,1+dp[x][y+1][0]);
        r++;
        cout<<ans-r<<endl;
    }
    return 0;
}