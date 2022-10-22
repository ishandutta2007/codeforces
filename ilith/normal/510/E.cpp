#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a,i##i=b;i<=i##i;++i)
#define ROF(i,a,b) for(rgi i=a,i##i=b;i>=i##i;--i)
typedef long long ll;
using namespace std;
const ll N=210,M=80010;
int n,m,s,t,a[N],C;
int u,v,c,hd[N],tot=1,nxt[M],to[M];
vector<int>P,G;
int vs[M],vis[N];
ll ans,w[M],k;
inline void link(int u,int v,ll c){
    to[++tot]=v,w[tot]=c;
    nxt[tot]=hd[u],hd[u]=tot;
}
inline void add(int u,int v,ll c){
	link(u,v,c),link(v,u,0);
}
int q[N],l,r,d[N];
int bfs(){
    memset(d,0,sizeof d);
    q[d[s]=l=r=1]=s;
    while(r>=l){
        for(int i=hd[k=q[l++]];i;i=nxt[i]){
            if(w[i]&&!d[to[i]])d[q[++r]=to[i]]=d[k]+1;
        }
    }
    return d[t];
}
ll dfs(int x,ll f){
    if(x==t)return f;
    ll res=f;
    for(int i=hd[x];i;i=nxt[i]){
        if(w[i]&&d[v=to[i]]==d[x]+1)f-=k=dfs(v,min(f,w[i])),w[i]-=k,w[i^1]+=k;
    }
    return f==res?d[x]=0:res-f;
}
vector<vector<int>>Ans;
void Dfs(int x){
	if(vis[x])return;
	vis[x]=1,G.pbk(x);
	for(int i=hd[x];i;i=nxt[i])if(w[i]==!(a[x]&1)&&to[i]<=n){
		Dfs(to[i]);
    }
}
signed main(){
	vs[1]=1;
	FOR(i,2,M-5){
		if(!vs[i])P.pbk(i);
		for(rgi j:P){
			if(i*j>M-5)break;
			vs[i*j]=1;
			if(i%j==0)break;
		}
	}
	scanf("%d",&n),s=n+1,t=n+2;
	FOR(i,1,n){
		scanf("%d",a+i);
		a[i]&1?add(s,i,2):add(i,t,2);
		FOR(j,1,i-1)if(!vs[a[i]+a[j]]){
			a[i]&1?add(i,j,1):add(j,i,1);
		}
	}
	while(bfs())ans+=dfs(s,1ll<<40);
	if(ans!=n)puts("Impossible"),exit(0);
	FOR(i,1,n)if(!vis[i]){
		Dfs(i),Ans.pbk(G),G.clear();
	}
	printf("%d\n",(int)Ans.size());
	for(auto k:Ans){
		printf("%d ",(int)k.size());
		for(rgi t:k)printf("%d ",t);
		puts("");
	}
    return 0;
}