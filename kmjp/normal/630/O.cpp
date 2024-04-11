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

int PX,PY,VX,VY;
int A,B,C,D;
double vx,vy;
double lx,ly;
double rx,ry;


void go(double a,double b) {
	_P("%.12lf %.12lf\n",PX+a,PY+b);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>PX>>PY>>VX>>VY;
	cin>>A>>B>>C>>D;
	
	double vv=sqrt(VX*VX+VY*VY);
	vx=VX/vv;
	vy=VY/vv;
	lx=-vy;
	ly=vx;
	rx=-lx;
	ry=-ly;
	
	
	go(vx*B,vy*B);
	go(lx*A/2,ly*A/2);
	go(lx*C/2,ly*C/2);
	go(lx*C/2-vx*D,ly*C/2-vy*D);
	go(rx*C/2-vx*D,ry*C/2-vy*D);
	go(rx*C/2,ry*C/2);
	go(rx*A/2,ry*A/2);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}