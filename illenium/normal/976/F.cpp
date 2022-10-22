#include<bits/stdc++.h>
#define maxn 4005
#define INF 0x3f3f3f3f
using namespace std;

struct edge{
    int to,cap,rev,id;
    edge(int a = 0,int b = 0,int c = 0,int d = 0){
        to = a,cap = b,rev = c,id = d;
    }
};

bool visit[maxn];
int indg[maxn],level[maxn],iter[maxn],n1,n2,m,s,t,store[maxn];
vector<edge> graph[maxn];
vector<edge> standard[maxn];

void add_e(int from,int to,int cap,int id){
    graph[from].push_back(edge(to,cap,graph[to].size(),id));
    graph[to].push_back(edge(from,0,graph[from].size() - 1,id));
}
void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> que;
    level[s] = 0;
    que.push(s);
    while(que.size()){
        int v = que.front();
        que.pop();
        for(int i = 0;i < graph[v].size();++i){
            edge& e = graph[v][i];
            if(e.cap > 0 && level[e.to] < 0){
                level[e.to] = level[v] + 1;
                que.push(e.to);
            }
        }
    }
}
int dfs(int v,int t,int f){
    if(v == t) return f;
    for(int& i = iter[v];i < graph[v].size();++i){
        edge& e = graph[v][i];
        if(e.cap > 0 && level[v] < level[e.to]){
            int d = dfs(e.to,t,min(f,e.cap));
            if(d > 0){
                e.cap -= d;
                graph[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t){
    int flow = 0;
    while(true){
        bfs(s);
        if(level[t] < 0) return flow;
        memset(iter,0,sizeof(iter));
        int f;
        while((f = dfs(s,t,INF)) > 0){
            flow += f;
        }
    }
}

int main()
{
	scanf("%d%d%d",&n1,&n2,&m);
    s = 0,t = n1 + n2 + 1;
    for(int i = 0;i < m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        v += n1;
        ++indg[u],++indg[v];
        standard[u].push_back(edge(v,1,standard[v].size(),i + 1));
        standard[v].push_back(edge(u,0,standard[u].size() - 1,i + 1));
    }
    int mdg = maxn;
    for(int i = 1;i <= n1 + n2;++i)
        mdg = min(mdg,indg[i]);
    printf("0\n");
    for(int k = 1;k <= mdg;++k){
        for(int v = 0;v < maxn;++v) graph[v].clear();
        for(int i = 1;i <= n1 + n2;++i){
            for(int j = 0;j < standard[i].size();++j)
                graph[i].push_back(standard[i][j]);
        }
        for(int i = 1;i <= n1;++i) add_e(s,i,indg[i] - k,-1);
        for(int i = n1 + 1;i <= n1 + n2;++i) add_e(i,t,indg[i] - k,-1);
        max_flow(s,t);
        memset(visit,false,sizeof(visit));
        int cnt = 0;
        for(int i = n1 + 1;i <= n1 + n2;++i){
            for(int j = 0;j < graph[i].size();++j){
                edge& e = graph[i][j];
                if(e.cap && e.to != t){
                    visit[e.id] = true;
                    ++cnt;
                }
            }
        }
        printf("%d",m - cnt);
        for(int i = 1;i <= m;++i){
            if(!visit[i]) printf(" %d",i);
        }
        printf("\n");
    }
    return 0;
}