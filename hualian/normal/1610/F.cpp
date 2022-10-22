#include<bits/stdc++.h>
#define pb push_back
#define ed (e[w][x].size()-1)
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=5e6+9;
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
int n,m; 
int d[N];
struct node{int x,v;};
vector<node>e[2][N];
int ans[N*2],id=1;
void add(int x,int y,int w){
	e[w][x].pb(node{y,++id});
	e[w][y].pb(node{x,++id});
}
bool out(int x,int w){while(e[w][x].size()&&ans[e[w][x][ed].v]!=-1)e[w][x].pop_back();return e[w][x].size()?1:0;}
void dfs(int x,int w){
	if(!out(x,w))w^=1;
	if(!out(x,w))return;
	ans[e[w][x][ed].v]=0;ans[e[w][x][ed].v^1]=1;
	dfs(e[w][x][ed].x,w);
	while(out(x,w)){
		ans[e[w][x][ed].v]=0;ans[e[w][x][ed].v^1]=1;
		dfs(e[w][x][ed].x,w);
	}w^=1;
	while(out(x,w)){
		ans[e[w][x][ed].v]=0;ans[e[w][x][ed].v^1]=1;
		dfs(e[w][x][ed].x,w);
	}
}
int p[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	rep(i,m){
		int x=read(),y=read(),w=read();
		if(w==2)w=0;
		add(x,y,w);
		d[x]^=1;d[y]^=1;
		p[x]+=w;p[y]+=w;
	}
	int res=0;
	rep(i,n)if(d[i])add(i,n+1,1);
	rep(i,n)res+=p[i]%2;cout<<res<<endl;
	memset(ans,-1,sizeof ans);
	rep(i,n)dfs(i,1);
	rep(i,m){assert(ans[2*i]!=-1);printf("%d",ans[i*2]+1);}
	return 0;
}