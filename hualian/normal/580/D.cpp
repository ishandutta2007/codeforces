#include<bits/stdc++.h>
#define int long long
#define lowbit(x) (x&-x)
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=19;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,k,ans;
int c[N][N];
int dp[1<<N][N];
int pop[1<<N];
int a[N];
int sta[N],top;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read(),k=read();
	rep(i,n)a[i-1]=read();
	rep(i,(1<<n)-1)pop[i]=pop[i>>1]+(i&1);
	rep(i,k){
		int x=read(),y=read();
		c[x-1][y-1]=read();
	}
	memset(dp,0xc0,sizeof dp);
	dp[0][0]=0;
	For(S,0,(1<<n)-1)For(x,0,n-1)if(!((S>>x)&1))For(y,0,n-1)if(((S>>y)&1)||!S){
		chmx(dp[S|(1<<x)][x],dp[S][y]+(S==0?0:c[y][x])+a[x]);}
	For(S,0,(1<<n)-1)if(pop[S]==m)For(x,0,n-1)chmx(ans,dp[S][x]);
	cout<<ans<<endl;
	return 0;
}