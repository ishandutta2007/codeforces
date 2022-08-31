#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define int long long
#define double long double

typedef std::vector<int> poly;
int P; 
inline int mul(const int &a,const int &b){return 1ll*a*b%P;}
inline int add(int a,const int &b){a+=b;return(a>=P)?a-P:a;}
inline int sub(int a,const int &b){a-=b;return (a<0)?a+P:a;}
int qsm(int a,long long b){
	int ans=1;
	while(b){
		if(b&1)ans=mul(ans,a);
		a=mul(a,a);
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
long long n,m,Lim=1,L=-1,R[800001];
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
//	for(int i=0;i<F.size();i++)printf("%d ",F[i]);putchar('\n');
	return F;
}
int g;
bool isprime(int x){
	for(int i=2;1ll*i*i<=x;i++)
		if(x%i==0)return 0;
	return 1;
}
void bluestein(poly &f){
	for(int i=0;i<f.size();i++)f[i]=mul(f[i],qsm(g,(1ll*i*(i-1))/2));
	poly h(n<<1);
//	for(int i=0;i<n;i++)
//		for(int j=0;j<n;j++)
//			h[i]=add(h[i],mul(f[j],qsm(g,1ll*i*j)));
	for(int i=0;i<h.size();i++)h[i]=qsm(qsm(g,P-2),(1ll*i*(i-1))/2);
	std::reverse(h.begin(),h.end());
	f=f*h;
	f.resize(n<<1);
	std::reverse(f.begin(),f.end());
	f.resize(n);
	for(int i=0;i<f.size();i++)f[i]=mul(f[i],qsm(g,(1ll*i*(i-1))/2));
}
std::vector<int>vec;
int pri[11],top;
signed main(){
	scanf("%lld",&n);
	if(n==1){
		int b,c;
		scanf("%lld%lld",&b,&c);
		for(int i=b-10000;i<=b+10000;i++)
			if(1ll*(b-i)*(b-i)==c)vec.push_back(i);
		printf("%d\n",(int)vec.size());
		for(int i=0;i<vec.size();i++)printf("%lld\n",vec[i]);
		return 0;
	}
	for(int i=5000000;i;i++)
		if(i%n==1){
			P=i;
			break;
		}
	while(!isprime(P))P+=n;
	int tem=P-1;
	for(int j=2;1ll*j*j<=tem;j++)
		if(tem%j==0){
			pri[++top]=j;
			while(tem%j==0)tem/=j;
		}
	if(tem>1)pri[++top]=tem;
	for(g=2;;g++){
		bool cando=1;
		for(int i=1;i<=top;i++)if(qsm(g,(P-1)/pri[i])==1)cando=0;
		if(cando)break;
	}
	g=qsm(g,(P-1)/n);
	g=qsm(g,P-2);
	int x=0;
	poly B(n),C(n),D(n),E,F;
	for(int i=0;i<n;i++)scanf("%lld",&B[i]),x+=B[i]*B[i];
	std::reverse(B.begin()+1,B.end());
	E=B;
	for(int i=0;i<n;i++)scanf("%lld",&C[i]),C[i]-=x;
	F=C;
	for(int i=0;i<n;i++)C[i]=(C[i]%P+P)%P;
	for(int i=0;(1<<i)<400000;i++){
		const complex wn=(complex){cos(pi/(1<<i)),sin(pi/(1<<i))};
		w[1<<i]=(complex){1,0};
		for(int j=1;j<(1<<i);j++)
			w[j+(1<<i)]=w[j+(1<<i)-1]*wn;
	}
	int inv=qsm(n,P-2);
	for(int i=0;i<n;i++)C[i]=P-C[i];
	for(int i=0;i<n;i++)D[i]=1;
	poly H=B;
	bluestein(B);
//	bluestein(B);
//	for(int i=0;i<n;i++)printf("%d ",B[i]);putchar('\n');
	for(int i=0;i<n;i++)B[i]=qsm(B[i],P-2);
	for(int i=0;i<n;i++)B[i]=mul(B[i],(P+1)>>1);
	bluestein(C);
	bluestein(D);
	for(int i=0;i<n;i++)C[i]=mul(C[i],B[i]);
	for(int i=0;i<n;i++)D[i]=mul(D[i],B[i]);
	bluestein(C);
	bluestein(D);
	std::reverse(C.begin()+1,C.end());
	std::reverse(D.begin()+1,D.end());
	for(int i=0;i<n;i++)C[i]=mul(C[i],inv);
	for(int i=0;i<n;i++)D[i]=mul(D[i],inv);
//	for(int i=0;i<n;i++)B[i]=mul(B[i],inv);
//	poly E(n);
//	for(int i=0;i<n;i++)
//		for(int j=0;j<n;j++)
//			E[(i+j)%n]=add(E[(i+j)%n],mul(H[i],B[j]));
//	for(int i=0;i<n;i++)printf("%d ",E[i]);putchar('\n');
//	for(int i=0;i<n;i++)printf("%d ",D[i]);putchar('\n');
	int t0=0,t1=P-1,t2=0;
	for(int i=0;i<n;i++){
		t0=add(t0,mul(C[i],C[i]));
		t1=add(t1,mul(2,mul(C[i],D[i])));
		t2=add(t2,mul(D[i],D[i]));
	}
	for(int i=0;i<P;i++){
		int u=add(t0,add(mul(t1,i),mul(mul(t2,i),i)));
		if(u==0)vec.push_back(i);
	}
	for(int i=0;i<(int)vec.size();i++){
		poly g(n);
		int x=0;
		for(int j=0;j<n;j++){
			int v=add(C[j],mul(D[j],vec[i]));
			if(v>(P>>1))v-=P;
			g[j]=v;
			x+=1ll*g[j]*g[j]%998244353;
		}
		int o=P;
		P=998244353;
//		for(int j=0;j<n;j++)printf("%d ",g[j]);putchar('\n');
		for(int j=0;j<n;j++)g[j]=(g[j]%P+P)%P;
		for(int j=0;j<n;j++)E[j]=(E[j]%P+P)%P;
		for(int j=0;j<n;j++)F[j]=(F[j]%P+P)%P;
		g=g*E;
		for(int i=n;i<g.size();i++)(g[i%n]+=g[i])%=P;
//		for(int i=0;i<n;i++)printf("%d ",F[i]);putchar('\n');
//		printf("%lld\n",x);
		bool cando=1;
		for(int i=0;i<n;i++)if((F[i]-x+2*g[i])%998244353!=0)cando=0;
		P=o;
		if(!cando){
			std::swap(vec[i],vec.back());
			vec.pop_back();
			--i;
		}
	}
	if(vec.size()==2){
		int v1=add(C[0],mul(D[0],vec[0])),v2=add(C[0],mul(D[0],vec[1]));
		if(v1>(P>>1))v1-=P;
		if(v2>(P>>1))v2-=P;
		if(v1>v2)std::swap(vec[0],vec[1]);
	}
	printf("%d\n",(int)vec.size());
	for(int i=0;i<vec.size();i++){
		for(int j=0;j<n;j++){
			int v=add(C[j],mul(D[j],vec[i]));
			if(v>(P>>1))v-=P;
			printf("%lld ",v);
		}
		putchar('\n');
	}
}