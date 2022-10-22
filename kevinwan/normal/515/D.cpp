#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=1e5+10;
bool g[2010][2010];
int ans[2010][2010];
int n,m;
void dfs(int r,int c){
    if(r<=0||r>n||c<=0||c>m)return;
    if(g[r][c])return;
    bool prop=0;
    if(g[r-1][c]&&g[r][c-1]&&g[r+1][c]&&!g[r][c+1]){
        ans[r][c]=1;
        ans[r][c+1]=2;
        g[r][c]=g[r][c+1]=prop=1;
    }
    if(g[r-1][c]&&g[r][c-1]&&!g[r+1][c]&&g[r][c+1]){
        ans[r][c]=3;
        ans[r+1][c]=4;
        g[r][c]=g[r+1][c]=prop=1;
    }
    if(g[r-1][c]&&!g[r][c-1]&&g[r+1][c]&&g[r][c+1]){
        ans[r][c]=2;
        ans[r][c-1]=1;
        g[r][c]=g[r][c-1]=prop=1;
    }
    if(!g[r-1][c]&&g[r][c-1]&&g[r+1][c]&&g[r][c+1]){
        ans[r][c]=4;
        ans[r-1][c]=3;
        g[r][c]=g[r-1][c]=prop=1;
    }
    if(prop)for(int i=r-2;i<=r+2;i++)for(int j=c-2;j<=c+2;j++)dfs(i,j);
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin>>n>>m;
    int i,j;
    memset(g,1,sizeof(g));
    for(i=1;i<=n;i++){
        string s;
        cin>>s;
        for(j=0;j<m;j++){
            g[i][j+1]=(s[j]=='*');
        }
    }
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)dfs(i,j);
    bool suc=1;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)suc&=g[i][j];
    if(!suc)printf("Not unique");
    else{
        for(i=1;i<=n;i++){
            for(j=1;j<=m;j++){
                if(ans[i][j]==0)printf("*");
                else if(ans[i][j]==1)printf("<");
                else if(ans[i][j]==2)printf(">");
                else if(ans[i][j]==3)printf("^");
                else printf("v");
            }
            printf("\n");
        }
    }
}