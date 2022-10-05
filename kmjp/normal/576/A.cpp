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

const int prime_max = 10000;
int NP,prime[100000],divp[prime_max];
map<int,int> M;

void cprime() {
	for(int i=2;i<prime_max;i++) if(divp[i]==0) {
		//M[i]=NP;
		prime[NP++]=i;
		for(ll j=1LL*i*i;j>i&&j<prime_max;j+=i) divp[j]=i;
	}
}

int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cprime();
	
	cin>>N;
	
	vector<int> V;
	FOR(i,NP) {
		x=prime[i];
		while(x<=N) {
			V.push_back(x);
			x*=prime[i];
		}
	}
	
	_P("%d\n",V.size());
	FOR(i,V.size()) {
		_P("%d%c",V[i],i==V.size()-1?'\n':' ');
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}