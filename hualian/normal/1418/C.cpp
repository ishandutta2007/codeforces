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
int dp[N][2];
int a[N];
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	int T=read();
	while(T--){
		int n=read();
		rep(i,n)dp[i][0]=dp[i][1]=1e9;
		rep(i,n)a[i]=read(); 
		dp[0][0]=0;dp[0][1]=1e9;
		rep(i,n)For(j,0,1){
			chmn(dp[i][j],dp[i-1][j^1]+j*a[i]);
			if(i-2>=0)chmn(dp[i][j],dp[i-2][j^1]+j*(a[i]+a[i-1]));
		}
		cout<<min(dp[n][1],dp[n][0])<<endl;
	}
	return 0;
}