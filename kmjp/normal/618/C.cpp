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
ll X[101010],Y[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	FOR(i,N) X[N-1-i]-=X[0],Y[N-1-i]-=Y[0];
	
	ll rr=1LL<<62;
	x=0;
	for(i=1;i<N;i++) if(X[i]*X[i]+Y[i]*Y[i]<rr) x=i, rr=X[i]*X[i]+Y[i]*Y[i];
	
	double dx=X[x]/sqrt(rr);
	double dy=Y[x]/sqrt(rr);
	
	double h=1e20;
	y=1515150;
	for(i=1;i<N;i++) if(x!=i && X[x]*Y[i]-X[i]*Y[x]) {
		double a=X[i]*dx+Y[i]*dy;
		double b=abs(X[i]*X[i]+Y[i]*Y[i]-a*a);
		if(b<h) h=b, y=i;
	}
	
	
	_P("%d %d %d\n",1,x+1,y+1);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}