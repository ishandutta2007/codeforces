#include <cstdio>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

int n, m, k;
int ban[100005];
vector<int> graph[100005];
bool vis[100005];
int deg[100005];

int tdeg[100005];

bool trial(double t){
    memcpy(tdeg,deg,sizeof(deg));
    memset(vis,0,sizeof(vis));
    queue<int> q;
    int cnt = 0;
    for (int i=0; i<k; i++) {
        q.push(ban[i]);
        vis[ban[i]] = 1;
        cnt++;
    }
    while (!q.empty()) {
        int qf = q.front();
        q.pop();
        for (auto &i : graph[qf]){
            if(vis[i]) continue;
            tdeg[i]--;
            if(tdeg[i] <= t * deg[i]){
                vis[i] = 1;
                q.push(i);
                cnt++;
            }
        }
    }
    return cnt != n;
}

int main(){
    scanf("%d %d %d",&n,&m,&k);
    for (int i=0; i<k; i++) {
        scanf("%d",&ban[i]);
    }
    for (int i=0; i<m; i++) {
        int s, e;
        scanf("%d %d",&s,&e);
        deg[s]++;
        deg[e]++;
        graph[s].push_back(e);
        graph[e].push_back(s);
    }
    double s = 0, e = 1;
    for (int i=0; i<50; i++) {
        double m = (s+e)/2;
        if(trial(m)) s = m;
        else e = m;
    }
    trial(s - 1e-9);
    vector<int> ret;
    for (int i=1; i<=n; i++) {
        if(!vis[i]) ret.push_back(i);
    }
    printf("%d\n",(int)ret.size());
    for (auto &i : ret){
        printf("%d ",i);
    }
}