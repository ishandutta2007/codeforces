#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxd=60100,maxm=601000;
long long INF=1ll<<50;
int n,m,s,t;
long long ans,flow[maxm];
int head[maxd],nxt[maxm],rdc[maxm],tnt=1; 
int no[maxd];
queue <int> q;
inline int read(){
	int res=0;
	char ch=getchar(),ch1=ch;
	while(!isdigit(ch))ch1=ch,ch=getchar();
	while(isdigit(ch))res=(res<<3)+(res<<1)+ch-'0',ch=getchar();
	return ch1=='-'?-res:res;
}
void add(int u,int v,long long f){
	nxt[++tnt]=head[u];
	head[u]=tnt;
	rdc[tnt]=v;
	flow[tnt]=f;
}
void addedge(int u,int v,long long f){
	add(u,v,f);add(v,u,0);
}
bool bfs(){
	for(register int i=0;i<=t;++i)
		no[i]=0;
	no[s]=1;
	q.push(s);
	while(q.size()){
		int p=q.front();
		q.pop();
		for(register int i=head[p];i;i=nxt[i])
			if(flow[i]&&!no[rdc[i]]){
				no[rdc[i]]=no[p]+1;
				q.push(rdc[i]);
			}
	}
	return no[t];	
}
long long dinic(int p,long long f){
	if(p==t)
		return f;
	long long fs=0;
	for(register int i=head[p],tf;i&&f;i=nxt[i])
		if(no[rdc[i]]==no[p]+1&&flow[i]){
			tf=dinic(rdc[i],min(f,flow[i]));
			fs+=tf;f-=tf;flow[i]-=tf;flow[i^1]+=tf;
		}
	if(!fs)no[p]=-1;
	return fs;
}
int main(){
	n=read();m=read();
	s=0;t=n+m+1;
	for(register int i=1;i<=n;++i)
		addedge(i,t,read());
	for(register int i=1,scr;i<=m;++i){
		addedge(n+i,read(),INF);
		addedge(n+i,read(),INF);
		addedge(s,n+i,(scr=read()));
		ans+=scr;
	}
	while(bfs())
		ans-=dinic(s,INF);
	printf("%lld\n",ans);
	return 0;
}