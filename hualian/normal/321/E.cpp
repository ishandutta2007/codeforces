#include<bits/stdc++.h>
#define pb push_back
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  a) for(int i=1,i##end=a;i<=i##end;i++)
using namespace std;
const int N=4e3+9;
const int K=810;
void chmx(int &x,int y){(x<y)?(x=y):(0);}
void chmn(int &x,int y){(x>y)?(x=y):(0);}
inline int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,k,a[N][N];
int dp[K][N];
int *f,*g;
int w(int i,int j){if(i>j)return 0;return a[j][j]-a[j][i-1]-a[i-1][j]+a[i-1][i-1];}
void solve(int l,int r,int L,int R){
	if(l>r)return;
	int mid=(l+r)>>1,p=0,nr=min(mid,R);
	For(i,L,nr)if(f[mid]>g[i]+w(i+1,mid))f[mid]=g[i]+w(i+1,mid),p=i;
	solve(l,mid-1,L,p);solve(mid+1,r,p,R);
}
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	n=read(),k=read();
	rep(i,n)rep(j,n)a[i][j]=read();
	rep(i,n)rep(j,n)a[i][j]+=a[i-1][j]+a[i][j-1]-a[i-1][j-1];
	memset(dp,0x3f,sizeof dp);
	rep(i,n)dp[1][i]=w(1,i);
	For(i,2,k){f=dp[i];g=dp[i-1];solve(1,n,1,n);}
	cout<<dp[k][n]/2<<endl;
	return 0;
}