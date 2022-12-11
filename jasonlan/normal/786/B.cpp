#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define mid ((l+r)>>1)
using namespace std;
typedef long long ll;
const int maxn=1000100,maxs=3001000;
const ll INF=1000000000000000;
int n,q,s;
int rt_in,rt_out,ver;
int son[2][maxn];
int in[maxn],out[maxn];
int head[maxn],rdc[maxs],nxt[maxs],tnt;
ll dis[maxn],len[maxs];
bool vis[maxn];
inline ll read(){
	ll res=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return res;
}
void addedge(int u,int v,ll c){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
	len[tnt]=c;
}
void build_in(int &p,int l,int r){
	p=++ver;
	if(l==r){
		in[l]=p;return;
	}
	build_in(son[0][p],l,mid);
	build_in(son[1][p],mid+1,r);
	addedge(p,son[0][p],0);
	addedge(p,son[1][p],0);
}
void build_out(int &p,int l,int r){
	p=++ver;
	if(l==r){
		out[l]=p;
		addedge(in[l],out[l],0);
		return;
	}
	build_out(son[0][p],l,mid);
	build_out(son[1][p],mid+1,r);
	addedge(son[0][p],p,0);
	addedge(son[1][p],p,0);
}
void add_in(int p,int lr,int rr,int x,ll w,int l,int r){
	if(lr<=l&&r<=rr){
		addedge(out[x],p,w);return;
	}
	if(lr>r||rr<l)return;
	add_in(son[0][p],lr,rr,x,w,l,mid);
	add_in(son[1][p],lr,rr,x,w,mid+1,r);
}
void add_out(int p,int lr,int rr,int x,ll w,int l,int r){
	if(lr<=l&&r<=rr){
		addedge(p,in[x],w);return;
	}
	if(lr>r||rr<l)return;
	add_out(son[0][p],lr,rr,x,w,l,mid);
	add_out(son[1][p],lr,rr,x,w,mid+1,r);
}
void dijkstra(){
	for(register int i=1;i<=ver;++i)
		dis[i]=INF;
	dis[out[s]]=0;
	priority_queue <pair<ll,int> > qe;
	qe.push(make_pair(-dis[out[s]],out[s]));
	while(qe.size()){
		int p=qe.top().second;
		qe.pop();
		if(vis[p])continue;
		vis[p]=true;
		for(register int i=head[p];i;i=nxt[i])
			if(dis[rdc[i]]>dis[p]+len[i]){
				dis[rdc[i]]=dis[p]+len[i];
				qe.push(make_pair(-dis[rdc[i]],rdc[i]));
			}
	}
}
int main(){
	n=read();q=read();s=read();
	build_in(rt_in,1,n);
	build_out(rt_out,1,n);
	for(register int i=1,op,v,x,y;i<=q;++i){
		op=read();
		if(op==1){
			x=y=read();v=read();
			add_out(rt_out,x,y,v,read(),1,n);
		}
		else if(op==2){
			v=read();x=read();y=read();
			add_in(rt_in,x,y,v,read(),1,n);
		}
		else{
			v=read();x=read();y=read();
			add_out(rt_out,x,y,v,read(),1,n);
		}
	}
	dijkstra();
	for(register int i=1;i<=n;++i)
		dis[out[i]]==INF?printf("-1 "):printf("%lld ",dis[out[i]]);
	return 0;
}