#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
const int N=1005;
typedef pair<int,int> pii;
int n,siz[N],rt,all;
vector<int>e[N];
void getroot(int p,int fa){
	siz[p]=1;
	int ms=0;
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==fa)continue;
		getroot(v,p),siz[p]+=siz[v];
		ms=max(ms,siz[v]);
	}
	ms=max(ms,n-siz[p]);
	if(ms<all)all=ms,rt=p;
}
void dfs(int p,int fa){
	siz[p]=1;
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==fa)continue;
		dfs(v,p),siz[p]+=siz[v];
	}
}
void dfss(int p,int fa,int dis,int L,int R){
	int ct=0;
	for(ri i=0,v;i<e[p].size();++i){
		if((v=e[p][i])==fa)continue;
		cout<<v<<' '<<p<<' '<<dis*(ct+1)<<'\n';
		dfss(v,p,dis,1,siz[v]);
		ct+=siz[v];
	}
}
priority_queue<pii,vector<pii>,greater<pii> >q;
int fa[N];
inline int find(const int&x){return x^fa[x]?fa[x]=find(fa[x]):x;}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	if(n==1)return 0;
	for(ri i=1,u,v;i<n;++i){
		u=read(),v=read();
		e[u].push_back(v);
		e[v].push_back(u);
	}
	if(n==2)return cout<<"1 2 1",0;
	all=n,rt=0,getroot(1,0);
	dfs(rt,0);
	for(ri i=0;i<e[rt].size();++i)q.push(pii(siz[e[rt][i]],e[rt][i])),fa[e[rt][i]]=e[rt][i];
	while(q.size()>2){
		pii a=q.top(),b;
		q.pop(),b=q.top(),q.pop();
		fa[find(a.se)]=find(b.se);
		q.push(pii(a.fi+b.fi,find(b.se)));
	}
	pii a=q.top(),b;
	q.pop(),b=q.top(),q.pop();
	int ca=0,cb=0;
	for(ri v,i=0;i<e[rt].size();++i){
		if(find(v=e[rt][i])==a.se)cout<<v<<' '<<rt<<' '<<ca+1<<'\n',dfss(v,rt,1,1,siz[v]),ca+=siz[v];
		else cout<<v<<' '<<rt<<' '<<(cb+1)*(a.fi+1)<<'\n',dfss(v,rt,a.fi+1,1,siz[v]),cb+=siz[v];
	}
	return 0;
}