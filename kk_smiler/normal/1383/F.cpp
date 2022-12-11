#include <bits/stdc++.h>
using namespace std;
int n,m,k,Q,head[10010],o=-1,cur[10010],dep[10010],pre[10010],lst[10010],ans[1030],sz[1030];
inline int read(){
	register int tmp=0,fl=0;
	static char ch;
	while(ch=getchar(),ch<'0'||ch>'9') fl|=ch=='-';
	tmp=ch^48;
	while(ch=getchar(),ch>='0'&&ch<='9') tmp=tmp*10+(ch^48);
	return fl?-tmp:tmp;
}
void write(int x){
	if(x>=10) write(x/10);
	putchar(x%10+'0'); 
}
struct edge{
	int to,link;
}e[20010];
void add_edge(int u,int v){
	e[++o].to=v,e[o].link=head[u],head[u]=o;
	e[++o].to=u,e[o].link=head[v],head[v]=o;
}
int *w,ff[1030][20010],mX[1030],Mx;
queue<int>q;
bool bfs(){
	memset(dep,0,sizeof(int[n+1]));
	dep[1]=1,q.push(1);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];~i;i=e[i].link){
			int v=e[i].to;
			if(!dep[v]&&w[i]) dep[v]=dep[u]+1,q.push(v);
		}
	}
	return dep[n];
}
int dfs(int u,int in){
	if(u==n) return in;
	int out=0,res;
	for(int &i=cur[u];(~i)&&in;i=e[i].link){
		int v=e[i].to;
		if(dep[v]==dep[u]+1&&w[i]){
			res=dfs(e[i].to,min(w[i],in));
			w[i]-=res,w[i^1]+=res;
			in-=res,out+=res;
		}
	}
	if(!out) dep[u]=0;
	return out;
}
bool Bfs(){
	memset(dep,0,sizeof(int[n+1]));
	dep[1]=1,q.push(1);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];~i;i=e[i].link){
			int v=e[i].to;
			if(!dep[v]&&w[i]){
				dep[v]=dep[u]+1,lst[v]=i,q.push(v);
				if(v==n){
					while(!q.empty()) q.pop();
					break;
				}
			}
			
		}
	}
	if(!dep[n]) return false;
	int nw=n,fl=2e9;
	while(nw!=1){
		fl=min(w[lst[nw]],fl);
		nw=e[lst[nw]^1].to;
	}
	Mx+=fl,nw=n;
	while(nw!=1){
		w[lst[nw]]-=fl;
		w[lst[nw]^1]+=fl;
		nw=e[lst[nw]^1].to;
	}
	return true;
}
void dinic(){
	while(bfs()) memcpy(cur,head,sizeof(int[n+1])),Mx+=dfs(1,2e9); 
}
void FF(){
	while(Bfs());
}
int main(){
	srand(time(NULL));
	n=read(),m=read(),k=read(),Q=read();
	memset(head,-1,sizeof(head));
	for(int i=1,u,v,w;i<=m;i++) u=read(),v=read(),w=read(),add_edge(u,v),ff[(1<<k)-1][o]=0,ff[(1<<k)-1][o^1]=w;
	w=ff[(1<<k)-1],dinic(),mX[(1<<k)-1]=Mx;
	for(int S=(1<<k)-2;S>=0;S--){
		int mx=-1,pos;
		for(int i=0;i<k;i++){
			if((S>>i)&1) continue;
			if(mX[S|(1<<i)]==mx&&(rand()&1)) pos=i;
			if(mX[S|(1<<i)]>mx) mx=mX[S|(1<<i)],pos=i;
		}
		w=ff[S],memcpy(w,ff[S|(1<<pos)],sizeof(int[o+1])),Mx=mx;
		w[pos*2]=25,FF(),mX[S]=Mx;
	}
	while(Q--){
		for(int i=0;i<k;i++) sz[1<<i]=read();
		for(int S=1;S<(1<<k);S++) sz[S]=sz[S^(S&-S)]+sz[S&-S];
		int res=2e9; 
		for(int S=0;S<(1<<k);S++) res=min(res,mX[S]+sz[S]);
		write(res),putchar('\n');
	}
}