#include<cstdio>
#include<vector>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
int n,m,k,u,v,cost;
bool vis[110000],used[110000];
ll dis[110000];
vector<pii> vec[110000];
queue<int> que;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;i++){
        scanf("%d%d%d",&u,&v,&cost);
        vec[u].push_back(make_pair(v,cost));
        vec[v].push_back(make_pair(u,cost));
    }
    memset(dis,0x3f,sizeof(dis));
    que.push(1); dis[1]=0; vis[1]=true;
    for (int i=1;i<=k;i++){
        scanf("%d%d",&v,&cost);
        if (cost<dis[v]){
            dis[v]=cost; vis[v]=1;
            used[v]=1; que.push(v);
        }
    }
    while (!que.empty()){
        int u=que.front(); que.pop();
        vis[u]=0; int sz=vec[u].size();
        for (int i=0;i<sz;i++){
            int v=vec[u][i].first,w=vec[u][i].second;
            if (dis[v]>=dis[u]+w){
                dis[v]=dis[u]+w;
                used[v]=false;
                if (!vis[v]){
                    vis[v]=true;
                    que.push(v);
                }
            }
        }
    }
    int ans=0;
    for (int i=1;i<=n;i++)
        if (used[i]) ans++;
    printf("%d\n",k-ans);
    return 0;
}