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

int N,M;
ll A[3010101];
ll tot[3030303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) scanf("%d",&x), A[x]++;
	
	ll tt=1LL*N*(N-1);
	for(i=1;i<=3000000;i++) {
		for(j=1;i*j<=3000000;j++) {
			if(i==j) {
				tot[i*j] += A[i]*(A[i]-1);
				tt -= A[i]*(A[i]-1);
			}
			else {
				tot[i*j] += A[i]*A[j];
				tt -= A[i]*A[j];
			}
		}
	}
	tot[3000001] = tt;
	for(i=3000000;i>=0;i--) tot[i] += tot[i+1];

	
	scanf("%d",&M);
	FOR(i,M) {
		scanf("%d",&x);
		_P("%I64d\n",tot[x]);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}