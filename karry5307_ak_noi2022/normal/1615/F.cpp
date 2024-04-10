#include<cstdio>
#include<cmath>
using namespace std;
const long long mod=1000000007;
int n,t;
long long dp[2005][6005],num[2005][6005];
char a[2005],b[2005];
void trans(int x,int y,int A,int B)
{
    int Moves=0,Ny=0;
    if(A==B)
    {
        Ny=6000-y;
        if(y>=3000) Moves=2*(3000-Ny);
        else Moves=0;
    }
    if(A==0 && B==1)
    {
        Ny=6000-y-1;
        if(y>=3000) Moves=2*(3000-Ny)-1;
        else Moves=0;
    }
    if(A==1 && B==0)
    {
        Ny=6000-y+1;
        if(y>3000) Moves=2*(3000-Ny)+1;
        else Moves=0;
    }
//    printf("dp[%d][%d]=%lld  num[%d][%d]=%lld (%d,%d)->(%d,%d)\n",x,y,dp[x][y],x,y,num[x][y],x,y,x+1,Ny);
    dp[x+1][Ny]=(dp[x+1][Ny]+dp[x][y])%mod;
    num[x+1][Ny]=((num[x+1][Ny]+num[x][y])%mod+dp[x][y]*Moves%mod)%mod;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf(" %c",&a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            scanf(" %c",&b[i]);
        }   
        for(int i=0;i<=n+2;i++)
        {
            for(int j=3000-n-2;j<=3000+n+2;j++)
            {
                dp[i][j]=0;
                num[i][j]=0;
            }
        }
        dp[1][3000]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=3000-n-1;j<=3000+n+1;j++)
            {
                if(!dp[i][j]) continue;
                if((a[i]=='0' || a[i]=='?') && (b[i]=='0' || b[i]=='?'))
                {
                    trans(i,j,0,0);
                }
                if((a[i]=='0' || a[i]=='?') && (b[i]=='1' || b[i]=='?'))
                {
                    trans(i,j,0,1);
                }
                if((a[i]=='1' || a[i]=='?') && (b[i]=='0' || b[i]=='?'))
                {
                    trans(i,j,1,0);
                }
                if((a[i]=='1' || a[i]=='?') && (b[i]=='1' || b[i]=='?'))
                {
                    trans(i,j,1,1);
                }
            }
        }
        printf("%lld\n",num[n+1][3000]);
    }
}