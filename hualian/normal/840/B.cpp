#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=3e5+9;
//char buf[(1<<21)+5],*p1,*p2;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
void chmx(int &x,int y){(x<y)&&(x=y);}
void chmn(int &x,int y){(x>y)&&(x=y);}
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,a[N],rt=0;
vector<int>e[N];
map<int,int>mp[N];
int fa[N],vis[N];
void dfs(int x){
	vis[x]=1;
	for(int to:e[x])if(!vis[to])
		fa[to]=x,dfs(to);
}
int sta[N],top,ok[N];
void work(int x){
	if(x!=rt)ok[x]=a[x];
	for(int to:e[x]){
		work(to);
		ok[x]^=ok[to];
	}
	if(x!=rt&&ok[x])sta[++top]=mp[fa[x]][x];
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	rep(i,n)a[i]=read();
	rep(i,m){
		int x=read(),y=read();
		e[x].push_back(y);
		e[y].push_back(x);
		mp[x][y]=mp[y][x]=i;
	}
	rep(i,n)if(a[i]==-1){
		if(!rt){rt=i;continue;}
		a[i]=0;
	}
	if(!rt){
		int all=0;
		rep(i,n)all^=a[i];
		if(all){puts("-1");return 0;}
		rt=1;
	}
	dfs(rt);
	rep(i,n)e[i].clear();
	rep(i,n)e[fa[i]].push_back(i);
	work(rt);
	cout<<top<<endl;rep(i,top)printf("%d ",sta[i]);
	return 0;
}