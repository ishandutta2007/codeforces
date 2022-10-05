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
int X[606060];
int V[606060];

int ok(double v) {
	double L=X[0]-v*V[0];
	double R=X[0]+v*V[0];
	for(int i=1;i<N;i++) {
		double L2=X[i]-v*V[i];
		double R2=X[i]+v*V[i];
		if(R2<L) return 0;
		if(R<L2) return 0;
		L=max(L,L2);
		R=min(R,R2);
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i];
	FOR(i,N) cin>>V[i];
	
	double L=0,R=1e10;
	FOR(i,100) {
		double M=(L+R)/2;
		if(ok(M)) R=M;
		else L=M;
	}
	_P("%.12lf\n",L);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}