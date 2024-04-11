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
int A[202020];
ll B[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N+1) cin>>A[i], B[i]=A[i];
	int mi=N;
	FOR(i,N) {
		B[i+1] += B[i]/2;
		B[i] %= 2;
		if(B[i]&1) mi=min(mi,i);
	}
	
	int ret=0;
	ll v=0;
	for(i=N;i>=0;i--) {
		v=v*2+B[i];
		if(abs(v)>1LL<<40) break;
		if(i==N && A[i]-v==0) continue;
		if(i<=mi && abs(A[i]-v)<=K) ret++;
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