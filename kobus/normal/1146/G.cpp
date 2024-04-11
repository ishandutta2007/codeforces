#include <bits/stdc++.h>
using namespace std;
#define INF 1'000'000'001
#define f first
#define s second
#define eps 1e-6
#define pb push_back
#define pii pair<int,int>
#define one 1
#define int long long
#define mp make_pair
#define ld long double
#define MAXN 112345


//0 indexed, i am stupid
//verified

int n,src,dst;
int dis[MAXN],q[MAXN],work[MAXN];
struct edge{int to,rev;int f,cap;};
vector<edge> are[MAXN];

vector<pair<pii,int>> to_make;

void dinic_add(int s,int t,int cap){
    are[s].pb((edge){t,(int)are[t].size(),0,cap});
    are[t].pb((edge){s,(int)are[s].size()-1,0,0});
}

void dinic_clear(){
    for(int i=0;i<n;i++)are[i].clear();
}

void dinic_make(){
    for(auto i:to_make)dinic_add(i.f.f,i.f.s,i.s);
}

void dinic_delete(){
    to_make.pop_back();
}

void dinic_put(int a,int b,int c){
    to_make.pb(mp(mp(a,b),c));
}

bool dinic_bfs(){
    fill(dis,dis+n,-1);dis[src]=0;
    int qt=0;q[qt++]=src;
    for(int qh=0;qh<qt;qh++){
        int u=q[qh];
        for(int i=0;i<are[u].size();i++){
            edge &e=are[u][i];int v=are[u][i].to;
            if(dis[v]<0&&e.f<e.cap)dis[v]=dis[u]+1,q[qt++]=v;
        }
    }
    return dis[dst]>=0;
}

int dinic_dfs(int u, int f){
    if(u==dst)return f;
    for(int &i=work[u];i<are[u].size();i++){
        edge &e=are[u][i];
        if(e.cap<=e.f)continue;
        int v=e.to;
        if(dis[v]==dis[u]+1){
            int df=dinic_dfs(v,min(f,e.cap-e.f));
            if(df>0){
                e.f+=df;
                are[v][e.rev].f-=df;
                return df;
            }
        }
    }
    return 0;
}

int max_flow(int _src,int _dst){
    src=_src;dst=_dst;
    int resp=0;
    fill(dis,dis+n,0);
    fill(q,q+n,0);
    fill(work,work+n,0);
    dinic_clear();
    dinic_make();
    while(dinic_bfs()){
        fill(work,work+n,0);
        while(int delta=dinic_dfs(src,INF)){
            resp+=delta;
        }
    }
    return resp;
}

int nh,h,r;

int node_from(int house,int height){
    if(height==0)return 0;
    return h*house+height;
}

int node_to(int house,int height){
    if(height==h+1)return n-1;
    return h*house+height;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(13);
    cout.setf(ios::fixed);

    cin>>nh>>h>>r;

    n=nh*h+r+2;
    for(int i=0;i<nh;i++){
        for(int j=0;j<=h;j++){
            //cout<<i<<" "<<j<<" "<<node_from(i,j)<<" "<<node_to(i,j+1)<<endl;
            dinic_put(node_from(i,j),node_to(i,j+1),h*h-(h-j)*(h-j));  
        }
    }
    
    for(int i=0;i<r;i++){
        int le,ri,x,c;
        cin>>le>>ri>>x>>c;
        le--;ri--;
        dinic_put(0,n-2-i,c);
        for(int j=le;j<=ri;j++){
            dinic_put(n-2-i,node_from(j,h-x),INF);
        }
    }
    
    cout<<nh*h*h-max_flow(0,n-1)<<endl;

    return 0;
}