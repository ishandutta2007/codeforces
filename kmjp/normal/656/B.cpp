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
int R[16],M[16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll a=1;
	for(i=1;i<=16;i++) {
		ll g=__gcd(a,(ll)i);
		a=a/g*i;
	}
	
	cin>>N;
	FOR(i,N) cin>>M[i];
	FOR(i,N) cin>>R[i];
	
	int is=0;
	FOR(i,a) {
		int ok=0;
		FOR(j,N) if(i%M[j]==R[j]) ok=1;
		is+=ok;
	}
	_P("%.12lf\n",is*1.0/a);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}