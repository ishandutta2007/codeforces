// luogu remote judge
#include<bits/stdc++.h>
using namespace std;
const long long INF=1e18;
class segtree{
private:
    int sz;
    vector<long long>val;
public:
    segtree(int _sz){
        sz=1;
        while(sz<_sz){
            sz<<=1;
        }
        val.assign(sz<<1,INF);
    }
    void modify(int p,int l,int r,int s,int t,long long x){
        if(l>=t||r<=s){
            return;
        }
        if(l>=s&&r<=t){
            val[p]=min(val[p],x);
            return;
        }
        modify(p<<1,l,(l+r)>>1,s,t,x);
        modify(p<<1|1,(l+r)>>1,r,s,t,x);
    }
    void modify(int s,int t,long long x){
        modify(1,0,sz,s,t,x);
    }
    long long queryval(int p,int l,int r,int pos){
        if(r-l==1){
            return val[p];
        }
        if(pos<((l+r)>>1)){
            return min(val[p],queryval(p<<1,l,(l+r)>>1,pos));
        }
        return min(val[p],queryval(p<<1|1,(l+r)>>1,r,pos));
    }
    long long queryval(int pos){
        return queryval(1,0,sz,pos);
    }
};
int main(){
    int n,m,q;
    scanf("%d%d%d",&n,&m,&q);
    vector<vector<int>>edge(n);
    vector<tuple<int,int,int>>edges(m);
    for(int i=0;i<m;++i){
        scanf("%d%d%d",&get<0>(edges[i]),&get<1>(edges[i]),&get<2>(edges[i]));
        --get<0>(edges[i]);
        --get<1>(edges[i]);
        edge[get<0>(edges[i])].push_back(i);
        edge[get<1>(edges[i])].push_back(i);
    }
    vector<long long>d1(n,INF),d2(n,INF);
    vector<int>pre1(n,-1),pre2(n,-1);
    auto dijkstra=[&](int s,vector<long long> &d,vector<int> &pre){
        priority_queue<pair<long long,int>>que;
        d[s]=0;
        que.push({0,s});
        while(!que.empty()){
            auto x=que.top();
            que.pop();
            int u=x.second;
            if(d[u]!=-x.first){
                continue;
            }
            for(auto &e:edge[u]){
                int v=get<0>(edges[e])+get<1>(edges[e])-u;
                int w=get<2>(edges[e]);
                if(d[v]>d[u]+w){
                    d[v]=d[u]+w;
                    pre[v]=e;
                    que.push({-d[v],v});
                }
            }
        }
    };
    dijkstra(0,d1,pre1);
    dijkstra(n-1,d2,pre2);
    vector<bool>used(m);
    long long sp=d1[n-1];
    for(int i=0;i<m;++i){
        int u=get<0>(edges[i]);
        int v=get<1>(edges[i]);
        int w=get<2>(edges[i]);
        if(min(d1[u],d1[v])+min(d2[u],d2[v])+w==sp){
            used[i]=true;
        }
    }
    vector<bool>cut(m);
    vector<int>dfn(n,-1),low(n,-1);
    int dfs_clock=0;
    function<void(int,int)> tarjan=[&](int u,int f){
        dfn[u]=dfs_clock++;
        low[u]=dfn[u];
        for(auto &e:edge[u]){
            if(used[e]){
                int v=get<0>(edges[e])+get<1>(edges[e])-u;
                if(dfn[v]==-1){
                    tarjan(v,e);
                    low[u]=min(low[u],low[v]);
                    if(low[v]>dfn[u]){
                        cut[e]=true;
                    }
                }else if(f!=e){
                    low[u]=min(low[u],dfn[v]);
                }
            }
        }
    };
    tarjan(0,-1);
    for(int i=0;i<n;++i){
        if(pre1[i]!=-1&&!cut[pre1[i]]){
            stack<int>stk;
            int e=-1;
            for(int u=i,v;;u=v){
                stk.push(u);
                if(pre1[u]==-1||cut[pre1[u]]){
                    e=pre1[u];
                    break;
                }
                v=get<0>(edges[pre1[u]])+get<1>(edges[pre1[u]])-u;
            }
            while(!stk.empty()){
                pre1[stk.top()]=e;
                stk.pop();
            }
        }
        if(pre2[i]!=-1&&!cut[pre2[i]]){
            stack<int>stk;
            int e=-1;
            for(int u=i,v;;u=v){
                stk.push(u);
                if(pre2[u]==-1||cut[pre2[u]]){
                    e=pre2[u];
                    break;
                }
                v=get<0>(edges[pre2[u]])+get<1>(edges[pre2[u]])-u;
            }
            while(!stk.empty()){
                pre2[stk.top()]=e;
                stk.pop();
            }
        }
    }
    vector<int>pos(m,-1);
    int tot=0;
    for(int u=0;pre2[u]!=-1;++tot){
        pos[pre2[u]]=tot;
        u=max(get<0>(edges[pre2[u]]),get<1>(edges[pre2[u]]),[&](int u,int v){return d1[u]<d1[v];});
    }
    for(int i=0;i<n;++i){
        if(pre1[i]!=-1){
            pre1[i]=pos[pre1[i]];
        }
        if(pre2[i]!=-1){
            pre2[i]=pos[pre2[i]];
        }else{
            pre2[i]=tot;
        }
    }
    segtree t(tot);
    for(int i=0;i<m;++i){
        if(!used[i]){
            int u=get<0>(edges[i]);
            int v=get<1>(edges[i]);
            int w=get<2>(edges[i]);
            t.modify(pre1[u]+1,pre2[v],d1[u]+w+d2[v]);
            t.modify(pre1[v]+1,pre2[u],d1[v]+w+d2[u]);
        }
    }
    while(q--){
        int x,y;
        scanf("%d%d",&x,&y);
        --x;
        int u=get<0>(edges[x]);
        int v=get<1>(edges[x]);
        int w=get<2>(edges[x]);
        if(d1[u]>d1[v]){
            swap(u,v);
        }
        if(y==w){
            printf("%I64d\n",sp);
        }else if(y<w){
            printf("%I64d\n",min(sp,d1[u]+y+d2[v]));
        }else if(!cut[x]){
            printf("%I64d\n",sp);
        }else{
            printf("%I64d\n",min(sp+y-w,t.queryval(pos[x])));
        }
    }
    return 0;
}