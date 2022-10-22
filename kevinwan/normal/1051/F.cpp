#include<bits/stdc++.h>
using namespace std;
#define lastof(v) v[v.size()-1]
typedef long long ll;
typedef pair<int,int>pii;
typedef pair<ll,int>pli;
const int mn=1e5+10;
vector<int>g[mn];
vector<ll>w[mn];
vector<int> nums;
bool vis[mn];
int anc[mn][17];
ll dep[mn];
int d[mn];
void dfs(int x,int p){
    vis[x]=1;
    for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        if(y==p)continue;
        if(vis[y]){
            nums.push_back(x);
            nums.push_back(y);
        }
        else anc[y][0]=x,dep[y]=dep[x]+w[x][i],d[y]=d[x]+1,dfs(y,x);
    }
}
int go(int a,int b){
    for(int i=0;b;b>>=1,i++)if(b&1)a=anc[a][i];
    return a;
}
int lca(int a,int b){
    if(d[a]>d[b])a=go(a,d[a]-d[b]);
    else b=go(b,d[b]-d[a]);
    for(int i=16;i>=0;i--){
        if(anc[a][i]!=anc[b][i])a=anc[a][i],b=anc[b][i];
    }
    if(a!=b)return anc[a][0];
    else return a;
}
ll dis(int a,int b){
    return dep[a]+dep[b]-dep[lca(a,b)]*2;
}
vector<vector<ll>>ans;
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        g[a].push_back(b);
        g[b].push_back(a);
        w[a].push_back(c);
        w[b].push_back(c);
    }
    anc[1][0]=1;
    dfs(1,0);
    sort(nums.begin(),nums.end());
    nums.erase(unique(nums.begin(),nums.end()),nums.end());
    for(int i=1;i<17;i++)for(int j=1;j<=n;j++)anc[j][i]=anc[anc[j][i-1]][i-1];
    for(int u:nums){
        ans.push_back(vector<ll>(mn,0x3f3f3f3f3f3f3f3f));
        priority_queue<pli>pq;
        pq.push({0,u});
        while(pq.size()){
            int x=pq.top().second;
            ll v=-pq.top().first;
            pq.pop();
            if(lastof(ans)[x]<=v)continue;
            lastof(ans)[x]=v;
            for(int i=0;i<g[x].size();i++){
                pq.push({-(v+w[x][i]),g[x][i]});
            }
        }
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int u,v;
        scanf("%d%d",&u,&v);
        ll pr=dis(u,v);
        for(int i=0;i<ans.size();i++)pr=min(pr,ans[i][u]+ans[i][v]);
        printf("%lld\n",pr);
    }
}