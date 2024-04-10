#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
const ll mod=1e9+7;
const int mn=1e3+10;
string s[mn];
bool vis[mn][mn];
int n,m;
bool gud(int r,int c){
    return 0<=r&&r<n&&0<=c&&c<m&&!vis[r][c]&&s[r][c]=='#';
}
void dfs(int r,int c){
    vis[r][c]=1;
    if(gud(r+1,c))dfs(r+1,c);
    if(gud(r-1,c))dfs(r-1,c);
    if(gud(r,c+1))dfs(r,c+1);
    if(gud(r,c-1))dfs(r,c-1);
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)cin>>s[i];
    bool b=1;
    int fr=0,fc=0;
    for(int i=0;i<n;i++){
        bool f=1;
        for(int j=0;j<m;j++)f&=s[i][j]=='.';
        fr+=f;
        int num=(s[i][0]=='#');
        for(int j=1;j<m;j++){
            if(s[i][j-1]=='.'&&s[i][j]=='#')num++;
        }
        if(num>=2)b=0;
    }
    for(int i=0;i<m;i++){
        bool f=1;
        for(int j=0;j<n;j++)f&=s[j][i]=='.';
        fc+=f;
        int num=(s[0][i]=='#');
        for(int j=1;j<n;j++){
            if(s[j-1][i]=='.'&&s[j][i]=='#')num++;
        }
        if(num>=2)b=0;
    }
    if(!b){
        printf("-1");
        return 0;
    }
    if((fr&&!fc)||(fc&&!fr)){
        printf("-1");
        return 0;
    }
    int ans=0;
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)if(gud(i,j))ans++,dfs(i,j);
    printf("%d",ans);
}