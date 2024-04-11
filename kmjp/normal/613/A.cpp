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
ll X[101010],Y[101010],PX,PY;
double ma,mi;


void solve() {
	int i,j,k,l,x,y; string s;
	
	mi=1e12;
	cin>>N>>PX>>PY;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		X[i]-=PX;
		Y[i]-=PY;
		ll r=X[i]*X[i]+Y[i]*Y[i];
		ma=max(ma,(double)r);
		mi=min(mi,(double)r);
	}
	X[N]=X[0];
	Y[N]=Y[0];
	
	FOR(i,N) {
		double dx=X[i+1]-X[i];
		double dy=Y[i+1]-Y[i];
		double dx2=-X[i];
		double dy2=-Y[i];
		double rad=sqrt(dx*dx+dy*dy);
		dx/=rad;
		dy/=rad;
		
		double sp=dx*dx2+dy*dy2;
		if(0<=sp&&sp<=rad) {
			double tx=X[i]+sp*dx;
			double ty=Y[i]+sp*dy;
			double rr=tx*tx+ty*ty;
			ma=max(ma,(double)rr);
			mi=min(mi,(double)rr);
		}
	}
	_P("%.12lf\n",(ma-mi)*atan(1)*4);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}