#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n,m,c1,c2,c3,p[26],nex[100005][26],dp[255][255][255];
char s[100005];
int a[4][255];
void Min(int &x,int y)
{
    if(x==-1) x=y;
    else x=min(x,y);
}
void up(int i,int j,int k)
{
    int x=a[1][i],y=a[2][j],z=a[3][k];
    dp[i][j][k]=-1;
    if(i!=0&&dp[i-1][j][k]!=-1)
    {
        int t=dp[i-1][j][k];
        t=nex[t][x];
        if(t!=-1)
            Min(dp[i][j][k],t);
    }
    if(j!=0&&dp[i][j-1][k]!=-1)
    {
        int t=dp[i][j-1][k];
        t=nex[t][y];
        if(t!=-1)
            Min(dp[i][j][k],t);
    }
    if(k!=0&&dp[i][j][k-1]!=-1)
    {
        int t=dp[i][j][k-1];
        t=nex[t][z];
        if(t!=-1)
            Min(dp[i][j][k],t);
    }
}
void up1()
{
    for(int i=0;i<=c2;i++)
        for(int j=0;j<=c3;j++)
        up(c1,i,j);
}
void up2()
{
    for(int i=0;i<=c1;i++)
        for(int j=0;j<=c3;j++)
        up(i,c2,j);
}
void up3()
{
    for(int i=0;i<=c1;i++)
        for(int j=0;j<=c2;j++)
        up(i,j,c3);
}
int main()
{
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    memset(p,-1,sizeof(p));
    for(int i=n;i>=0;i--)
    {
        for(int j=0;j<26;j++)
            nex[i][j]=p[j];
        if(i==0) break;
        p[s[i]-'a']=i;
    }
    memset(dp,-1,sizeof(dp));
    dp[0][0][0]=0;
    while(m--)
    {
        char opt[5],c[5];
        int id;
        scanf("%s%d",opt,&id);
        if(opt[0]=='+')
        {
            scanf("%s",c);
            if(id==1)
                a[id][++c1]=c[0]-'a',up1();
            else if(id==2)
                a[id][++c2]=c[0]-'a',up2();
            else a[id][++c3]=c[0]-'a',up3();
        }
        else
        {
            if(id==1) c1--;
            else if(id==2) c2--;
            else c3--;
        }
        if(dp[c1][c2][c3]==-1)
            printf("NO\n");
        else printf("YES\n");
    }
}