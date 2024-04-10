#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=11;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int dp[1<<N][1<<N];//1 
int to[N][N],pop[1<<N];
int n,m,k,S,T,res;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),m=read(),k=read();
	rep(i,1<<n)pop[i]=pop[i>>1]+(i&1);
	rep(i,m){
		int x=read(),y=read();
		to[x][y]=to[y][x]=1;
		int S=(1<<x-1)|(1<<y-1);
		dp[S][S]=1;
	}
	for(S=0;S<(1<<n);S++)for(T=S;T;--T&=S){
		if(!dp[S][T])continue;
		rep(i,n)if((S>>i-1)&1)
		rep(j,n)if(!((S>>j-1)&1)){
			if(!to[i][j])continue;
			int s=S|(1<<j-1);
			int t=T;if((T>>i-1)&1)t^=(1<<i-1);
			if(t>(1<<j-1))continue;
			t|=(1<<j-1);
			dp[s][t]+=dp[S][T];
		}
	}
	For(i,0,(1<<n)-1)if(pop[i]==k)res+=dp[(1<<n)-1][i];
	cout<<res<<endl;
	return 0;
}