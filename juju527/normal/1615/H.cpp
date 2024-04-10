#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=1005,inf=1e9;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int v[maxn];
vector<int> ed[maxn];
int p[maxn],id[maxn];
int tmp0[maxn],tmp1[maxn];
struct max_flow{
    struct Edge{int to,w,nxt;}e[6*maxn];
    int cnt;
    int head[maxn];
    int s,t;
    void init(int num){
        s=0,t=num+1;cnt=0;
        for(int i=s;i<=t;i++)head[i]=-1;
        return ;
    }
    void add(int u,int v,int w){e[cnt]=(Edge){v,w,head[u]};head[u]=cnt++;return ;}
    void addedge(int u,int v,int w){add(u,v,w),add(v,u,0);return ;}
    int lev[maxn];
    queue<int>q;
    bool bfs(){
        for(int i=s;i<=t;i++)lev[i]=0;
        while(q.size())q.pop();
        q.push(s);lev[s]=1;
        while(q.size()){
            int k=q.front();
            q.pop();
            for(int i=head[k];i!=-1;i=e[i].nxt){
                int tmp=e[i].to;
                if(lev[tmp]||!e[i].w)continue;
                lev[tmp]=lev[k]+1;
                q.push(tmp);
                if(tmp==t)return 1;
            }
        }
        return 0;
    }
    ll dinic(int x,int flow){
        if(x==t)return flow;
        int rest=flow;
        for(int i=head[x];i!=-1;i=e[i].nxt){
            int tmp=e[i].to;
            if(lev[tmp]!=lev[x]+1||!e[i].w)continue;
            int inc=dinic(tmp,min(rest,e[i].w));
            if(!inc)lev[tmp]=0;
            e[i].w-=inc,e[i^1].w+=inc;
            rest-=inc;
            if(!rest)break;
        }
        return flow-rest;
    }
    int work(int l,int r){
        int maxflow=0;
        while(bfs()){
            int flow=dinic(s,inf);
            while(flow)maxflow+=flow,flow=dinic(s,inf);
        }
        int l0=0,l1=0;
        for(int i=l;i<=r;i++){
            if(lev[id[p[i]]])tmp0[++l0]=p[i];
            else tmp1[++l1]=p[i];
        }
        for(int i=l;i<=l+l0-1;i++)p[i]=tmp0[i-l+1];
        for(int i=l+l0;i<=r;i++)p[i]=tmp1[i-l-l0+1];
        return l+l0-1;
    }
}F;
int f[maxn];
void solve(int l,int r,int x,int y){
    if(l>r)return ;
    if(x==y){for(int i=l;i<=r;i++)f[p[i]]=x;return ;}
    int mid=(x+y)/2;
    F.init(r-l+1);
    for(int i=l;i<=r;i++)id[p[i]]=i-l+1;
    for(int i=l;i<=r;i++){
        int u=p[i],val=abs(v[u]-mid)-abs(v[u]-mid-1);
        if(val>0)F.addedge(id[u],F.t,val);
        else F.addedge(F.s,id[u],-val);
        for(size_t j=0;j<ed[u].size();j++)if(id[ed[u][j]])F.addedge(id[u],id[ed[u][j]],inf);
    }
    int pos=F.work(l,r);
    for(int i=l;i<=r;i++)id[p[i]]=0;
    solve(l,pos,x,mid);solve(pos+1,r,mid+1,y);
    return ;
}
int main(){
    int n,m;
	n=read();m=read();
	for(int i=1;i<=n;i++)v[i]=read();
    for(int i=1;i<=m;i++){
		int u,v;
		u=read();v=read();
		ed[v].push_back(u);
	}
	for(int i=1;i<=n;i++)p[i]=i;
	solve(1,n,1,1e9);
	for(int i=1;i<=n;i++)printf("%d ",f[i]);
	puts("");
	return 0;
}