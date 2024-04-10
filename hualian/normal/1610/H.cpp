#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=3e5+9;
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
vector<int>e[N],E[N];
int dep[N],fa[N][20];
void init(int x){
	dep[x]=dep[fa[x][0]]+1;
	rep(i,19)fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int to:e[x])init(to);
}
int find(int x,int rt){
	Rof(i,19,0)if(dep[fa[x][i]]>dep[rt])
		x=fa[x][i];
	return x;
}
int dp[N];
void dfs(int x){
	for(int to:e[x])dfs(to),dp[x]+=dp[to];
	for(int to:E[x])chmx(dp[x],dp[to]+1);
	return;
}
int X[N],Y[N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read();
	For(i,2,n)e[fa[i][0]=read()].push_back(i);
	init(1);
	rep(i,m){
		X[i]=read(),Y[i]=read();
		if(dep[X[i]]<dep[Y[i]])swap(X[i],Y[i]);
		if(fa[X[i]][0]==Y[i]){puts("-1");return 0;}
		int son=find(X[i],Y[i]);
		if(fa[son][0]==Y[i]){
			E[son].push_back(X[i]);
			X[i]=Y[i]=0;
		}
	}dfs(1);
	int ans=dp[1];
	rep(i,m)if(X[i])chmx(ans,dp[X[i]]+dp[Y[i]]+1);
	cout<<ans<<endl;
	return 0;
}