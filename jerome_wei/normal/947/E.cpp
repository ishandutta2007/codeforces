#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
typedef long long ll;

const int mod=998244353;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
int mul(int a,int b){return (ll)a*b%mod;}
int qpow(int a,ll b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/*math*/

namespace Template_Poly{
	typedef vector<int> Poly;
	int rev[N];
	Poly Poly_add(Poly A,Poly B){
		A.resize(max(A.size(),B.size()));
		for(size_t i=0;i<B.size();i++)A[i]=add(A[i],B[i]);
		return A;
	}
	Poly Poly_sub(Poly A,Poly B){
		A.resize(max(A.size(),B.size()));
		for(size_t i=0;i<B.size();i++)A[i]=sub(A[i],B[i]);
		return A;
	}
	void DFT(int *t,int n,int type){
		int l=0;while(1<<l<n)++l;
		for(int i=0;i<n;i++)rev[i]=(rev[i>>1]>>1)|((i&1)<<(l-1));
		for(int i=0;i<n;i++)if(rev[i]>i)swap(t[rev[i]],t[i]);
		for(int step=1;step<n;step<<=1){
			int wn=qpow(3,(mod-1)/(step<<1));
			for(int i=0;i<n;i+=step<<1){
				int w=1;
				for(int k=0;k<step;k++,w=mul(w,wn)){
					int x=t[i+k],y=mul(t[i+k+step],w);
					t[i+k]=add(x,y),t[i+k+step]=sub(x,y);
				}
			}
		}
		if(type==1)return;
		for(int i=1;i<n-i;i++)swap(t[i],t[n-i]);
		int inv=qpow(n,mod-2);
		for(int i=0;i<n;i++)t[i]=mul(t[i],inv);
	}
	Poly NTT(Poly A,int n,Poly B,int m){
		static Poly res,PolA,PolB;
		PolA=A,PolB=B;
		int len=1;while(len < n+m)len<<=1;
		res.resize(len);
		PolA.resize(len),PolB.resize(len);
		DFT(&PolA[0],len,1);DFT(&PolB[0],len,1);
		for(int i=0;i<len;i++) res[i]= mul(PolA[i],PolB[i]);
		DFT(&res[0],len,-1);
		res.resize(n+m-1);
		return res;
	}
	Poly NTT(Poly A,Poly B){
		return NTT(A,A.size(),B,B.size());
	}
	Poly Poly_inv(Poly A,int n){
		if(n==1)return Poly(1,qpow(A[0],mod-2));
		int len=1<<((int)ceil(log2(n))+1);
		Poly x=Poly_inv(A,(n+1)>>1),y;
		x.resize(len),y.resize(len);
		for(int i=0;i<n;i++)y[i]=A[i];
		DFT(&x[0],len,1),DFT(&y[0],len,1);
		for(int i=0;i<len;i++)x[i]=mul(x[i],sub(2,mul(x[i],y[i])));
		DFT(&x[0],len,-1);
		x.resize(n);
		return x;
	}
	Poly Poly_inv(Poly A){
		return Poly_inv(A,A.size());
	}
	Poly Deri(Poly A){
		int n=A.size();
		for(int i=1;i<n;i++)A[i-1]=mul(A[i],i);
		A.resize(n-1);
		return A;
	}

	Poly Inte(Poly A){
		int n=A.size();
		A.resize(n+1);
		for(int i=n;i;i--)A[i]=mul(A[i-1],qpow(i,mod-2));
		A[0]=0;
		return A;
	}

	Poly ln(Poly A){
		int len=A.size();
		A=Inte(NTT(Deri(A),Poly_inv(A)));
		A.resize(len);
		return A;
	}

	Poly exp(Poly A,int n){
		if(n==1)return Poly(1,1);
		Poly x=exp(A,(n+1)>>1),y;
		x.resize(n);
		y=ln(x);
		for(int i=0;i<n;i++)y[i]=sub(A[i],y[i]);
		y[0]++;
		x=NTT(x,y);
		x.resize(n);
		return x;
	}
	Poly exp(Poly A){
		return exp(A,A.size());
	}

	Poly sqrt(Poly A,int n){
		if(n==1)return Poly(1,1);
		Poly x=sqrt(A,(n+1)>>1),y;
		x.resize(n),y.resize(n);
		for(int i=0;i<n;i++)y[i]=A[i];
		x=Poly_add(NTT(Poly_inv(x),y),x);
		int inv2=qpow(2,mod-2);
		for(int i=0;i<n;i++)
			x[i]=mul(x[i],inv2);
		x.resize(n);
		return x;
	}
	Poly sqrt(Poly A){
		return sqrt(A,A.size());
	}
	Poly rever(Poly A){
		reverse(A.begin(),A.end());
		return A;
	}
	void div(Poly A,Poly B,Poly &C,Poly &D){
		int n=A.size(),m=B.size();
		Poly ra=rever(A),rb=rever(B);
		ra.resize(n-m+1),rb.resize(n-m+1);
		C=NTT(ra,Poly_inv(rb));
		C.resize(n-m+1);
		C=rever(C);
		D=Poly_sub(A,NTT(B,C));
		D.resize(m);
	}
}
using namespace Template_Poly;
typedef Poly poly;
int fac[N], ifac[N];
inline void init(int n = 3e5){
	fac[0]=ifac[0]=1;for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=qpow(fac[n],mod-2);for(int i=n-1;i;i--)ifac[i]=mul(ifac[i+1],i+1);
}
int n;
poly g,f;

inline poly transfer(poly f,int d){
	poly t = poly(ifac,ifac+n+1);
	reverse(t.begin(), t.end());
	for(int i=0;i<=n;i++)f[i] = mul(mul(qpow(d,i),fac[i]) , f[i]);// cout << f[i] << "," ;puts("");
	t=NTT(t,f);
	f.resize(n+1);
	for(int i=0;i<=n;i++)f[i] = mul(t[n+i],mul(qpow(d,i),ifac[i]));// cout << f[i] << " ";puts("");
	return f;
}
ll m;
int main()
{
	init();
	cin >> n >> m;f.resize(n+1);
	for(int i=0;i<=n;i++)scanf("%d",&f[i]);
	g = transfer(f, 1);
	for(int i=0;i<=n;i++)g[i] = mul(g[i], qpow(qpow(i+1,m),mod-2));
	f = transfer(g, mod-1);
	for(int i=0;i<=n;i++)printf("%d ",f[i]);
	puts("");
	return 0;
}