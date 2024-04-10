#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

ll mo;
struct modint {
	ll v;
	modint(const ll a=0) { v=a; if(mo&&(v>=mo||v<0)) v=(v%mo+mo)%mo;}
	static modint pow(const modint& a,ll n=mo-2) {
		ll b=a.v,r=1;
		while(n) r=r*((n%2)?b:1)%mo,b=b*b%mo,n>>=1;
		return modint(r);
	}
	modint& operator+=(const modint& a) { v+=a.v; if(v>=mo) v-=mo; return *this;}
	modint& operator-=(const modint& a) { v+=mo-a.v; if(v>=mo) v-=mo; return *this;}
	modint& operator*=(const modint& a) { v=v*a.v%mo; return *this;}
	modint& operator/=(const modint& a) { assert(a.v!=0); *this*=pow(a); return *this;}
	modint operator+(const modint& a) const { modint res(*this); return res+=a;}
	modint operator-(const modint& a) const { modint res(*this); return res-=a;}
	modint operator*(const modint& a) const { modint res(*this); return res*=a;}
	modint operator/(const modint& a) const { modint res(*this); return res/=a;}
	friend ostream& operator<<(ostream& os, const modint& a){ os<<a.v; return os;}
};

int N,M;
modint dp1[505];
modint dp2[505];
modint dp3[505][505];
modint dp4[505][505];

ll comb(ll N_, ll C_) {
	const int NUM_=400001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>mo;
	dp1[0]=1;
	for(i=1;i<=N;i++) {
		for(j=1;j<=i;j++) {
			dp1[i]+=modint(i+1)*dp1[j-1]*dp1[i-j]*comb(i-1,j-1);
			dp2[i]+=modint(i+1)*(dp2[i-j]*dp1[j-1]+dp1[i-j]*dp2[j-1])*comb(i-1,j-1);
			dp2[i]+=dp1[j-1]*dp1[i-j]*comb(i-1,j-1)*(comb(j-1+1,2)+comb(i-j+1,2));
		}
	}
	dp3[0][0]=1;
	for(i=1;i<=N;i++) {
		FOR(j,i) {
			dp3[i][j]=dp3[i-1][j];
			dp4[i][j]=dp4[i-1][j];
			for(l=1;l<=j;l++) {
				dp3[i][j]+=dp1[l]*dp3[i-l-1][j-l]*comb(j,l);
				dp4[i][j]+=(dp1[l]*dp4[i-l-1][j-l]+dp2[l]*dp3[i-l-1][j-l])*comb(j,l);
			}
		}
		dp3[i][i]=dp1[i];
		dp4[i][i]=dp2[i];
	}
	
	cout<<dp4[N][M]<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}