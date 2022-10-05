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
ll A[202020];
ll S[202020];
int nex[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>A[i];
	x=N;
	for(i=N-1;i>=0;i--) {
		nex[i]=x;
		if(A[i]!=1) x=i;
	}
	
	ll ret=0;
	FOR(i,N) {
		int R=i;
		ll p=1;
		ll s=0;
		while(R<N) {
			if((double)p*A[R]>3e18) break;
			p*=A[R];
			s+=A[R];
			int add=nex[R]-R-1;
			if(p%K==0) {
				if(s*K<=p && p<=(s+add)*K) ret++;
			}
			
			s+=add;
			R=nex[R];
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