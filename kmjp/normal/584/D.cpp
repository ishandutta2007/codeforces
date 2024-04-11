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

int N;

const int prime_max = 20000;
int NP,prime[100000],divp[prime_max];
map<int,int> M;

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

//
bool isprime(ll v) {
	for(ll i=2;i*i<=v;i++) if(v%i==0) return false;
	return true;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	if(isprime(N)) return _P("1\n%d\n",N);
	if(N>3 && isprime(N-2)) return _P("2\n2 %d\n",N-2);
	
	cprime();
	FOR(x,NP) FOR(y,NP) {
		int z = N-(prime[x]+prime[y]);
		if(z>0 && isprime(z)) return _P("3\n%d %d %d\n",prime[x],prime[y],z);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}