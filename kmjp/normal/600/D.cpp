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

ll X[2],Y[2],R[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	long double PI=atan(1)*4;
	
	FOR(i,2) cin>>X[i]>>Y[i]>>R[i];
	
	if(R[0]<R[1]) swap(X[0],X[1]),swap(Y[0],Y[1]),swap(R[0],R[1]);
	X[1]-=X[0];
	Y[1]-=Y[0];
	if(X[1]*X[1]+Y[1]*Y[1]>=(R[0]+R[1])*(R[0]+R[1])) return _P("0\n");
	if(sqrt(X[1]*X[1]+Y[1]*Y[1])+R[1]<=R[0]) return _P("%.12lf\n",(double)(PI*R[1]*R[1]));
	long double A=R[0];
	long double B=R[1];
	long double D=sqrt(X[1]*X[1]+Y[1]*Y[1]);
	long double S=0;
	FOR(i,2) {
		long double co=(A*A+D*D-B*B)/(2*A*D);
		long double the=acos(co);
		S+=the*A*A;
		S-=A*sin(the)*A*cos(the);
		swap(A,B);
	}
	_P("%.12lf\n",(double)S);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}