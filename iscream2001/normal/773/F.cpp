#pragma GCC optimize("-O3")
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<cstring>
#include<map>
#include<queue>
#include<set>
#include<cmath>
#include<vector>
#define DB long double
#define LL long long
#define ui unsigned int
#define ull unsigned long long
using namespace std;
  
inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
void Out(int x){
    if(x>9) Out(x/10);
    putchar('0'+x%10);
}
LL gcd(LL x,LL y){
    if(!y) return x;
    return gcd(y,x%y);
}
LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;
    }
    return re;
}
const DB eps=1e-6;
const DB PI=acos(-1);
const LL inf=1e16;
const int N=2e5+50;

struct V{
	DB x,y;
	V(DB _x=0,DB _y=0){x=_x;y=_y;}
};
V operator + (V a,V b){return V(a.x+b.x,a.y+b.y);}
V operator - (V a,V b){return V(a.x-b.x,a.y-b.y);}
V operator * (V a,V b){return V(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}
struct FFT{
	int n;
	int rev[200000];
	void init(int m){
		int k=0;n=1;
		while(n<m){++k;n<<=1;}
		for(int i=0;i<n;++i){
			int t=0;
			for(int j=0;j<k;++j) if(i&(1<<j)) t|=(1<<(k-j-1));
			rev[i]=t;
		}
	}
	void DFT(V *a,int flag){
		for(int i=0;i<n;++i) if(i<rev[i]) swap(a[i],a[rev[i]]);
		for(int l=2;l<=n;l<<=1){
			int m=l>>1;
			V wn(cos(2*PI/l),flag*sin(2*PI/l));
			for(V *p=a;p!=a+n;p+=l){
				V w(1,0);
				for(int k=0;k<m;++k){
					V t=w*p[k+m];
					p[k+m]=p[k]-t;
					p[k]=p[k]+t;
					w=w*wn;
				}
			}
		}
		if(flag==-1) for(int i=0;i<n;++i) a[i].x/=n;
	}
	void CHENG(V *a,V *b,int m){
		init(m);
		DFT(a,1);DFT(b,1);
		for(int i=0;i<n;++i) a[i]=a[i]*b[i];
		DFT(a,-1);
	}
}fft;
V a[N],b[N];
LL n,mx,P,ans=0;
LL A[2][N],B[N];
LL C[2][N];
void BZ(int x){
	x=x&1;
	for(int i=0;i<=n;++i) B[i]=(A[0][i]+A[1][i])%P;
	for(int i=0;i<=n;++i) {b[i].x=B[i];b[i].y=0;}
	fft.DFT(b,1);
	for(int i=1;i<=n;++i) {a[i].x=A[x][i];a[i].y=0;}
	fft.DFT(a,1);
	for(int i=0;i<fft.n;++i) a[i]=a[i]*b[i];
	fft.DFT(a,-1);
	for(int i=0;i<=n;++i) C[0][i]=(LL)(a[i].x+0.5);
	for(int i=0;i<fft.n;++i) a[i].x=a[i].y=0;
	for(int i=1;i<=n;++i) {a[i].x=A[x^1][i];a[i].y=0;}
	fft.DFT(a,1);
	for(int i=0;i<fft.n;++i) a[i]=a[i]*b[i];
	fft.DFT(a,-1);
	for(int i=0;i<=n;++i) C[1][i]=(LL)(a[i].x+0.5);
	for(int i=0;i<fft.n;++i) a[i].x=a[i].y=b[i].x=b[i].y=0;
	for(int i=0;i<=n;++i){
		A[0][i]=(A[0][i]+C[0][i])%P;
		A[1][i]=(A[1][i]+C[1][i])%P;
	}
}
void add(int x){
	x=(x+1)&1;
	for(int i=0;i<=n;++i) B[i]=(A[0][i]+A[1][i])%P;
	for(int i=0;i<n;++i) A[x][i+1]=(A[x][i+1]+B[i])%P;
}
int main(){
	scanf("%I64d%I64d%I64d",&n,&mx,&P);
	fft.init(n+n+3);
	int now=31;
	while((mx&(1<<now))==0) --now;
	int i=0;
	A[0][0]=1;
	for(;now>=1;--now){
		BZ(i);i<<=1;
		if(mx&(1<<now)){
			add(i);
			++i;
		}
		for(int i=1;i<=n;i+=2)
			ans=(ans+A[1][i])%P;
	}
	printf("%I64d\n",ans);
	return 0;
}
/*

*/