#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K,Q,L;
int A[303030];
ll B[303030];
vector<ll> BV[5];
const int mo=998244353;

inline int multmod(int a,int b,int mo=mo) {
	int d,r;
	if(a==0 || b==0) return 0;
	if(a==1 || b==1) return max(a,b);
	__asm__("mull %4;"
	        "divl %2"
		: "=d" (r), "=a" (d)
		: "r" (mo), "a" (a), "d" (b));
	return r;
}
int modpow(int a, int n = mo-2) {
	int r=1;
	while(n) r=multmod(r,(n%2)?a:1),a=multmod(a,a),n>>=1;
	return r;
}

vector<ll> fft(vector<ll> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		ll wn=modpow(5,(mo-1)/m);
		if(rev) wn=modpow(wn);
		for(i=0;i<n;i+=m) {
			ll w=1;
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				ll t1=v[j1],t2=multmod(w,v[j2]);
				v[j1]=t1+t2;
				v[j2]=t1+mo-t2;
				while(v[j1]>=mo) v[j1]-=mo;
				while(v[j2]>=mo) v[j2]-=mo;
				w=multmod(w,wn);
			}
		}
	}
	if(rev) {
		ll rv = modpow(n);
		FOR(i,n) v[i]=multmod(v[i],rv);
	}
	return v;
}

vector<ll> MultPoly(vector<ll> P,vector<ll> Q,bool resize=false) {
	if(resize) {
		int maxind=0,pi=0,qi=0,i;
		int s=2;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		P.resize(s*2);Q.resize(s*2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]=multmod(P[i],Q[i]);
	return fft(P,true);
}

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

ll p2[404040];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,401010) p2[i+1]=p2[i]*2%mo;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x;
		A[x]++;
	}
	FOR(i,K) {
		cin>>B[i];
	}
	sort(B,B+K);
	
	FOR(i,K) {
		vector<ll> X,Y;
		int one=0,two=0;
		FOR(j,B[i]) {
			if(A[j]==1) one++;
			if(A[j]>=2) two++;
		}
		
		X.resize(one+1);
		FOR(j,one+1) X[j]=comb(one,j)*p2[j]%mo;
		Y.resize(2*two+1);
		FOR(j,2*two+1) Y[j]=comb(2*two,j)%mo;
		BV[i]=MultPoly(X,Y,1);
	}
	
	
	cin>>Q;
	while(Q--) {
		ll ret=0;
		cin>>L;
		FOR(i,K) {
			ll v=(L-2*B[i]-2)/2;
			
			if(v>=0 && BV[i].size()>=v+1) ret+=BV[i][v];
		}
		cout<<ret%mo<<endl;
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}