#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int>pii;
mt19937 rng(chrono::system_clock::now().time_since_epoch().count());
mt19937_64 rngll(rng());
const int mn=1e4+10;
const ll mod=1e9+7;
vector<pii>g[mn];
bool vis[mn],val[mn];
int hail[mn][2],ed[mn];
int tot;
vector<int>one;

void dfs(int x,int p){
    vis[x]=1;
    for(pii idk:g[x])if(idk.first!=p&&vis[idk.first]){
        if(val[x]==val[idk.first]){
            tot++;
            hail[x][1]++;
            hail[idk.first][1]--;
            one.push_back(idk.second);
        }
        else{
            hail[x][0]++;
            hail[idk.first][0]--;
        }
    }
    for(pii idk:g[x])if(idk.first!=p&&!vis[idk.first]){
        ed[idk.first]=idk.second;
        val[idk.first]=val[x]^1;
        dfs(idk.first,x);
        hail[x][0]+=hail[idk.first][0];
        hail[x][1]+=hail[idk.first][1];
    }

}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        g[a].push_back({b,i+1});
        g[b].push_back({a,i+1});
    }
    for(int i=1;i<=n;i++)if(!vis[i])dfs(i,0);
    if(!tot){
        printf("%d\n",m);
        for(int i=1;i<=m;i++)printf("%d ",i);
        return 0;
    }
    vector<int>ans;
    for(int i=1;i<=n;i++)if(ed[i]){
        assert(hail[i][0]>=0&&hail[i][1]>=0);
        if(hail[i][0]==0&&hail[i][1]==tot)ans.push_back(ed[i]);
    }
    if(tot==1)for(int x:one)ans.push_back(x);
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int x:ans)printf("%d ",x);
}