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

int N,K;
ll mask[64];
int ma=0;

int bk(ll R,ll P,ll X) {
	static int cma=0;
	int ma=0;
	if(P==0 && X==0) {
		cma=max(cma,__builtin_popcountll(R));
		return __builtin_popcountll(R);
	}
	if(cma>=__builtin_popcountll(R)+__builtin_popcountll(P)) return 0;
	while(P) {
		int i = __builtin_ffsll(P)-1;
		ma = max(ma,bk(R | (1LL<<i), P & mask[i], X & mask[i]));
		P ^= (1LL<<i);
		X |= (1LL<<i);
	}
	return ma;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(y,N) {
		FOR(x,N) {
			cin>>i;
			if(i) mask[y] |= 1LL<<x;
		}
	}
	
	x = bk(0,(1LL<<N)-1,0);
	double ret=(x-1.0)/(2*x);
	
	
	_P("%.12lf\n",ret*K*K);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}