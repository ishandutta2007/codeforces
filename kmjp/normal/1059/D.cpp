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

int ok(long double M) {
	long double L=-3e20,R=3e20;
	int i;
	FOR(i,N) {
		if(2*M<Y[i]) return 0;
		long double dx=sqrt(Y[i]*(2*M-Y[i]));
		L=max(L,X[i]-dx);
		R=min(R,X[i]+dx);
	}
	return L<=R;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		if(Y[0]>0 != Y[i]>0) return _P("-1\n");
	}
	FOR(i,N) Y[i]=abs(Y[i]);
	
	long double L=0,R=1e20;
	FOR(i,100) {
		long double M=(L+R)/2;
		if(ok(M)) R=M;
		else L=M;
	}
	_P("%.12f\n",(double)L);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}