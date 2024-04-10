#include<bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define SZ(x) ((int)x.size())
#define L(i,u) for (register int i=head[u]; i; i=nxt[i])
#define rep(i,a,b) for (register int i=(a); i<=(b); i++)
#define per(i,a,b) for (register int i=(a); i>=(b); i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
typedef long double ld;
template<class T> inline void read(T &x){
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
template<class T> inline void umin(T &x, T y){x=x<y?x:y;}
template<class T> inline void umax(T &x, T y){x=x>y?x:y;}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 59;
int n,mx;ld P,p[N][N],q[N][N],f[N][N],ans[N];
struct mtr{
	ld a[N][N];//f: 1..mx ans: mx+1..2*mx
	mtr(){memset(a,0,sizeof(a));}
}b[N];
inline mtr mul(const mtr&a,const mtr&b){
	mtr c;
	rep(i,0,mx)rep(j,0,mx)rep(k,0,mx)
		c.a[i][k]+=a.a[i][j]*b.a[j][k];
	return c;
}
inline void trans(const mtr &a){
	ld b[N]={0};
	rep(i,0,mx)rep(j,0,mx)b[i]+=ans[j]*a.a[i][j];
	rep(i,0,mx)ans[i]=b[i];
}
int main() {
	read(n);int _;read(_);P=(ld)1.0*_/1e9;//P:1  1-P:2
	p[1][1]=P;p[1][2]=1-P;
	q[1][2]=1-P;
	mx=min(50,n+1);
	rep(i,2,mx+2){
		p[i][1]=P;p[i][2]=1-P+P*P;
		q[i][2]=1-P;
		rep(j,3,i+1)p[i][j]=p[i][j-1]*p[i-1][j-1],q[i][j]=q[i][j-1]*p[i-1][j-1];
	}
	rep(i,1,mx+2)rep(j,1,mx)q[i][j]=q[i][j]*(1-p[i-1][j]);
	per(i,mx+2,1)rep(j,1,mx)p[i][j]=p[i][j]*(1-p[i-1][j]);
	/*rep(i,1,mx+1){
		rep(j,1,mx)printf("%.3lf ",(double)p[i][j]);puts("");
	}
	rep(i,1,mx+1){
		rep(j,1,mx)printf("%.3lf ",(double)q[i][j]);puts("");
	}*/
	ans[0]=1;rep(i,1,mx)ans[i]=i;
	rep(i,2,mx+2){
		rep(j,2,mx){
			b[i].a[j][0]=j;
			ld s=0;rep(k,1,j-1)s+=p[i-1][k];
			rep(k,1,j-1)b[i].a[j][k]+=p[i-1][k]/s;
		}
		rep(j,1,1){
			b[i].a[j][0]=j;
			ld s=0;rep(k,2,mx)s+=q[i-1][k];
			rep(k,2,mx)b[i].a[j][k]+=q[i-1][k]/s;
		}
		b[i].a[0][0]=1;
	}
	int cc=min(mx+1,n);rep(i,2,cc)trans(b[i]);
	int T=n-cc;mtr E=b[mx+2];
	while(T){
		if(T&1)trans(E);E=mul(E,E);T>>=1;
	}
//	rep(i,1,mx)printf("%lf ",(double)ans[i]);puts("");
	double res=0;rep(i,1,mx)res+=ans[i]*p[min(n,mx+1)][i];
	printf("%lf\n",res);
	return 0;
}