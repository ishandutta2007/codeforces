#include<bits/stdc++.h>
using namespace std;
const int mn=2e5+10;
vector<int>g[mn],w[mn],in[mn];
queue<int>q;
bool vis[mn];
int rem[mn];
int ans[mn];
int main(){
    int n,m,i;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a].push_back(b);
        g[b].push_back(a);
        rem[a]+=c,rem[b]+=c;
        w[a].push_back(c);
        w[b].push_back(c);
        in[a].push_back(i);
        in[b].push_back(-i);
    }
    q.push(1);
    vis[1]=1;
    while(q.size()){
        int x=q.front();
        q.pop();
        for(i=0;i<g[x].size();i++){
            int y=g[x][i];
            if(vis[y])continue;
            rem[y]-=2*w[x][i];
            if(y!=n&&rem[y]==0){
                q.push(y);
                vis[y]=1;
            }
            ans[abs(in[x][i])]=(in[x][i]<0);
        }
    }
    for(i=1;i<=m;i++)printf("%d\n",ans[i]);
}