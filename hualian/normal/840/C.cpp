#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
using namespace std;
const int N=3e3+9;
const int p=1e9+7;
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
int n;
int dp[N][N];//ij 
map<int,int>mp;
int sta[N],top;
int fac[N],ifac[N];
int inv(int x,int base=p-2){
	int res=1;
	while(base){
		if(base&1)res=res*x%p;
		x=x*x%p;
		base>>=1;
	}return res;
}
void init(int n=N-1){
	fac[0]=1;rep(i,n)fac[i]=fac[i-1]*i%p;
	ifac[n]=inv(fac[n]);Rof(i,n-1,0)ifac[i]=ifac[i+1]*(i+1)%p;
	assert(fac[10]*ifac[10]%p==1);
}
int C(int n,int m){return fac[n]*ifac[m]%p*ifac[n-m]%p;}
int calc(int n,int m) {//nm, 
	return C(n-1,m-1)*fac[n]%p;
}
int F[N];//n 
signed main(){
//	printf("%.5lf\n",(&pppp-&ppp)/1024.0/1024.0);
	n=read();init();
	rep(i,n){
		int x=read(),A=1,cnt;
		for(int j=2;j*j<=x;j++){
			cnt=0;
			while(x%j==0)cnt^=1,x/=j;
			A*=cnt?j:1;
		}if(x!=1)A*=x;
		if(!mp[A])mp[A]=++top,sta[top]=1;
		else sta[mp[A]]++;
	}
	dp[0][0]=1;
	rep(i,top)For(k,0,sta[i]){//xy 
		int w=calc(sta[i],k);
		For(j,0,n-k)
			(dp[i][j+k]+=C(j+k,j)*dp[i-1][j]%p*w)%=p;
	}
	int ans=0,op=-1;
	For(i,1,n)F[n-i]=dp[top][i];//nin-i 
//	cout<<F[3]<<endl;
	For(i,0,n){
		op=-op;
		(ans+=op*F[i]*C(i,0))%=p;
	}cout<<(ans+p)%p<<endl;
	return 0;
}