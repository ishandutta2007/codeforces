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

int N,K,Q;
int num[1010101];
ll co[1010101];
ll mo=1000000007;

ll combi(ll N_, ll C_) {
	const int NUM_=1000001;
	static ll fact[NUM_+1],factr[NUM_+1],inv[NUM_+1];
	if (fact[0]==0) {
		inv[1]=fact[0]=factr[0]=1;
		for (int i=2;i<=NUM_;++i) inv[i] = inv[mo % i] * (mo - mo / i) % mo;
		for (int i=1;i<=NUM_;++i) fact[i]=fact[i-1]*i%mo, factr[i]=factr[i-1]*inv[i]%mo;
	}
	if(C_<0 || C_>N_) return 0;
	return factr[C_]*fact[N_]%mo*factr[N_-C_]%mo;
}

template<typename V> vector<V> enumdiv(V n) {
	vector<V> S;
	for(V i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(i=1;i<=1000000;i++) co[i]=i;
	for(i=1;i<=1000000;i++) {
		for(j=i*2;j<=1000000;j+=i) co[j]-=co[i];
	}
	
	cin>>N>>K>>Q;
	while(N--) {
		cin>>x;
		auto v = enumdiv(x);
		FORR(r,v) num[r]++;
	}
	ll cur=0;
	for(i=1;i<=1000000;i++) (cur += co[i]*combi(num[i],K))%=mo;
	while(Q--) {
		cin>>x;
		auto v = enumdiv(x);
		FORR(r,v) {
			cur-=co[r]*combi(num[r],K)%mo;
			num[r]++;
			cur+=co[r]*combi(num[r],K)%mo;
		}
		cur=(cur%mo+mo)%mo;
		cout<<cur<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}