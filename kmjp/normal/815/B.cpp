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

int N;
ll A[202020];
ll mo=1000000007;

ll combi(ll N_, ll C_) {
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

ll hoge(vector<ll> a) {
	int v=1;
	int i;
	string s;
	while(a.size()>1) {
		vector<ll> b;
		FOR(i,a.size()-1) {
			b.push_back((mo+a[i]+v*a[i+1])%mo);;
			v=-v;
		}
		s+=" ";
		swap(a,b);
	}
	return a[0];
}

vector<ll> getP(int N) {
	vector<ll> P;
	int M=N/4*4;
	int i;
	FOR(i,M/2) {
		P.push_back(combi(M/2-1,i));
		P.push_back(mo-combi(M/2-1,i));
	}
	if(M<N) {
		vector<ll> Q;
		M++;
		P.push_back(0);
		Q.push_back(1);
		int v=1;
		FOR(i,M-1) {
			Q.push_back((mo+P[i+1]+v*P[i])%mo);
			v=-v;
		}
		swap(P,Q);
	}
	if(M<N) {
		vector<ll> Q;
		M++;
		P.push_back(0);
		Q.push_back(1);
		FOR(i,M-1) Q.push_back((P[i+1]+P[i])%mo);
		swap(P,Q);
	}
	if(M<N) {
		vector<ll> Q;
		M++;
		P.push_back(0);
		Q.push_back(1);
		int v=1;
		FOR(i,M-1) {
			Q.push_back((mo+P[i+1]+v*P[i])%mo);
			v=-v;
		}
		swap(P,Q);
	}
	return P;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	auto V=getP(N);
	ll ret=0;
	FOR(i,N) {
		ll v;
		cin>>v;
		ret += v*V[i];
		ret = (ret%mo+mo)%mo;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}