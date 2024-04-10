#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=2e6+9;
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
struct edge{
	int to,pre;
}e[2*N];int last[N],cnt;
void add(int x,int y){
	e[++cnt].pre=last[x];
	e[cnt].to=y;
	last[x]=cnt;
}
int vis[N],ans[N];
void dfs(int x,int c){
	vis[x]=1;
	ans[x]=c;
	for(int i=last[x];i;i=e[i].pre)
		if(!vis[e[i].to])dfs(e[i].to,c^1);
}
int aa[N],bb[N];
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	int n=read();
	rep(i,n){int x=read(),y=read();aa[i]=x,bb[i]=y;add(x,y),add(y,x);}
	rep(i,n)add(2*i,2*i+1),add(2*i+1,2*i);
	rep(i,2*n)if(!vis[i])dfs(i,0);
	rep(i,n)cout<<ans[aa[i]]+1<<" "<<ans[bb[i]]+1<<endl;
	return 0;
}