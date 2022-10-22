#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=510;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,mx,k; 
int a[N],d[N];
int dp[N][N];
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),mx=read(),k=read();
	rep(i,n)d[i]=read();
	rep(i,n)a[i]=read();
	d[++n]=mx;a[n]=mx;
	memset(dp,0x3f,sizeof dp);dp[1][0]=0;
	For(i,2,n)For(j,1,i-1)For(l,0,k){
		if(l+i-j-1>k)break;
		chmn(dp[i][l+(i-j-1)],dp[j][l]+a[j]*(d[i]-d[j]));
	}
	int res=1e18;
	For(i,0,k)chmn(res,dp[n][i]);
	cout<<res<<endl;
	return 0;
}