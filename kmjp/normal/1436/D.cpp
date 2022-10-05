#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int P[202020],C[202020];
ll A[202020];
ll B[202020];

int ok(ll v) {
	if(v<0) return 0;
	ZERO(B);
	int i;
	for(i=N-1;i>=0;i--) {
		if(C[i]==0) {
			B[i]=v;
		}
		if(B[i]<A[i]) return 0;
		if(i) {
			B[P[i]]+=B[i]-A[i];
			if(B[P[i]]>=200000000000000LL) {
				B[P[i]]=200000000000000LL;
			}
		}
	}
	return 1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>P[i+1];
		P[i+1]--;
		C[P[i+1]]++;
	}
	FOR(i,N) cin>>A[i];
	ll ret=1000000000LL*N;
	for(i=60;i>=0;i--) {
		ll tmp=ret-(1LL<<i);
		if(ok(tmp)) ret=tmp;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}