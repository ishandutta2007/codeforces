#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll A[202020];

double dodo(double v) {
	double sum=0;
	double mi=0,ma=0;
	double tma=0;
	int i;
	
	FOR(i,N) {
		sum += A[i]-v;
		tma=max(tma,abs(sum-ma));
		tma=max(tma,abs(sum-mi));
		
		ma=max(ma,sum);
		mi=min(mi,sum);
	}
	return tma;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	double L=*min_element(A,A+N);
	double R=*max_element(A,A+N);
	
	FOR(i,200) {
		double m1=(2*L+R)/3;
		double m2=(2*R+L)/3;
		
		if(dodo(m1)<dodo(m2)) R=m2;
		else L=m1;
	}
	_P("%.12lf\n",dodo(L));
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}