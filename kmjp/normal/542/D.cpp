#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------


const int prime_max = 1000001;
int NP,prime[100000],divp[prime_max];
map<ll,int> M;
ll A;
ll from[10000],to[10000];

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

vector<ll> enumdiv(ll n) {
	vector<ll> S;
	for(ll i=1;i*i<=n;i++) if(n%i==0) {S.push_back(i); if(i*i!=n) S.push_back(n/i); }
	sort(S.begin(),S.end());
	return S;
}

bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return true;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	cin>>A;
	auto D=enumdiv(A);
	
	
	FOR(i,D.size()) M[D[i]]=i;
	
	from[0]=1;
	FOR(i,NP) {
		memmove(to,from,sizeof(from));
		ll a=prime[i];
		while(a<A) {
			if(A%(1+a)==0) {
				FOR(x,D.size()) {
					ll v=D[x]*(1+a);
					if(M.count(v)) to[M[v]]+=from[x];
				}
			}
			a*=prime[i];
		}
		swap(from,to);
	}
	ll ret=from[D.size()-1];
	FOR(i,D.size()-1) if(from[i]) {
		ll d=A/D[i];
		if(d-1>=prime_max && isprime(d-1)) ret+=from[i];
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}