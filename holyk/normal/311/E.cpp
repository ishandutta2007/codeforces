#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define DEC(i,a,b) for(int i=(a);i>=(b);--i)
#define dbg(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
template<typename T,typename U> inline bool smax(T&x,const U&y){return y>x?(x=y,1):0;}
template<typename T,typename U> inline bool smin(T&x,const U&y){return y<x?(x=y,1):0;}
typedef long long ll;
typedef pair<int,int> pii;
#define pb push_back
#define X first
#define Y second
inline int read(){
    int w=0,p=0;char c;
    while(!isdigit(c=getchar()))if(c=='-')p=1;
    while(isdigit(c))w=(w<<1)+(w<<3)+(c^'0'),c=getchar();
    return p?-w:w;
}
const int N=2e4+5,M=2e5+5;
struct node{
	int v,w,nxt;
}e[M<<1];
int n,m,g,head[N],tot=1,s,t;
inline void add(int x,int y,int z){
	e[++tot]=(node){y,z,head[x]};head[x]=tot;
	e[++tot]=(node){x,0,head[y]};head[y]=tot;
}
queue<int>q;int d[N];
inline bool bfs(){
	memset(d,-1,sizeof d);
	q.push(s),d[s]=0;
	while(q.size()){
		int x=q.front();q.pop();
		for(int i=head[x];i;i=e[i].nxt){
			int&y=e[i].v;
			if(e[i].w&&!~d[y])d[y]=d[x]+1,q.push(y);
		}
	}
	return d[t]>0;
}
int cur[N],a[N],b[N];
inline int dfs(int x,int flow){
	if(x==t)return flow;
	int used=0;
	for(int i=cur[x];i;i=e[i].nxt){
		int&y=e[i].v;
		if(e[i].w&&d[y]==d[x]+1){
			int f=dfs(y,min(e[i].w,flow-used));
			used+=f,e[i].w-=f,e[i^1].w+=f;
			if(e[i].w)cur[x]=i;
			if(used==flow)return flow;
		}
	}
	if(!used)d[x]=-1;
	return used;
}
int main(){
	n=read(),m=read(),g=read();s=0,t=m+n+1;
	REP(i,1,n)a[i]=read();
	REP(i,1,n)b[i]=read(),a[i]?add(s,m+i,b[i]):add(m+i,t,b[i]);
	int ans=0;
	REP(i,1,m){
		int x=read(),w=read(),k=read();
		while(k--){
			int y=read();x?add(i,m+y,1e9):add(m+y,i,1e9);
		}
		ans+=w;w+=read()*g;
		x?add(s,i,w):add(i,t,w);
	}
//	cout<<ans<<endl;
	while(bfs()){
		REP(i,0,t)cur[i]=head[i];ans-=dfs(s,1e9);
	}
	cout<<ans;
	return 0;
}