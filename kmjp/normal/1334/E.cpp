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

ll D;
int Q;
vector<ll> P;

const ll mo=998244353;
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
	
	cin>>D>>Q;
	
	ll v=D;
	for(ll a=2;a*a<=v;a++) {
		if(v%a==0) {
			P.push_back(a);
			while(v%a==0) v/=a;
		}
	}
	if(v>1) P.push_back(v);
	
	while(Q--) {
		ll U,V;
		cin>>U>>V;
		
		vector<int> A,B,C;
		int sum[2]={};
		FOR(i,P.size()) {
			x=0;
			while(U%P[i]==0) x++,U/=P[i];
			while(V%P[i]==0) x--,V/=P[i];
			A.push_back(max(x,0));
			B.push_back(max(-x,0));
			sum[0]+=A.back();
			sum[1]+=B.back();
		}
		ll ret=1;
		FORR(c,A) {
			ret=ret*comb(sum[0],c)%mo;
			sum[0]-=c;
		}
		FORR(c,B) {
			ret=ret*comb(sum[1],c)%mo;
			sum[1]-=c;
		}
		cout<<ret<<endl;
		
		
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}