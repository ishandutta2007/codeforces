#include<bits/stdc++.h>
using namespace std;
string s[2010];
bool g[2010][2010];
int num[2010][2010];
void dfs(int r,int c);
void add(int r,int c){
    g[r][c]=1;
    num[r][c]++;
    if(r)num[r-1][c]++;
    if(c)num[r][c-1]++;
    if(r&&c)num[r-1][c-1]++;
    if(num[r][c]==3)dfs(r,c);
    if(r&&num[r-1][c]==3)dfs(r-1,c);
    if(c&&num[r][c-1]==3)dfs(r,c-1);
    if(r&&c&&num[r-1][c-1]==3)dfs(r-1,c-1);
}
void dfs(int r,int c){
    if(!g[r][c])add(r,c);
    else if(!g[r+1][c])add(r+1,c);
    else if(!g[r][c+1])add(r,c+1);
    else if(!g[r+1][c+1])add(r+1,c+1);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++){
        g[i][j]=s[i][j]=='.';
        if(!g[i][j])continue;
        num[i][j]++;
        if(i)num[i-1][j]++;
        if(j)num[i][j-1]++;
        if(i&&j)num[i-1][j-1]++;
    }
    for(int i=0;i<n-1;i++)for(int j=0;j<m-1;j++)if(num[i][j]==3)dfs(i,j);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            printf("%c",g[i][j]?'.':'*');
        }
        printf("\n");
    }

}