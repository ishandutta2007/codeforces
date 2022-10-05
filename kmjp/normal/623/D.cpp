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
double P[101];
long double did[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i], P[i]/=100;
	
	long double ret=0;
	long double predid=0;
	for(i=1;i<=1000000;i++) {
		int best=0;
		for(x=1;x<N;x++) if((1-did[x])*P[x]*did[best]>did[x]*(1-did[best])*P[best]) best=x;
		
		did[best] += (1-did[best])*P[best];
		long double newdid=1;
		FOR(x,N) newdid*=did[x];
		ret += i*(newdid-predid);
		predid=newdid;
	}
	_P("%.12lf\n",(double)ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}