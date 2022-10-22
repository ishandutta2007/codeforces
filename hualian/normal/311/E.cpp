#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int inf=1e9+7;
const int N=3e4+9;
const int S=3e4,T=3e4+1;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct edge{
	int pre,to,w; 
}e[10*N];int last[N],cur[N],cnt=1;
void add(int x,int y,int w){
	e[++cnt].pre=last[x];
	e[cnt].to=y;e[cnt].w=w;
	last[x]=cnt;
	e[++cnt].pre=last[y];
	e[cnt].to=x;e[cnt].w=0;
	last[y]=cnt;
}
int n,m,g,idx,ans;
int a[N],q[N],gap[N],dis[N];
void bfs(){
	int l=1,r=0;q[++r]=T,gap[dis[T]=1]++;
	while(l<=r){
		int x=q[l++];
		for(int i=last[x];i;i=e[i].pre){
			int to=e[i].to;if(dis[to])continue;
			gap[dis[to]=dis[x]+1]++;q[++r]=to;
		}
	}
}
int isap(int x,int in){
	if(in==0)return 0;
	if(x==T)return in;
	int out=0;
	for(int &i=cur[x];i;i=e[i].pre){
		int to=e[i].to;if(dis[x]!=dis[to]+1)continue;
		int res=isap(to,min(in-out,e[i].w));
		out+=res;e[i].w-=res,e[i^1].w+=res;
		if(in==out)return in;
	}
	(--gap[dis[x]])?(++gap[++dis[x]]):dis[S]=idx+1;
	return out;
}
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read(),g=read();idx=n;
	rep(i,n)a[i]=read();
	rep(i,n)a[i]?add(i,T,read()):add(S,i,read());
	rep(i,m){
		int op=read(),w=read(),k=read();ans+=w;
		++idx;
		rep(j,k){
			int x=read();
			op?add(x,idx,inf):add(idx,x,inf);
		}
		int f=read();
		op?add(idx,T,w+g*f):add(S,idx,w+g*f);
	}
	bfs();while(dis[S]!=idx+1)memcpy(cur,last,sizeof last),ans-=isap(S,inf);
	cout<<ans<<endl;
	return 0;
}