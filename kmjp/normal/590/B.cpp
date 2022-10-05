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

int X,Y;
int V,T;
int VX,VY,WX,WY;

void solve() {
	int i,j,k,l,r,x,y;
	
	cin>>x>>y>>X>>Y;
	X-=x;
	Y-=y;
	cin>>V>>T;
	cin>>VX>>VY>>WX>>WY;
	
	double L=0,R=1e9;
	FOR(i,200) {
		double M=(L+R)/2;
		double cx = min(1.0*T,M)*VX + max(0.0,M-T)*WX;
		double cy = min(1.0*T,M)*VY + max(0.0,M-T)*WY;
		
		if((X-cx)*(X-cx)+(Y-cy)*(Y-cy)<=V*M*V*M) R=M;
		else L=M;
	}
	
	return _P("%.12lf\n",L);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}