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
ll X[201010],Y[201010],P[202020];
ll ssum2;
ll border;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i], X[i+N]=X[i], Y[i+N]=Y[i];
	FOR(i,N) ssum2 += X[i]*Y[i+1]-Y[i]*X[i+1];
	FOR(i,N) {
		P[i+N]=P[i]=__gcd(abs(X[i+1]-X[i]),abs(Y[i+1]-Y[i]));
		border+=P[i];
	}
	
	long double inp=(abs(ssum2)-border+2)/2;
	long double pox[105];
	long double pon=pow(0.5,N);
	FOR(i,100) pox[i]=pow(0.5,i+1);
	
	FOR(i,N) {
		ll tsum2=0, tb=0;
		for(x=1;x<min(N,80);x++) {
			long double prob=(pox[x]-pon)/(1-(1+N+N*(N-1)/2)*pon);
			if(prob<1e-20) continue;
			
			tsum2 += (X[i+x]-X[i])*(Y[i+x-1]-Y[i])-(Y[i+x]-Y[i])*(X[i+x-1]-X[i]);
			tb += P[i+x-1];
			if(x==1) continue;
			
			ll pb=__gcd(abs(X[i+x]-X[i]),abs(Y[i+x]-Y[i]));
			inp -= prob*(pb-1);
			pb+=tb;
			ll inpt=(abs(tsum2)-pb+2)/2;
			inp -= prob*inpt;
		}
	}
	_P("%.12lf\n",(double)inp);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}