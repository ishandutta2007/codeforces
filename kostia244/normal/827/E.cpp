#pragma GCC optimize("Ofast")
//#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4.1,tune=native")
#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(v) (v).begin(),(v).end()
using namespace std;
typedef long long int ll;
const int inf = 0x3fffffff; const ll INF = 0x1fffffffffffffff; const double eps=1e-12;
template<class T>inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T>inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
//end

template<unsigned mod=998244353>struct fp {
   unsigned v;
   static unsigned get_mod(){return mod;}
   unsigned inv() const{
      int tmp,a=v,b=mod,x=1,y=0;
      while(b)tmp=a/b,a-=tmp*b,swap(a,b),x-=tmp*y,swap(x,y);
      if(x<0)x+=mod; return x;
   }
   fp():v(0){}
   fp(ll x):v(x>=0?x%mod:mod+(x%mod)){}
   fp pow(ll t){fp res=1,b=*this; while(t){if(t&1)res*=b;b*=b;t>>=1;}return res;}
   fp& operator+=(const fp& x){if((v+=x.v)>=mod)v-=mod;return *this;}
   fp& operator-=(const fp& x){if((v+=mod-x.v)>=mod)v-=mod; return *this;}
   fp& operator*=(const fp& x){v=ll(v)*x.v%mod; return *this;}
   fp& operator/=(const fp& x){v=ll(v)*x.inv()%mod; return *this;}
   fp operator+(const fp& x)const{return fp(*this)+=x;}
   fp operator-(const fp& x)const{return fp(*this)-=x;}
   fp operator*(const fp& x)const{return fp(*this)*=x;}
   fp operator/(const fp& x)const{return fp(*this)/=x;}
   bool operator==(const fp& x)const{return v==x.v;}
   bool operator!=(const fp& x)const{return v!=x.v;}
}; using Fp=fp<>;
template<typename T>struct factorial {
   vector<T> Fact,Finv,Inv;
   factorial(int maxx){
      Fact.resize(maxx); Finv.resize(maxx); Inv.resize(maxx);
      Fact[0]=Fact[1]=Finv[0]=Finv[1]=Inv[1]=1; unsigned mod=Fp::get_mod();
      rep(i,2,maxx){
         Fact[i]=Fact[i-1]*i;
         Inv[i]=Inv[mod%i]*(mod-mod/i);
         Finv[i]=Finv[i-1]*Inv[i];
      }
   }
   T fact(int n,bool inv=0){if(inv)return Finv[n];else return Fact[n];}
   T inv(int n){return Inv[n];}
   T nPr(int n,int r){if(n<0||n<r||r<0)return Fp(0);else return Fact[n]*Finv[n-r];}
   T nCr(int n,int r){if(n<0||n<r||r<0)return Fp(0);else return Fact[n]*Finv[r]*Finv[n-r];}
};

template<typename T,unsigned p>struct NTT{
   vector<T> rt,irt;
   NTT(int lg=21){
      unsigned mod=T::get_mod();
      T prt=p; rt.resize(1<<lg,1); irt.resize(1<<lg,1);
      for(int w=0;w<lg;w++){
         int mask=(1<<w)-1; T g=prt.pow((mod-1)>>w),ig=g.inv();
         for(int i=0;i<mask;i++){
            rt[mask+i+1]=g*rt[mask+i];
            irt[mask+i+1]=ig*irt[mask+i];
         }
      }
   }
   void ntt(vector<T>& f,bool inv=0){
      int n=f.size();
      if(inv){
         for(int i=1;i<n;i<<=1)for(int j=0;j<n;j+=i*2){
            for(int x=j,y=i+j,z=i*2-1;x<i+j;x++,y++,z++){
               f[y]*=irt[z]; T tmp=f[x]-f[y]; f[x]+=f[y]; f[y]=tmp;
            }
         } T mul=T(n).inv(); rep(i,0,n)f[i]*=mul;
      }else{
         for(int i=n>>1;i;i>>=1)for(int j=0;j<n;j+=i*2){
            for(int x=j,y=i+j,z=i*2-1;x<i+j;x++,y++,z++){
               T tmp=f[x]-f[y]; f[x]+=f[y]; f[y]=tmp*rt[z];
            }
         }
      }
   }
   vector<T> conv(vector<T> a,vector<T> b){
      int n=a.size()+b.size()-1,m=(n&(n-1)?1<<(32-__builtin_clz(n)):n);
      a.resize(m); b.resize(m); ntt(a); ntt(b);
      rep(i,0,m)a[i]*=b[i]; ntt(a,1); a.resize(n); return a; 
   }
};
NTT<Fp,3> ntt;
vector<Fp> multiply(vector<Fp> a,vector<Fp> b){return ntt.conv(a,b);};

signed main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		int n;
		cin >> n >> s;
		vector<Fp> a(n), b(n);
		for(int i = 0; i < n; i++) {
			a[i] = (s[i]=='V');
			b[i] = (s[i]=='K');
		}
		reverse(ALL(b));
		vector<Fp> r = multiply(a, b);
		vector<int>ans;
		for(int i = 1; i <= n; i++) {
			int ok = 1;
			for(int j = i; j < n; j += i) ok &= r[n+j-1] == 0 && r[n-1-j] == 0;
			if(ok) ans.push_back(i);
		}
		cout << ans.size() << '\n';
		for(auto &i : ans) cout << i << " "; cout << '\n';
	}
}
//?VK
//??V
//K?