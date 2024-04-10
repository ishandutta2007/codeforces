#include<bits/stdc++.h>
using namespace std;
const int dx[]={-1,0,1,0};
const int dy[]={0,-1,0,1};
int grid[550][550];
int n;
void dfs(int x,int y,int num,int &lft)
{
    if(!lft)
        return ;
    lft--;
    grid[x][y]=num;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(ny>nx)
            continue;
        if(nx<1||ny<1||nx>n||ny>n)
            continue;
        if(grid[nx][ny])
            continue;
        dfs(nx,ny,num,lft);
    }
    return ;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        dfs(i,i,x,x);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
            cout<<grid[i][j]<<" ";
        puts("");
    }
    return 0;
}