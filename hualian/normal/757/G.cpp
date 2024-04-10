// LUOGU_RID: 90434064
#include<bits/stdc++.h>
#define mk make_tuple
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
bool ppp;
const int N=8e5+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,q,a[N]; 
vector<tuple<int,int> >E[N/4];
struct edge{
	int pre,to,w;
}e[2*N];int last[N],cnt=1;
void add(int x,int y,int w){
	e[++cnt]=edge{last[x],y,w};last[x]=cnt;
	e[++cnt]=edge{last[y],x,w};last[y]=cnt;
}
void rebuild(int x,int fa){
	int lst=0;
	for(auto &v:E[x]){
		int to,w;tie(to,w)=v;if(to==fa)continue;
		if(!lst)add(x,to,w),lst=x;
		else{
			++n;add(lst,n,0);
			add(n,to,w);lst=n;
		}rebuild(to,x);
	}
}
int sz[N],vis[N],We,Wp,MN,dfsrt;
void dfs1(int x,int fa){
	sz[x]=1;
	for(int i=last[x];i;i=e[i].pre){
		int to=e[i].to;if(to==fa||vis[i])continue;
		dfs1(to,x);sz[x]+=sz[to];
	}
}
void dfs2(int x,int fa){
	for(int i=last[x];i;i=e[i].pre){
		int to=e[i].to;if(vis[i]||to==fa)continue;
		dfs2(to,x);
		if(max(sz[to],sz[dfsrt]-sz[to])<max(sz[Wp],sz[dfsrt]-sz[Wp]))Wp=to,We=i;
	}
}
int getrt(int x){
	We=Wp=0;sz[0]=1e9;dfsrt=x;
	dfs1(x,0);dfs2(x,0);
	return We;
}
long long dis[N][32];
bool op[N][32],nowop;
void prepare(int dep,int x,int fa){
	op[x][dep]=nowop;
	for(int i=last[x];i;i=e[i].pre){
		int to=e[i].to;if(to==fa||vis[i])continue;
		dis[to][dep]=dis[x][dep]+e[i].w;
		prepare(dep,to,x);
	}
}
int idx;
struct point{int l,r,v0,w;long long v1;}t[N*20];
#define ls t[p].l
#define rs t[p].r 
void divide(int We,int &p,int dep){
	p=++idx;t[p].w=e[We].w;We>>=1;
	if(!We)return;
	int x=e[We<<1].to,y=e[We<<1|1].to;
	vis[We<<1]=vis[We<<1|1]=1;
	if(x){
		nowop=0;prepare(dep+1,x,0);
		divide(getrt(x),ls,dep+1);
	}
	if(y){
		nowop=1;prepare(dep+1,y,0);
		divide(getrt(y),rs,dep+1);
	}
}
int rt[N];
void merge(int &p,int p2,int x,int dep){
	if(!p2)return;
	p=++idx;t[p]=t[p2];
	t[p].v0++;t[p].v1+=dis[x][dep];
	if(!op[x][dep+1])merge(ls,t[p2].l,x,dep+1);
	else merge(rs,t[p2].r,x,dep+1);
}
long long ans,mod=1<<30;
long long get(int p,int x,int dep){
	long long res=0;
	while(p){
		if(!op[x][dep+1])res+=t[rs].v1+1ll*t[rs].v0*(dis[x][dep+1]+t[p].w),p=ls;
		else res+=t[ls].v1+1ll*t[ls].v0*(dis[x][dep+1]+t[p].w),p=rs;
		dep++;
	}return res;
}
bool pppp;
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),q=read();
	rep(i,n)a[i]=read();
	rep(i,n-1){
		int x=read(),y=read(),w=read();
		E[x].push_back(mk(y,w));
		E[y].push_back(mk(x,w));
	}rebuild(1,0);
	divide(getrt(1),rt[0],1);
	rep(i,n)merge(rt[i],rt[i-1],a[i],1);
	cerr<<idx<<endl;
	while(q--){
		int OP=read();
		ans%=mod;
		if(OP==1){
			int l=ans^read(),r=ans^read(),x=ans^read();
			printf("%lld\n",ans=(get(rt[r],x,1)-get(rt[l-1],x,1)));
		}else{
			int x=ans^read();swap(a[x],a[x+1]);
			merge(rt[x],rt[x-1],a[x],1);
		}
	}
	return 0;
}