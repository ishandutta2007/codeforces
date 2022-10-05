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

ll D,K,A,B,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D>>K>>A>>B>>T;
	if(A*K+T>=B*K) {
		cout<<min(D,K)*A + max(0LL,D-K)*B << endl;
	}
	else {
		ll mi=1LL<<60;
		for(x=0;x<=min(D,K);x++) {
			ll mv=D-x;
			ll fix=max(0LL,(mv+K-1)/K-1);
			mi=min(mi,x*B + A*(D-x) + fix*T);
		}
		cout<<mi<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}