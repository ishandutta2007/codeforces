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
ll A[101010],B[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>B[i];
	sort(A,A+N);
	sort(B,B+N);
	int L[2]={},R[2]={N-1,N-1};
	
	ll ret=0;
	FOR(i,N) {
		if(R[0]<L[0]) R[1]--;
		else if(R[1]<L[1]) ret+=A[R[0]--];
		else {
			if(A[R[0]]>=B[R[1]]) ret+=A[R[0]--];
			else R[1]--;
		}
		
		if(R[0]<L[0]) ret-=B[R[1]--];
		else if(R[1]<L[1]) R[0]--;
		else {
			if(A[R[0]]>=B[R[1]]) R[0]--;
			else ret-=B[R[1]--];
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}