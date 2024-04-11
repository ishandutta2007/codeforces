#include <cstdio>
#include <queue>
using namespace std;

int n,m;
vector<int> graph[3005];

int dist[3005][3005];

void bfs(int obj){
    bool vis[3005] = {};
    queue<int> q, d;
    q.push(obj);
    d.push(0);
    vis[obj] = 1;
    while (!q.empty()) {
        int qf = q.front();
        int df = d.front();
        q.pop();
        d.pop();
        dist[obj][qf] = df;
        for (auto &i : graph[qf]){
            if(vis[i]) continue;
            vis[i] = 1;
            q.push(i);
            d.push(df+1);
        }
    }
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i=0; i<m; i++) {
        int x,y;
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i=1; i<=n; i++) {
        bfs(i);
    }
    int s,e,x;
    int ns,ne,nx;
    int ret = m+1;
    scanf("%d %d %d %d %d %d",&s,&e,&x,&ns,&ne,&nx);
    if(dist[s][e] <= x && dist[ns][ne] <= nx){
        ret = min(ret,dist[s][e] + dist[ns][ne]);
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            int dist1 = dist[s][i] + dist[i][j] + dist[j][e];
            int dist2 = dist[ns][i] + dist[i][j] + dist[j][ne];
            if(dist1 <= x && dist2 <= nx){
                ret = min(ret,dist[s][i] + dist[i][j] + dist[j][e] + dist[ns][i] + dist[j][ne]);
            }
            dist1 = dist[e][i] + dist[i][j] + dist[j][s];
            if(dist1 <= x && dist2 <= nx){
                ret = min(ret,dist[e][i] + dist[i][j] + dist[j][s] + dist[ns][i] + dist[j][ne]);
            }
            // s - i - j - e
            // s' - i - j - e'
        }
    }
    printf("%d",max(m - ret,-1));
}