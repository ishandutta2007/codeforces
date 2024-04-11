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
int A[101010];
int S,T;
ll SA[501010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
	}
	cin>>S>>T;
	FOR(i,N) {
		SA[S+N-i]+=A[i];
		SA[T+N-i]-=A[i];
		SA[N+S+N-i]+=A[i];
		SA[N+T+N-i]-=A[i];
		SA[2*N+S+N-i]+=A[i];
		SA[2*N+T+N-i]-=A[i];
	}
	
	for(i=1;i<=3*N;i++) SA[i]+=SA[i-1];
	
	int ret=1010101;
	ll ma=-1;
	FOR(i,3*N) {
		if(SA[i]>=ma) {
			x=i;
			while(x>N) x-=N;
			if(SA[i]>ma) {
				ret=x;
			}
			else {
				ret=min(ret,x);
			}
			ma=SA[i];
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