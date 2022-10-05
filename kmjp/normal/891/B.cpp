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
int A[22];

void solve() {
	int i,j,k,l,r,x,y; string s;
	clock_t st,ed;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		
		if(*max_element(A,A+N)==A[i]) {
			x=*min_element(A,A+N);
		}
		else {
			x=1<<30;
			FOR(j,N) if(A[j]>A[i]&&A[j]<x) x=A[j];
		}
		_P("%d%c",x,(i==N-1)?'\n':' ');
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}