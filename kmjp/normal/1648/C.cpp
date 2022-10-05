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

int N,M;
const ll mo=998244353;
int S[202020],T[202020];

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}

int rev2=(mo+1)/2;
template<class V,int NV> class SegTree_Mul {
public:
	vector<V> sum,mul; // sum stores val after muladd
	SegTree_Mul(){sum.resize(NV*2,1); mul.resize(NV*2,1);};

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum[k];
		x=max(x,l);
		y=min(y,r);
		V ret=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		return (ret*mul[k])%mo;
	}
	void propagate(int k,int s) {
		(mul[k*2]*=mul[k])%=mo;
		(sum[k*2]*=mul[k])%=mo;
		(mul[k*2+1]*=mul[k])%=mo;
		(sum[k*2+1]*=mul[k])%=mo;
		
		mul[k]=1;
	}

	void domul(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			(mul[k]*=v)%=mo;
			(sum[k]*=v)%=mo;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			domul(x,y,v,l,(l+r)/2,k*2);
			domul(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=(sum[k*2]+sum[k*2+1])%mo;
		}
	}
};

SegTree_Mul<ll,1<<18> st;
const int NUM_=400001;
static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];

void solve() {
	int i,j,k,l,r,x,y; string s;

	inv[1]=fact[0]=factr[0]=1;
	for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
	for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	
	cin>>N>>M;
	
	FOR(i,N) {
		cin>>x;
		S[x]++;
	}
	FOR(i,M) cin>>T[i];
	
	ll P=fact[N-1];
	FOR(i,201010) P=P*factr[S[i]]%mo;
	FOR(i,201010) st.domul(i,i+1,P*S[i]%mo);
	
	ll ret=0;
	int lef=N-1;
	FOR(i,min(N,M)) {
		ret+=st.getval(0,T[i]);
		if(S[T[i]]==0) break;
		ll p=S[T[i]]*modpow(lef)%mo;
		st.domul(0,T[i],p);
		st.domul(T[i]+1,201010,p);
		p=(S[T[i]]-1)*modpow(lef)%mo;
		st.domul(T[i],T[i]+1,p);
		lef--;
		S[T[i]]--;
	}
	if(i==min(N,M)&&N<M) ret++;
	
	cout<<ret%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}