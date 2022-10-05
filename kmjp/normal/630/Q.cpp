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

double v3(){
	return sqrt(2)/12;
}
double v4(){
	return 1*1*sqrt(2)/2/3;
}
double v5(){
	double pi=atan(1)*4;
	double a = sqrt(25+10*sqrt(5))/4;
	double r=0.5/sin(pi/5);
	double h=sqrt(1-r*r);
	return a*h/3;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>i>>j>>k;
	_P("%.12lf\n",i*i*i*v3()+j*j*j*v4()+k*k*k*v5());
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}