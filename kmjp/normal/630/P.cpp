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

ll P,R;
double A;

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>P>>R;
	
	double pi=atan(1)*4;
	double ta=pi/P/2;
	double ca=2*pi/P/2;
	double S=sin(ta)*sin(ca)/(2*sin(ta+ca));
	
	A=S*2*P;
	
	
	_P("%.12lf\n",A*R*R);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}