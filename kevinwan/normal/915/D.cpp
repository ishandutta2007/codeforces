#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int mn=5e2+10;
int ban,a[100001],b[100001];
bool vis[mn],ins[mn],cyc;
vector<int> g[mn];
vector<pii> idk;
int fl=0;
void dfs2(int x){
    vis[x]=ins[x]=1;
    for(int y:g[x]){
        if(ins[y]){
            fl=y,idk.push_back({x,y});
            return;
        }
        if(!vis[y])dfs2(y);
        if(fl==-1)return;
        if(fl){
            if(x==fl)fl=-1;
            idk.push_back({x,y});
            return;
        }
    }
    ins[x]=0;
}
void dfs(int x){
    vis[x]=ins[x]=1;
    for(int y:g[x]){
        if((x==idk[ban].first&&y==idk[ban].second))continue;
        if(ins[y])cyc=1;
        if(!vis[y])dfs(y);
    }
    ins[x]=0;
}
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,m,i;
    cin>>n>>m;
    for(i=0;i<m;i++){
        cin>>a[i]>>b[i];
        g[a[i]].push_back(b[i]);
    }
    for(i=1;i<=n;i++)if(!vis[i]&&fl==0)dfs2(i);
    if(idk.size()==0){
        printf("YES");
        return 0;
    }
    memset(ins,0,sizeof(ins));
    for(ban=0;ban<idk.size();ban++){
        memset(vis,0,sizeof(vis));
        cyc=0;
        for(i=1;i<=n;i++){
            if(!vis[i])dfs(i);
        }
        if(!cyc){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
}