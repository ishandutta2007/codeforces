#include<bits/stdc++.h>
using namespace std;
constexpr int MAX_N=5e5;
constexpr int BLOCK_SIZE=500;
int n,m;
int fa[MAX_N];
int op[BLOCK_SIZE],x[BLOCK_SIZE],y[BLOCK_SIZE];
map<pair<int,int>,int> id;
int tote;
bool able[MAX_N];
bool ask[MAX_N];
bool vis[MAX_N];
pair<int,int> edge[MAX_N];
int head[MAX_N];
int cnt;
int to[MAX_N];
int nxt[MAX_N];
int ind[MAX_N];
int que[MAX_N];
int find(int x){
    while(fa[x]>=0&&fa[fa[x]]>=0){
        x=fa[x]=fa[fa[x]];
    }
    return fa[x]<0?x:fa[x];
}
void insertEdge(int u,int v,int x){
    nxt[cnt]=head[u];
    to[cnt]=v;
    ind[cnt]=x;
    head[u]=cnt++;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    int last=0;
    for(int step=0;step*BLOCK_SIZE<m;++step){
        cnt=0;
        for(int i=0;i<n;++i){
            fa[i]=-1;
            head[i]=-1;
        }
        int tot=min(BLOCK_SIZE,m-step*BLOCK_SIZE);
        for(int i=0;i<tot;++i){
            cin>>op[i]>>x[i]>>y[i];
            --x[i];
            --y[i];
            if(x[i]>y[i]){
                swap(x[i],y[i]);
            }
            if(op[i]==1){
                if(!id.count({x[i],y[i]})){
                    edge[tote]={x[i],y[i]};
                    id[{x[i],y[i]}]=tote++;
                }
                ask[id[{x[i],y[i]}]]=true;
                int x0=(x[i]+1)%n,y0=(y[i]+1)%n;
                if(x0>y0){
                    swap(x0,y0);
                }
                if(!id.count({x0,y0})){
                    edge[tote]={x0,y0};
                    id[{x0,y0}]=tote++;
                }
                ask[id[{x0,y0}]]=true;
            }
        }
        for(int i=0;i<tote;++i){
            int u=find(edge[i].first);
            int v=find(edge[i].second);
            if(able[i]&&!ask[i]&&u!=v){
                if(fa[u]>fa[v]){
                    swap(u,v);
                }
                fa[u]+=fa[v];
                fa[v]=u;
            }
        }
        for(int i=0;i<tote;++i){
            int u=find(edge[i].first);
            int v=find(edge[i].second);
            if(ask[i]&&u!=v){
                insertEdge(u,v,i);
                insertEdge(v,u,i);
            }
        }
        for(int i=0;i<tot;++i){
            if(op[i]==1){
                int x0=(x[i]+last)%n;
                int y0=(y[i]+last)%n;
                if(x0>y0){
                    swap(x0,y0);
                }
                able[id[{x0,y0}]]^=1;
            }else{
                int l=0,r=0;
                int x0=find((x[i]+last)%n);
                int y0=find((y[i]+last)%n);
                que[r++]=x0;
                vis[x0]=true;
                while(l<r){
                    int u=que[l++];
                    for(int j=head[u];j!=-1;j=nxt[j]){
                        if(able[ind[j]]&&!vis[to[j]]){
                            vis[to[j]]=true;
                            que[r++]=to[j];
                        }
                    }
                }
                if(vis[y0]){
                    last=1;
                    cout<<1;
                }else{
                    last=0;
                    cout<<0;
                }
                for(int j=0;j<r;++j){
                    vis[que[j]]=false;
                }
            }
        }
        memset(ask,false,sizeof(ask));
    }
    cout<<endl;
    return 0;
}