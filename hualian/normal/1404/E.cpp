#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int inf=1e9;
const int N=210+9;
bool ppp;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,S,T;
struct edge{
	int pre,to,w;
}e[10*N*N];int last[N*N*2],cnt=1;
void add(int x,int y,int w){
	e[++cnt].pre=last[x];
	e[cnt].to=y;
	e[cnt].w=w;
	last[x]=cnt;
}
int dis[N*N*2],cur[N*N*2];
bool BFS(){
	memset(dis,0,sizeof dis);
	queue<int>q;
	dis[T]=1;q.push(T);
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=last[x];i;i=e[i].pre){
			int to=e[i].to;
			if(!e[i^1].w)continue;
			if(!dis[to]){
				dis[to]=dis[x]+1;
				q.push(to);
			}
		}
	}return dis[S]?1:0;
}
int dinic(int x,int in){
	if(in==0||x==T)return in;
	int out=0;
	for(int &i=cur[x];i;i=e[i].pre){
		int to=e[i].to;if(dis[to]+1==dis[x]){
			int res=dinic(to,min(in-out,e[i].w));
			out+=res;e[i].w-=res;e[i^1].w+=res;
			if(in==out)return in;
		}
	}return out;
}
bool pppp;
char s[210][210];
int D[210][210],R[210][210];
int idx;
void addd(int x,int y,int w){if(x==0||y==0)return;add(x,y,w),add(y,x,0);}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	int n=read(),m=read();
	rep(i,n)scanf("%s",s[i]+1);
	S=++idx;T=++idx;
	rep(i,n-1)rep(j,m)if(s[i][j]=='#'&&s[i+1][j]=='#')
		D[i][j]=++idx,addd(S,idx,1);
	rep(i,n)rep(j,m-1)if(s[i][j]=='#'&&s[i][j+1]=='#')
		R[i][j]=++idx,addd(idx,T,1);
	
	rep(i,n)rep(j,m){
		if(i-1&&j-1)addd(D[i-1][j],R[i][j-1],1);
		if(i-1&&j+1<=m)addd(D[i-1][j],R[i][j],1);
		if(i+1<=n&&j-1)addd(D[i][j],R[i][j-1],1);
		if(i+1<=n&&j+1<=m)addd(D[i][j],R[i][j],1);
	}
	int all=0;
	rep(i,n)rep(j,m)if(s[i][j]=='#')all++;
	int flow=0;
	while(BFS())memcpy(cur,last,sizeof last),flow+=dinic(S,inf);
	cout<<all-(idx-2-flow)<<endl;
	return 0;
}
////////////////