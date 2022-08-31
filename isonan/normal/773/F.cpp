#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define double long double
 
typedef std::vector<int> poly;
int P; 
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int qsm(int a,long long b,int P){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*ans*a%P;
		a=1ll*a*a%P;
		b>>=1;
	}
	return ans;
}
double pi=3.141592653589793238462643383279502884197169399375105820974944;
struct complex{
	double x,y;
	complex operator+(complex a){return (complex){x+a.x,y+a.y};}
	complex operator-(complex a){return (complex){x-a.x,y-a.y};}
	complex operator*(complex a){return (complex){x*a.x-y*a.y,x*a.y+y*a.x};}
}a[800001],c[800001],b[800001],d[800001],w[1600001];
long long Lim=1,L=-1,R[800001];
int n,m;
void FFT(complex *a){
	for(int i=0;i<Lim;i++)if(i<R[i])std::swap(a[i],a[R[i]]);
	for(int i=1,lg=0;i<Lim;i<<=1,lg++)
		for(int j=0;j<Lim;j+=(i<<1))
			for(int k=0;k<i;k++){
				complex Nx=a[j+k],Ny=a[i+j+k]*w[i+k];
				a[j+k]=Nx+Ny;
				a[i+j+k]=Nx-Ny;
			}
}
poly operator*(poly F,poly G){
	int n=F.size(),m=G.size();
//	for(int i=0;i<n;i++)printf("%d ",F[i]);putchar('\n');
//	for(int i=0;i<m;i++)printf("%d ",G[i]);putchar('\n');
	while(Lim<=(n+m-1))Lim<<=1,++L;
	for(int i=0;i<Lim;i++)R[i]=(R[i>>1]>>1)|((i&1)<<L);
	for(int i=0;i<Lim;i++)a[i].x=a[i].y=b[i].x=b[i].y=c[i].x=c[i].y=d[i].x=d[i].y=0.;
	for(int i=0;i<n;i++)a[i].x=F[i]&16383,a[i].y=F[i]>>14;
	for(int i=0;i<m;i++)c[i].x=G[i]&16383,c[i].y=G[i]>>14;
	FFT(a),FFT(c);
	for(int i=0;i<Lim;i++){
		complex na,nb,nc,nd;
		const int pl=(Lim-1)&(Lim-i);
		na=a[i]+(complex){a[pl].x,-a[pl].y};
		nb=a[i]-(complex){a[pl].x,-a[pl].y};
		nc=c[i]+(complex){c[pl].x,-c[pl].y};
		nd=c[i]-(complex){c[pl].x,-c[pl].y};
		const complex v1=(complex){0.5,0},v2=(complex){0,-0.5};
		na=na*v1,nb=nb*v2,nc=nc*v1,nd=nd*v2;
		b[pl]=na*nc+na*nd*(complex){0,1};
		d[pl]=nb*nc+nb*nd*(complex){0,1};
	}
	FFT(b),FFT(d);
	F.clear();
	for(int i=0;i<=n+m-2;i++){
		long long v1=(b[i].x/Lim)+0.5,v2=(b[i].y/Lim)+(d[i].x/Lim)+0.5,v3=(d[i].y/Lim)+0.5;
		F.push_back((((v3%P)<<28)%P+((v2%P)<<14)%P+v1)%P);
	}
	F.resize(n+1);
//	for(int i=0;i<F.size();i++)printf("%d ",F[i]);putchar('\n');
	return F;
}
poly operator+(poly a,poly b){
	if(a.size()<b.size())a.resize(b.size());
	for(int i=0;i<b.size();i++)a[i]=add(a[i],b[i]);
	return a;
}
int ans=0;
poly f[2];
void solve(int x){
	if(!x){
		f[0].resize(n+1);
		f[1].resize(n+1);
		return; 
	}
	solve(x>>1);
	for(int i=1;i<=n;i+=2)ans=(ans+f[1][i])%P;
	poly g=f[0]+f[1],o0=f[0],o1=f[1];
	g[0]=1;
//	printf("solve %d\n",x);
//	for(int i=0;i<=n;i++)printf("%d ",g[i]);putchar('\n');
	if((x>>1)%2==1){
		poly tem;
		tem=f[1];
		f[1]=f[0];
		f[0]=tem;
	}
	f[0]=g*f[0]+o0;
	f[1]=g*f[1]+o1;
	if(x%2){
		for(int i=n;i;i--)f[1][i]=add(f[1][i],add(f[0][i-1],f[1][i-1]));
		f[1][1]=add(f[1][1],1);
	} 
//	for(int i=0;i<=n;i++)printf("%d ",f[0][i]);putchar('\n');
//	for(int i=0;i<=n;i++)printf("%d ",f[1][i]);putchar('\n');
}
signed main(){
	scanf("%d%d%d",&n,&m,&P);
	for(int i=0;(1<<i)<400000;i++){
		const complex wn=(complex){cos(pi/(1<<i)),sin(pi/(1<<i))};
		w[1<<i]=(complex){1,0};
		for(int j=1;j<(1<<i);j++)
			w[j+(1<<i)]=w[j+(1<<i)-1]*wn;
	}
	solve(m);
	printf("%d\n",ans);
}