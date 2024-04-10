#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int inf=1e9+7;
const int N=1010;
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
int a[N][N],s[N][N];
int ans;
struct edge{
	int pre,to,w;
}e[N*N];int last[N],cur[N],cnt=1;
void add(int x,int y,int w){
	e[++cnt].pre=last[x];
	e[cnt].to=y;
	e[cnt].w=w;
	last[x]=cnt;
}
queue<int>q;
int dis[N];
bool bfs(){
	memset(dis,0x3f,sizeof dis);
	q.push(T);dis[T]=0;
	while(!q.empty()){
		int x=q.front();q.pop();
		for(int i=last[x];i;i=e[i].pre)if(e[i^1].w){
			int to=e[i].to;
			if(dis[x]+1<dis[to])dis[to]=dis[x]+1,q.push(to);
		}
	}return dis[S]<10000000;
}
int vis[N];
int dinic(int x,int in){
	if(x==T||in==0)	return in;
	vis[x]=1;int out=0;
	for(int &i=cur[x];i;i=e[i].pre){
		int to=e[i].to;if(!e[i].w||vis[to]||dis[to]+1!=dis[x])continue;
		int res=dinic(to,min(e[i].w,in-out));
		out+=res;e[i].w-=res;e[i^1].w+=res;
	}
	vis[x]=0;
	return out;
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	rep(i,n)rep(j,m){
		char c;cin>>c;
		a[i][j]=(c=='B');
	}
	rep(i,n)rep(j,m)s[i][j]=a[i][j]^a[i+1][j]^a[i][j+1]^a[i+1][j+1],ans+=s[i][j];
	rep(i,n-1)rep(j,m-1){
		if(s[i][j]&&s[i][m]&&s[n][j]){
			add(i,j+n,1);add(j+n,i,0);
		}
	}
	S=n+m+1;T=n+m+2;
	rep(i,n)add(S,i,1),add(i,S,0);rep(i,m)add(i+n,T,1),add(T,i+n,0);
	int res=0;
	while(bfs())memcpy(cur,last,sizeof last),res+=dinic(S,inf);
	if(s[n][m]){
		cout<<ans-res-(res+s[n][m]+1)%2;
	}else
		cout<<ans-res+(res+s[n][m])%2;
	return 0;
}