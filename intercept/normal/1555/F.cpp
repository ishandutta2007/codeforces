#include<bits/stdc++.h>
using namespace std;
const int M=8e5+9;
int n,m;
int sum[M],val[M],rev[M],f[M],s[M],c[M][2];
mt19937 rd(time(0));
int read(){
	int rex=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='0')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){rex=rex*10+ch-'0';ch=getchar();}
	return rex*f;
}
bool isroot(int x){
	return c[f[x]][0]!=x&&c[f[x]][1]!=x;
}
void pushup(int x){
	sum[x]=sum[c[x][0]]^sum[c[x][1]]^val[x];
}
void pushdown(int x){
	if(!rev[x])return;
	swap(c[x][0],c[x][1]);
	rev[c[x][0]]^=1;rev[c[x][1]]^=1;
	rev[x]=0;
}
void rotate(int x){
	int y=f[x],z=f[y],k=c[y][1]==x,ch=c[x][k^1];
	if(!isroot(y))c[z][c[z][1]==y]=x;f[x]=z;
	c[y][k]=ch;f[ch]=y;
	c[x][k^1]=y;f[y]=x;
	pushup(y),pushup(x);
}
void splay(int x){
	int top=0,u=x;
	while(!isroot(u))s[++top]=u,u=f[u];s[++top]=u;
	while(top)pushdown(s[top--]);
	for(int y=f[x];!isroot(x);y=f[x]){
		if(!isroot(y))
			rotate(((c[f[y]][1]==y)==(c[y][1]==x))?y:x);
		rotate(x);
	}
}
void access(int x){
	for(int t=0;x;t=x,x=f[x]){
		splay(x);
		c[x][1]=t;
		pushup(x);
	}
}
int findroot(int x){
	access(x),splay(x);
	while(c[x][0])x=c[x][0];
	return x;
}
void makeroot(int x){access(x);splay(x);rev[x]^=1;}
void split(int x,int y){makeroot(x);access(y);splay(y);}
void link(int x,int y){makeroot(x);f[x]=y;}
void cut(int x,int y){split(x,y);if(!c[x][1])f[x]=0,c[y][0]=0;pushup(y);}
void dfs(int x){
	if(c[x][0])dfs(c[x][0]);
	if(c[x][1])dfs(c[x][1]);
	if(x>n)val[x]=rd();
	sum[x]=sum[c[x][0]]^sum[c[x][1]]^val[x];
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int x=read(),y=read(),v=read(),z=n+i;
		val[z]=v;
		if(findroot(x)!=findroot(y)){
			link(x,z),link(y,z),puts("YES");
		}
		else {
			split(x,y);
			if((sum[y]^v)==1){
				puts("YES");
				dfs(y);
			}
			else puts("NO");
		}
		
	}
	return 0;
}