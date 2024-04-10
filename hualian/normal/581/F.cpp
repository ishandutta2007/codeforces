#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define For(i,a,b) for(register int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(register int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(register int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=5010+9;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
char In[1<<20],*Ss=In,*Tt=In;
//#define getchar() (Ss==Tt&&(Tt=(Ss=In)+fread(In,1,1<<20,stdin),Ss==Tt)?EOF:*Ss++)
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,d[N],sz[N];
int dp[N][2][N];
struct edge{
	int pre,to;
}e[2*N];int last[N],cnt;
void add(int x,int y){e[++cnt]=edge{last[x],y};last[x]=cnt;}
void dfs(int x,int fa){
	if(d[x]==1){
		sz[x]=1; 
		dp[x][0][1]=0;
		dp[x][1][0]=0;
		return;
	}
	dp[x][0][0]=dp[x][1][0]=0;
	for(int i=last[x],to;i;i=e[i].pre){
		to=e[i].to;if(to==fa)continue;
		dfs(to,x);sz[x]+=sz[to];
		int *f=dp[x][0],*g=dp[x][1];
		Rof(a,sz[x],0){
			f[a]=f[a]+min(dp[to][0][0],dp[to][1][0]+1);
			g[a]=g[a]+min(dp[to][0][0]+1,dp[to][1][0]);
			For(b,1,min(a,sz[to])){
				chmn(f[a],f[a-b]+dp[to][0][b]);
				chmn(f[a],f[a-b]+dp[to][1][b]+1);
				chmn(g[a],g[a-b]+dp[to][0][b]+1);
				chmn(g[a],g[a-b]+dp[to][1][b]);
			}
		}
	}
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read();memset(dp,0x3f,sizeof dp);
	rep(i,n-1){int x=read(),y=read();add(x,y),add(y,x);d[x]++,d[y]++;}
	rep(i,n)if(d[i]!=1){dfs(i,0);cout<<min(dp[i][0][sz[i]/2],dp[i][1][sz[i]/2]);return 0;}
	puts("1");
	return 0;
}