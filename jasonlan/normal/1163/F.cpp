#include<iostream>
#include<cstdio>
#include<queue>
#define mid ((l+r)>>1)
#define mp make_pair
using namespace std;
typedef long long ll;
const int maxn=200010;
const ll INF=1e18;
int n,m,Q;
int head[maxn],nxt[maxn<<1],rdc[maxn<<1],tnt=1;
ll dis[2][maxn],len[maxn<<1];
int frt[maxn],L[maxn],R[maxn];
int idpath[maxn<<1],idcnt;
int rt,ver,son[2][maxn<<1];
ll mini[maxn<<1];
bool onpath[maxn],vis[maxn];
priority_queue <pair<ll,int> > q;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void add(int u,int v,ll z){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
	len[tnt]=z;
}
void dijkstra(int c,int st){
	for(register int i=1;i<=n;++i)
		dis[c][i]=INF,vis[i]=0;
	dis[c][st]=0;
	q.push(mp(0,st));
	while(q.size()){
		int p=q.top().second;
		q.pop();
		if(vis[p])continue;
		vis[p]=true;
		for(register int i=head[p];i;i=nxt[i]){
			if(dis[c][rdc[i]]>dis[c][p]+len[i]){
				frt[rdc[i]]=i^1;
				dis[c][rdc[i]]=dis[c][p]+len[i];
				if(!onpath[rdc[i]])
					!c?L[rdc[i]]=L[p]:R[rdc[i]]=R[p];
				q.push(mp(-dis[c][rdc[i]],rdc[i]));
			}
		}
	}
}
void getpath(){
	onpath[1]=true;
	L[1]=R[1]=0;
	for(register int i=1,p=1;p!=n;++i){
		idpath[frt[p]]=idpath[frt[p]^1]=i;
		p=rdc[frt[p]];
		++idcnt;
		onpath[p]=true;
		L[p]=R[p]=i;
	}
}
void build(int &p,int l,int r){
	p=++ver;
	mini[p]=INF;
	if(l==r)return;
	build(son[0][p],l,mid);
	build(son[1][p],mid+1,r);
}
void modify(int p,int lr,int rr,ll x,int l,int r){
	if(lr<=l&&r<=rr){
		mini[p]=min(mini[p],x);
		return;
	}
	if(lr>r||l>rr)return;
	modify(son[0][p],lr,rr,x,l,mid);
	modify(son[1][p],lr,rr,x,mid+1,r);
}
ll query(int p,int xp,int l,int r){
	if(l==r)return mini[p];
	if(xp<=mid)return min(mini[p],query(son[0][p],xp,l,mid));
	return min(mini[p],query(son[1][p],xp,mid+1,r));
}
int main(){
	n=read();m=read();Q=read();
	for(register int i=1,u,v,z;i<=m;++i){
		u=read();v=read();z=read();
		add(u,v,z);add(v,u,z);
	}
	dijkstra(1,n);
	getpath();
	dijkstra(0,1);
	dijkstra(1,n);
	build(rt,1,idcnt);
	for(register int i=2;i<=tnt;++i)
		if(!idpath[i])
			modify(rt,L[rdc[i]]+1,R[rdc[i^1]],dis[0][rdc[i]]+len[i]+dis[1][rdc[i^1]],1,idcnt);
	for(register int i=1,t,x;i<=Q;++i){
		t=read();x=read();
		ll ans=dis[0][n];
		t<<=1;
		if(idpath[t]){
			ans+=x-len[t];
			if(x>len[t])
				ans=min(ans,query(rt,idpath[t],1,idcnt));
		}
		else{
			if(x<=len[t])
				ans=min(ans,min(dis[0][rdc[t]]+x+dis[1][rdc[t^1]],dis[0][rdc[t^1]]+x+dis[1][rdc[t]]));
			else;
		}
		printf("%lld\n",ans);
	}
	return 0;
}