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
ll H[1010101],T[1010101];
int vis[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	ll S=0;
	FOR(i,N) {
		scanf("%lld",&H[i]);
		S+=H[i];
	}
	
	ll V=0;
	ll lef=S;
	for(i=40;i>=0;i--) {
		ll A=V+(1LL<<i);
		ll sum=(A+A+(N-1))*N/2;
		if(sum<=S) V=A, lef=S-sum;
	}
	
	FOR(i,N) {
		T[i]+=V+i;
		if(i<lef) T[i]++;
	}
	
	
	FOR(i,N ) _P("%lld ",T[i]);
	
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}