#include <bits/stdc++.h>

using namespace std;
const int mn=1e5+10;
int p[mn];
bool vis[mn];
vector<vector<int>> c[mn];
vector<pair<int,int>>ans;
vector<int> g[mn];
void connect(int a,int b){
    int i;
    for(i=0;i<max(a,b);i++){
        ans.push_back({c[a][0][i%a],c[b][0][i%b]});
    }
}
void dfs(int x){
    vis[x]=1;
    for(int y:g[x]){
        if(vis[y]||!c[y].size())continue;
        connect(x,y);
        dfs(y);
    }
}
int main()
{
    int n,i,j,k;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",p+i);
    for(i=1;i<=n;i++)for(j=i*2;j<=n;j+=i)g[i].push_back(j),g[j].push_back(i);
    for(i=1;i<=n;i++){
        if(vis[i])continue;
        int x=i;
        vector<int>v;
        while(!vis[x]){
            vis[x]=1;
            v.push_back(x);
            x=p[x];
        }
        c[v.size()].push_back(v);
    }
    if(c[1].size()){
        for(i=1;i<=n;i++)if(i!=c[1][0][0])ans.push_back({c[1][0][0],i});
    }
    else if(c[2].size()){
        ans.push_back({c[2][0][0],c[2][0][1]});
        for(i=2;i<=n;i+=2){
            for(j=0;j<c[i].size();j++){
                if(i==2&&j==0)continue;
                for(k=0;k<i;k++){
                    ans.push_back({c[2][0][k&1],c[i][j][k]});
                }
            }
        }
    }
    if(ans.size()==n-1){
        printf("YES\n");
        for(auto p:ans)printf("%d %d\n",p.first,p.second);
    }
    else printf("NO");
}