#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=5010;
const int p=998244353;
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
int n,a[N];
int dp[2][N][N];
int iv[N];
int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout);
	int T=read();
	iv[0]=1;rep(i,5001)iv[i]=iv[i-1]*inv(i)%p;
	while(T--){
		int res=1;
		n=read();rep(i,n)a[i]=0;rep(i,n)a[read()]++;
		int f=0;
		rep(i,n)res=res*iv[a[i]]%p;
		For(i,0,n+1)For(j,0,n+1)dp[0][i][j]=dp[1][i][j]=0;dp[0][1][0]=1;
		int last=n;Rof(i,n,1)if(a[i]){last=i;break;}
		rep(i,last-1)For(j,0,n-a[i]){//ij 
			(dp[0][i+1][j+a[i]]+=dp[0][i][j])%=p;
			(dp[1][i+1][j+a[i]]+=dp[1][i][j])%=p;
			if(a[i])(dp[1][i+1][j+a[i]-1]+=dp[0][i][j]*a[i])%=p;
			if(j&&a[i]){dp[1][i+1][j+a[i]-2]=(dp[1][i][j]*j%p*a[i]+dp[1][i+1][j+a[i]-2])%p;}
		}
		res=res*dp[1][last][0]%p;
		if(a[last]>1)res=0;
		cout<<res<<endl;
	}
	return 0;
}