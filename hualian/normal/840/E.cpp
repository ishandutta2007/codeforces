// LUOGU_RID: 90354915
#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=1e5+9;
const int S=256;
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
int n,q,a[N];
int dep[N],fa[N];
vector<int>e[N];
int son[N][2],idx;
void clear(){idx=0;son[0][0]=son[0][1]=0;}
void insert(int x){
	int now=0;
	Rof(i,7,0){
		int nt=(x>>i)&1;
		if(!son[now][nt]){
			son[now][nt]=++idx;
			son[idx][0]=son[idx][1]=0;
		}now=son[now][nt];
	}
}
int g[N][S],f[N][S],top[N];
int get(int x,int rt){
	int res=0,now=0,ed=0;
	Rof(i,7,0){
		int nt=(x>>i)&1;
		if(son[now][!nt]){
			now=son[now][!nt];
			res|=1<<i;ed|=((!nt)<<i);
		}else now=son[now][nt],ed|=(nt<<i);
	}return (res<<8)|g[rt][ed];
}
void dfs(int x,int Fa){
	dep[x]=dep[Fa]+1;
	fa[x]=Fa;
	if(dep[x]>=S){
		clear();
		int i=x;
		while(dep[x]-dep[i]<S){
			chmx(g[x][a[i]/256],(dep[x]-dep[i])^(a[i]&255));
			insert(a[i]/256);
			i=fa[i];
		}top[x]=i;
		For(i,0,S-1)f[x][i]=get(i,x); 
	}
	for(int to:e[x])if(to!=fa[x])dfs(to,x);
}	
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),q=read();
	rep(i,n)a[i]=read();
	rep(i,n-1){
		int x=read(),y=read();
		e[x].push_back(y);
		e[y].push_back(x);
	}dfs(1,0);
	while(q--){
		int x=read(),y=read(),ans=0,len=0;
		while(dep[y]-dep[x]>=S){
			chmx(ans,f[y][len]);
			len++;y=top[y];
		}len<<=8;
		while(y!=fa[x]){
			chmx(ans,len^a[y]);
			y=fa[y];len++;
		}printf("%d\n",ans);
	}
	return 0;
}