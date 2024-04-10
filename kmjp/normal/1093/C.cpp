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
ll B[202020];
ll A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N/2) cin>>B[i];
	FOR(i,N/2) {
		if(i==0) {
			A[N-1-i]=B[i];
		}
		else {
			A[i]=A[i-1];
			A[N-1-i]=B[i]-A[i];
			if(A[N-1-i]>A[N-1-i+1]) {
				A[i]+=A[N-1-i]-A[N-1-i+1];
				A[N-1-i]=A[N-1-i+1];
			}
		}
	}
	
	
	FOR(i,N) cout<<A[i]<<" ";
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}