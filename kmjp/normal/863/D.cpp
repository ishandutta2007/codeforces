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

int N,Q,M;
int A[202020];
int T[202020],L[202020],R[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&Q,&M);
	FOR(i,N) scanf("%d",&A[i+1]);
	FOR(i,Q) scanf("%d%d%d",&T[Q-1-i],&L[Q-1-i],&R[Q-1-i]);
	FOR(i,M) {
		scanf("%d",&x);
		FOR(j,Q) {
			if(L[j]<=x && x<=R[j]) {
				if(T[j]==1) {
					x--;
					if(x<L[j]) x=R[j];
				}
				else {
					x=L[j]+R[j]-x;
				}
			}
		}
		_P("%d%c",A[x],(i==M-1)?'\n':' ');
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}