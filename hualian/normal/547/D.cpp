#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=4e5+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,S=4e5+1;
struct edge{
	int pre,to;
}e[6*N];int last[N],cnt=1;
int d[N];
bool vis[6*N];
void add(int x,int y){
	e[++cnt].pre=last[x];
	e[cnt].to=y;
	last[x]=cnt;
}
void dfs(int x){
	for(int &i=last[x];i;i=e[i].pre){
		int to=e[i].to;
		if(vis[i]||vis[i^1])continue;
		vis[i]=1;dfs(to);
	}
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();
	rep(i,n){
		int x=read(),y=read()+200000;
		add(x,y);
		add(y,x);
		d[x]++;d[y]++;
	}
	rep(i,400000)if(d[i]&1)add(i,S),add(S,i);
	rep(i,400000)dfs(i);
	rep(i,n)putchar(vis[i<<1]?'r':'b');
	return 0;
}