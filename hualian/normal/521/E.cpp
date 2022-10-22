#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=2e5+9;
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
int n,m,vis[N],dep[N],fa[N];
vector<int>e[N];
int X[N],Y[N],idx,used[N];
int LCA(int x,int y){
	while(x!=y){
		if(dep[x]>dep[y])x=fa[x];
		else y=fa[y];
	}return x;
}
int sta[N],top;
void output(int x,int y){
	while(dep[x]>=dep[y])sta[++top]=x,x=fa[x];
}
int d[N];
vector<int>E[N];
map<int,int>mp[N];
void ad(int x,int y){
	d[x]++,d[y]++;
	E[x].push_back(y);E[y].push_back(x);
	while(x!=y){
		if(!mp[x][fa[x]]){
			E[x].push_back(fa[x]),E[fa[x]].push_back(x),d[x]++,d[fa[x]]++;
			mp[x][fa[x]]=1;
		}
		x=fa[x];
	}
}
int xx=0,yy=0;
void find(int x,int f){
	sta[++top]=x;if(x==yy)return;
	for(int to:E[x])if(to!=f){
		find(to,x);
		if(x==xx){
			cout<<top<<" ";rep(i,top)cout<<sta[i]<<" ";puts("");sta[top=1]=x;
		}
	}
}
void work(int a,int b){
	puts("YES");
	ad(X[a],Y[a]);ad(X[b],Y[b]);
	rep(i,n)if(d[i]==3)yy=xx,xx=i;
	find(xx,0);exit(0);
}
void calc(int x,int y){
	++idx;if(dep[x]<dep[y])swap(x,y);
	X[idx]=x;Y[idx]=y;
	while(x!=y){
		if(used[x])work(used[x],idx);
		used[x]=idx;x=fa[x];
	}
}
void dfs(int x,int f){
	vis[x]=1;fa[x]=f;dep[x]=dep[f]+1;
	for(int to:e[x])if(to!=f&&dep[to]<=dep[x]){
		if(vis[to])calc(x,to);
		else dfs(to,x);
	}
}
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	rep(i,m){
		int x=read(),y=read();
		e[x].push_back(y);
		e[y].push_back(x);
	}
	rep(i,n)if(!vis[i])dfs(i,0);
	puts("NO");
	return 0;
}