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
int A[1010];
int B[1010];
int C[1010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	int M=0;
	while(M<N) {
		int now=(200.0*M/N+1)/2;
		j=K;
		int ok=0;
		FOR(i,N) {
			if(j>0 && B[i]<A[i]) {
				j--;
				if(B[i]+1==now) C[i]=1;
			}
		}
		j=K;
		FOR(i,N) {
			if(j>0 && B[i]<A[i]) {
				j--;
				B[i]++;
				if(B[i]==A[i]) M++;
			}
		}
	}
	
	int ret=0;
	FOR(i,N) ret+=C[i];
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}