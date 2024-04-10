// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
void dfs(int u,vector<set<int>> &adj,deque<pair<int,int>> &que,bool opt){
    if(adj[u].empty()){
        return;
    }
    int v=*(adj[u].begin());
    if(opt){
        que.push_back({min(u,v),max(u,v)});
    }else{
        que.push_front({min(u,v),max(u,v)});
    }
    adj[u].erase(v);
    adj[v].erase(u);
    dfs(v,adj,que,opt);
}
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<set<int>> adj(n);
    set<pair<int,int>> edge;
    for(int i=0;i<m;++i){
        int u,v;
        scanf("%d%d",&u,&v);
        --u;
        --v;
        edge.insert({min(u,v),max(u,v)});
        adj[u].insert(v);
        adj[v].insert(u);
    }
    for(int i=0;i<n;++i){
        deque<pair<int,int>> que;
        dfs(i,adj,que,false);
        dfs(i,adj,que,true);
        if(!que.empty()){
            que.pop_front();
            for(;que.size()>1;){
                edge.erase(que.front());
                que.pop_front();
                que.pop_front();
            }
        }
    }
    printf("%u\n",edge.size());
    for(auto e:edge){
        printf("%d %d\n",e.first+1,e.second+1);
    }
    return 0;
}