#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=110;
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
int sum;
int dp[N][N*N];
int a[N],b[N];
//ij 
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	int n=read();int all=0;
	memset(dp,0xc0,sizeof dp);dp[0][0]=0;
	rep(i,n)a[i]=read(),b[i]=read(),all+=b[i]; 
	rep(i,n)Rof(k,n,1)Rof(j,10000,a[i])
		chmx(dp[k][j],dp[k-1][j-a[i]]+b[i]);
	rep(k,n){
		int ans=0;
		rep(j,10000){
			chmx(ans,min(dp[k][j]*2+(all-dp[k][j]),2*j));
		}
		cout<<1.0*ans/2<<endl;
	}
	return 0;
}