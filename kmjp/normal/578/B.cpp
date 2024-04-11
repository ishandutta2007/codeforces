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

int N,K,X;
ll FX;
ll A[202020];
ll L[202020],R[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>X;
	FOR(i,N) cin>>A[i];
	FX=1;
	while(K--) FX*=X;
	
	FOR(i,N) L[i+1]=((i)?L[i]:0) | A[i];
	for(i=N-1;i>=0;i--) R[i+1]=((i)?R[i+2]:0) | A[i];
	
	ll ma=0;
	FOR(i,N) ma=max(ma,L[i] | R[i+2] | (A[i]*FX));
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}