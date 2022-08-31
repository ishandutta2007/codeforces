// luogu-judger-enable-o2
#include <cstdio>
#include <cstring>
#include <algorithm>
#define int long long

int m,n,head[55001],nxt[2000001],b[2000001],v[2000001],k=1,s,t,S,T,line[10001],now;
int p[55001],dis[55001],ans,q[55001],h,sum;
void push(int s,int t,int val){
    nxt[++k]=head[s];
    head[s]=k;
    b[k]=t;
    v[k]=val;
}
void link(int s,int t,int val){
    push(s,t,val);
    push(t,s,0);
}
bool bfs(){
    h=t=0;
    q[++t]=S;
    memset(dis,0,sizeof dis);
    dis[S]=1;
    while(h<t){
        h++;
        for(int i=head[q[h]];i;i=nxt[i])
            if(v[i]&&!dis[b[i]]){
                dis[b[i]]=dis[q[h]]+1;
                q[++t]=b[i];
                if(b[i]==T)return 1;
            }
    }
    return 0;
}
int dfs(int x,int flow){
    if(x==T||!flow)return flow;
    int used=0,w;
    for(int i=p[x];i;i=nxt[i])
        if(v[i]&&dis[b[i]]==dis[x]+1){
            w=dfs(b[i],std::min(flow-used,v[i]));
            used+=w;
            v[i]-=w;
            v[i^1]+=w;
            if(w)p[x]=i;
            if(flow==used)return flow;
        }
    if(!used)dis[x]=0;
    return used;
}
signed main(){
    scanf("%lld%lld",&n,&m);
    S=0,T=n+m+1;
    for(int i=1;i<=n;i++){
        int tem;
        scanf("%lld",&tem);
        link(0,i,tem);
    }
    for(int i=1;i<=m;i++){
        int a,b,c;
        scanf("%lld%lld%lld",&a,&b,&c);
        sum+=c;
        link(a,n+i,1000000000000000000ll);
        link(b,n+i,1000000000000000000ll);
        link(n+i,T,c);
    }
    while(bfs()){
        memcpy(p,head,sizeof p);
        ans+=dfs(S,1000000000000000000ll);
    }
    printf("%I64d\n",sum-ans);
}