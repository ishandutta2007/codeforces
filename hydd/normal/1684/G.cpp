#include<bits/stdc++.h>
using namespace std;
int n,m,pos,a[1100],g[1100][1100],match[1100]; bool vis[1100];
bool dfs(int u){
    for (int v=1;v<=pos;v++)
        if (g[u][v]&&!vis[v]){
            vis[v]=true;
            if (!match[v]||dfs(match[v])){
                match[v]=u;
                return true;
            }
        }
    return false;
}
void print(int x,int y){ cout<<x+x+y<<' '<<x+y<<'\n';}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin>>n>>m;
    for (int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);

    pos=0;
    for (int i=1;i<=n;i++)
        if (a[i]<=m/3) pos=i;
    for (int i=pos+1;i<=n;i++)
        for (int j=1;j<=pos;j++)
            if (a[i]%a[j]==0&&a[i]+a[i]+a[j]<=m) g[i][j]=true;
    for (int i=pos+1;i<=n;i++){
        for (int j=1;j<=pos;j++) vis[j]=false;
        if (!dfs(i)){
            cout<<"-1\n";
            return 0;
        }
    }
    cout<<pos<<'\n';
    for (int j=1;j<=pos;j++) 
        if (match[j]) print(a[match[j]],a[j]);
        else print(a[j],a[j]);
    return 0;
}