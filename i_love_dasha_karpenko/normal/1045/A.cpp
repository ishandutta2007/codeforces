#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl '\n'
const int N = 15e4+7;
const int INF = 1e9+7;
int start,fin;
struct edge{
    int to,flow,cap;
};
vector<edge> edges;
vector<int> G[N];
void addedge(int a,int b,int cap){
    G[a].push_back(edges.size());
    edges.push_back({b,0,cap});
    G[b].push_back(edges.size());
    edges.push_back({a,0,0});
}
void get_edg(int t,int tl,int tr,int l,int r,int v,int flow){
    if (tl>r || l>tr)
        return;
    if (l<=tl && tr<=r){
        addedge(v,t,flow);
        return;
    }
    int tm = (tl+tr)>>1;
    get_edg(t+1,tl,tm,l,r,v,flow);
    get_edg(t+(tm-tl+1)*2,tm+1,tr,l,r,v,flow);
}
int ord[N];
void makefin(int t,int tl,int tr){
    if (tl==tr){
        addedge(t,fin,1);
        ord[t] = tl;
        return;
    }
    int tm = (tl+tr)>>1;
    addedge(t,t+1,INF);
    addedge(t,t+(tm-tl+1)*2,INF);
    makefin(t+1,tl,tm);
    makefin(t+(tm-tl+1)*2,tm+1,tr);
}
int dist[N],ptr[N],type[N];
queue<int> Q;
void bfs(int v){
    Q.push(v);
    dist[v] = 0;
    while(!Q.empty()){
        v = Q.front();
        Q.pop();
        for(int edg:G[v]){
            if (edges[edg].flow==edges[edg].cap)
                continue;
            int to = edges[edg].to;
            if (dist[to]==-1){
                dist[to] = dist[v]+1;
                Q.push(to);
            }
        }
    }
}
int dfs(int v,int flow){
    if (flow==0 || v==fin)
        return flow;
    for(;ptr[v]<G[v].size();++ptr[v]){
        int edg = G[v][ptr[v]];
        int to = edges[edg].to;
        if (dist[to]!=dist[v]+1)
            continue;
        int can = edges[edg].cap-edges[edg].flow;
        int ret = dfs(to,min(flow,can));
        if (ret){
            edges[edg].flow+=ret;
            edges[edg^1].flow-=ret;
            return ret;
        }
    }
    return 0;
}
int dinic(int root){
    int flow = 0;
    while(1) {
        for(int i = 0;i<=fin;++i){
            dist[i] = -1;
            ptr[i] = 0;
        }
        bfs(root);
        if (dist[fin]==-1)
            break;
        int pushed = dfs(root,INF);
        while(pushed){
            flow+=pushed;
            pushed = dfs(root,INF);
        }
    }
    return flow;
}
int ans[N],got[N];
vector<int> need[N];
void get_val(int t,int tl,int tr,vector<int> &V){
    if(tl==tr){
        if (!got[ord[t]])
            V.push_back(ord[t]);
        while(!need[t].empty() && !V.empty()){
            ans[need[t].back()] = V.back();
            need[t].pop_back();
            V.pop_back();
        }
        return;
    }
    int tm = (tl+tr)>>1;
    get_val(t+1,tl,tm,V);
    vector<int> V1;
    get_val(t+(tm-tl+1)*2,tm+1,tr,V1);
    for(int to:V1)
        V.push_back(to);
    while(!need[t].empty() && !V.empty()){
        ans[need[t].back()] = V.back();
        need[t].pop_back();
        V.pop_back();
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m;
    cin>>n>>m;
    start = 0,fin = n+m*2;

    for(int i = 1;i<=n;++i){

        cin>>type[i];
        if (type[i]==0){
            addedge(0,i,1);
            int len;
            cin>>len;
            for(int j = 0;j<len;++j){
                int pos;
                cin>>pos;
                get_edg(n+1,1,m,pos,pos,i,1);
            }
        }
        if (type[i]==1){
            addedge(0,i,1);
            int l,r;
            cin>>l>>r;
            get_edg(n+1,1,m,l,r,i,1);
        }
        if (type[i]==2){
            addedge(0,i,2);
            for(int c = 0;c<3;++c){
                int pos;
                cin>>pos;
                get_edg(n+1,1,m,pos,pos,i,1);
            }
        }
    }
    makefin(n+1,1,m);
    cout<<dinic(start)<<endl;
    for(int i = 1;i<=n;++i){
        if (type[i]==0){
            for(int edg:G[i]){
                if (edges[edg].flow<=0)
                    continue;
                int to = ord[edges[edg].to];
                if (!got[to]) {
                    ans[i] = to;
                    got[to] = i;
                }
            }
        }
        if (type[i]==2){
            int cnt = 2;
            for(int edg:G[i]){
                if (edges[edg].flow<=0)
                    continue;
                --cnt;
                int to = ord[edges[edg].to];
                if (got[to]){
                    ans[got[to]] = 0;
                }
                ans[i] = to;
                got[to] = i;
                cout<<i<<' '<<to<<endl;
            }
            for(int edg:G[i]){
                if (cnt<=0 || edges[edg].flow>0 || edges[edg].to==start)
                    continue;
                --cnt;
                int to = ord[edges[edg].to];
                if (got[to]){
                    ans[got[to]] = 0;
                }
                ans[i] = to;
                got[to] = i;
                cout<<i<<' '<<to<<endl;
            }
        }

    }
    for(int i = 1;i<=n;++i){
        if (type[i]==1){

            for(int edg:G[i]){
                if (edges[edg].flow<=0)
                    continue;
                need[edges[edg].to].push_back(i);
                break;
            }
        }
    }
    vector<int> V;
    get_val(n+1,1,m,V);
    for(int i = 1;i<=n;++i){
        if (type[i]<2 && ans[i]){
            cout<<i<<' '<<ans[i]<<endl;
        }
    }
    return 0;
}