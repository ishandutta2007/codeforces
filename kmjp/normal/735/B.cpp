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

int N,N1,N2;
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>N1>>N2;
	FOR(i,N) cin>>A[i];
	if(N1>N2) swap(N1,N2);
	sort(A,A+N);
	reverse(A,A+N);
	ll P=0,Q=0;
	x=N1,y=N2;
	FOR(i,N) {
		if(x) {
			x--;
			P += A[i];
		}
		else if(y) {
			y--;
			Q += A[i];
		}
	}
	_P("%.12lf\n",1.0*P/N1+1.0*Q/N2);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}