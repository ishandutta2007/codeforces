#include<bits/stdc++.h>
using namespace std;
const int N = 1<<20;
const int mod = 998244353, g = 3;
typedef long long ll;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
int mul(int a,int b){return (ll)a*b%mod;}
int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
const int inv2 = qpow(2,mod-2);
/* math */
int w[N];
inline void init(){
	for(int step=1;step<N;step<<=1){
		w[step]=qpow(g, (mod-1)/(step<<1));;
	}
}
typedef vector<int> Poly;
namespace Poly_template {
	int rev[N];
	Poly Add(Poly a,Poly b){
		a.resize(max(a.size(),b.size()));
		for(size_t i=0;i<b.size();i++)a[i] = add(a[i],b[i]);
		return a;
	}
	Poly Sub(Poly a,Poly b){
		a.resize(max(a.size(),b.size()));
		for(size_t i=0;i<b.size();i++)a[i] = sub(a[i],b[i]);
		return a;
	}
	Poly rever(Poly x){
		reverse(x.begin(),x.end());
		return x;
	}
	void output(Poly func){
		for(size_t i=0;i<func.size();i++)printf("%d ",func[i]);
		puts("");
	}
	inline void DFT(int *t,int n,int tpe){
		int l=0;while(1<<l<n)++l;
		for(int i=1;i<n;i++) rev[i] = (rev[i>>1]>>1)|((i&1)<<(l-1));
		for(int i=0;i<n;i++) if(rev[i]>i) swap(t[rev[i]],t[i]);
		for(int step=1;step<n;step<<=1){
			int wn=w[step];
			// int wn = qpow(g, (mod-1)/(step<<1));
			for(int i=0;i<n;i+=step<<1){
				int w = 1;
				for(int j=0;j<step;j++,w = mul(w,wn)){
					int x = t[i+j], y = mul(w,t[i+j+step]);
					t[i+j] = add(x,y); t[i+j+step] = sub(x,y);
				}
			}
		}
		if(tpe==1)return ;
		for(int i=1;i<n-i;i++)swap(t[i],t[n-i]);
		int inv = qpow(n,mod-2);
		for(int i=0;i<n;i++)t[i] = mul(t[i], inv);
	}
	inline Poly NTT(Poly a, int n, Poly b, int m){
		int len = n+m-1,l=0;while(1<<l<len)++l;
		static Poly res;
		res.resize(1<<l); a.resize(1<<l),b.resize(1<<l);
		DFT(&a[0],1<<l,1),DFT(&b[0],1<<l,1);
		for(int i=0;i<(1<<l);i++)res[i] = mul(a[i],b[i]);
		DFT(&res[0],1<<l,-1);
		res.resize(len);
		return res;
	}
	Poly NTT(Poly a, Poly b){
		return NTT(a,a.size(),b,b.size());
	}
}
using namespace Poly_template;
int n,K;
typedef Poly poly;
int fac[N], ifac[N],Tfac[N];

int main()
{
	init();
	cin >> n >> K;
	fac[0]=ifac[0]=1;for(int i=1;i<=400000;i++)fac[i]=mul(fac[i-1],i);
	ifac[400000]=qpow(fac[400000],mod-2);for(int i=399999;i;i--)ifac[i]=mul(ifac[i+1],i+1);
	Tfac[0]=1;for(int i=1;i<=400000;i++)Tfac[i]=mul(Tfac[i-1],n+1-i);
	poly f(min(K+1,n+1)), g(min(K+1,n+1));
	int len=f.size();

	for(int i=0;i<len;i++){
		f[i]=mul(qpow(mod-1,i),qpow(Tfac[i],mod-2));
		f[i]=mul(f[i],ifac[i]);
		g[i]=mul(qpow(2,i),mul(ifac[i],ifac[i]));
	}
	// output(f);
	// output(g);
	f=NTT(f,g);
	f.resize(len);
	for(int i=1;i< min(len,K+1);i++){
		f[i]=mul(f[i], Tfac[i]);
		f[i]=mul(f[i], fac[i]);
		printf("%d ",f[i]);
	}
	for(int i=len;i<=K;i++){
		printf("%d ",0);
	}puts("");
}