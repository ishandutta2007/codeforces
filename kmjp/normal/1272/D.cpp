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
int A[202020];
int L[202020],R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ma=1;
	FOR(i,N) {
		cin>>A[i+1];
		L[i+1]=1;
		if(A[i+1]>A[i]) L[i+1]=L[i]+1;
		ma=max(ma,L[i+1]);
	}
	
	R[N]=1;
	for(i=N-1;i>=1;i--) {
		R[i]=1;
		if(A[i+1]>A[i]) R[i]=R[i+1]+1;
	}
	
	for(i=2;i<=N-1;i++) if(A[i-1]<A[i+1]) ma=max(ma,L[i-1]+R[i+1]);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}