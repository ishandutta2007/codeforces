#include<bits/stdc++.h>
#define rgi register int
#define int ll
using namespace std;
typedef long long ll;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
    T x=0,f=1;
    char ch=getchar();
    while(!(ch&16)){if(ch=='-')f=-1;ch=getchar();}
    while(ch&16)x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
    A=x*f,read(As...);
}
int n,m,u,v;
ll k,res=1;
struct node{
    int id,d;
};
struct edge{
	ll to,val;
};
bool operator<(node a,node b){
    return a.d>b.d;
}
const int N=600010;
vector<edge>a[N],ch[N];
int d[N],vis[N],e[N];
int st[N],ed[N],w[N];
priority_queue<node>q;
int chked[N];
signed main(){
    read(n,m,k);
    for(rgi i=1;i<=m;++i){
        read(u,v,w[i]),e[i]=u^v,st[i]=u,ed[i]=v;
        a[u].push_back(edge{i,w[i]}),a[v].push_back(edge{i,w[i]});
    }
    for(rgi i=m+1;i<=m+k;++i){
        u=1,read(v,w[i]),e[i]=u^v,st[i]=u,ed[i]=v;
        a[u].push_back(edge{i,w[i]}),a[v].push_back(edge{i,w[i]});
    }
    for(rgi i=1;i<=n;++i)d[i]=1e18;
    d[1]=0,q.push(node{1,0});
    while(!q.empty()){
        int x=q.top().id;
        q.pop();
        if(vis[x])continue;
        vis[x]=1;
        for(rgi i=0;i<a[x].size();i++){
            int to=e[a[x][i].to]^x,val=a[x][i].val;
            if(d[to]>d[x]+val){
                d[to]=d[x]+val;
                if(!vis[to])q.push(node{to,d[to]});
            }
        }
    }
    int ans=n-1;
    for(rgi i=1;i<=m;++i){
    	if(d[st[i]]>d[ed[i]])swap(st[i],ed[i]);
    	if(!chked[ed[i]]&&d[ed[i]]==d[st[i]]+w[i])chked[ed[i]]=1,--ans;
    }
    cout<<max(0ll,k-ans);
    return 0;
}