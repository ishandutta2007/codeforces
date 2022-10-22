#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int dx[]={-1,0,0,1},dy[]={0,-1,1,0};
int n,m,R[1505][1505],C[1505][1505];
bool b[1505][1505];
char c[1505][1505];
bool dfs(int x,int y)
{
    int u=(x%n+n)%n,v=(y%m+m)%m,i;
    if(c[u][v]=='#')return 0;
    if(b[u][v])return R[u][v]!=x||C[u][v]!=y;
    b[u][v]=1;
    R[u][v]=x;
    C[u][v]=y;
    for(i=0;i<4;i++)if(dfs(x+dx[i],y+dy[i]))return 1;
    return 0;
}
int main()
{
    int i,j;
    while(cin>>n>>m)
    {
        for(i=0;i<n;i++)scanf("%s",c[i]);
        for(i=0;i<n;i++)for(j=0;j<m;j++)b[i][j]=R[i][j]=C[i][j]=0;
        for(i=0;i<n;i++)for(j=0;j<m;j++)if(c[i][j]=='S')if(dfs(i+n,j+m))printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}