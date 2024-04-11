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
ll R,V;
ll S,F;
double M_PI;

double dist(double r,double lp) {
	double di=2*M_PI*r*lp;
	di += r*sin(M_PI*lp)*2;
	return di;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	M_PI=atan(1)*4;
	
	cin>>N>>R>>V;
	double round=2*M_PI*R;
	
	FOR(i,N) {
		cin>>S>>F;
		double D=F-S;
		double ret=floor(D/round);
		D=fmod(D,round);
		
		double LL=0,RR=1;
		FOR(j,100) {
			double MM=(LL+RR)/2;
			if(dist(R,MM)>=D) RR=MM;
			else LL=MM;
		}
		ret += LL;
		_P("%.12lf\n",ret*round/V);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}