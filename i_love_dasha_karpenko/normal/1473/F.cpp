#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int DIM = 3E3+7;
const ll INF = 1E9;
int A[DIM],start,finish;
struct edge{
    int v;
    ll flow,cap;
};
vector<edge> edges;
vector<int> G[DIM];
void add_edge(int a,int b,int cap){
    G[a].push_back(edges.size());
    G[b].push_back(edges.size()+1);
    edges.push_back({b,0,cap});
    edges.push_back({a,0,0});
}
ll sum = 0;
void readData(){
    int n;
    cin>>n;
    start = 0,finish = n+1;
    for(int i = 1;i<=n;++i){
        cin>>A[i];

    }
    for(int i = 1;i<=n;++i){
        set<int> S;
        for(int j = i-1;j>=1;--j){
            if (S.count(A[j])==0 && A[i]%A[j]==0){
                S.insert(A[j]);
                add_edge(i,j,INF);
            }
        }
    }
    for(int i = 1;i<=n;++i){
        int x;
        cin>>x;
        if (x<0)
            add_edge(i,finish,abs(x));
        else {
            add_edge(start, i, x);
            sum += x;
        }
    }
}
int vis[DIM];
void bfs(int start){
    vis[start] = 1;
    queue<int> Q;
    Q.push(start);
    while(!Q.empty()){
        int v = Q.front();
        Q.pop();
        for(int tn:G[v]){
            int to = edges[tn].v;
            if (vis[to]==0 && edges[tn].flow<edges[tn].cap){
                vis[to] = vis[v]+1;
                Q.push(to);
            }
        }
    }
}
int ptr[DIM];
ll dfs(int v,ll flow){
    if (flow==0)
        return 0;
    if (v==finish)
        return flow;
    for(;ptr[v]<G[v].size();++ptr[v]){
        int nv = G[v][ptr[v]];
        int to = edges[nv].v;
        if (vis[to]!=vis[v]+1)
            continue;
        int pushed = dfs(to,min(flow,edges[nv].cap-edges[nv].flow));
        if (pushed!=0){
            edges[nv].flow+=pushed;
            edges[nv^1].flow-=pushed;
            return pushed;
        }
    }
    return 0;
}
ll dinic(){
    ll res = 0;
    while(1){
        memset(vis,0,sizeof(vis));
        memset(ptr,0,sizeof(ptr));
        bfs(start);
        if (!vis[finish])
            break;
        while(int pushed = dfs(start,INF)){
            res+=pushed;
        }
    }
    return res;
}
int solve() {
    readData();
    cout<<sum-dinic()<<endl;
	return 1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int t;
	t = 1;
	while(t--)
		assert(solve());
}