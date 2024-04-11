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

ll A,B,C,D;

bool ok(double dif) {
	double ma1=-1e20,mi1=1e20;
	double ma2=-1e20,mi2=1e20;
	
	ma1=max(ma1,(A+dif)*(D+dif));
	ma1=max(ma1,(A+dif)*(D-dif));
	ma1=max(ma1,(A-dif)*(D+dif));
	ma1=max(ma1,(A-dif)*(D-dif));
	ma2=max(ma2,(C+dif)*(B+dif));
	ma2=max(ma2,(C+dif)*(B-dif));
	ma2=max(ma2,(C-dif)*(B+dif));
	ma2=max(ma2,(C-dif)*(B-dif));
	
	mi1=min(mi1,(A+dif)*(D+dif));
	mi1=min(mi1,(A+dif)*(D-dif));
	mi1=min(mi1,(A-dif)*(D+dif));
	mi1=min(mi1,(A-dif)*(D-dif));
	mi2=min(mi2,(C+dif)*(B+dif));
	mi2=min(mi2,(C+dif)*(B-dif));
	mi2=min(mi2,(C-dif)*(B+dif));
	mi2=min(mi2,(C-dif)*(B-dif));
	
	mi1=max(mi1,mi2);
	ma1=min(ma1,ma2);
	return mi1<=ma1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>D;
	double L=0,R=1e10;
	FOR(i,1000) {
		double M=(L+R)/2;
		if(ok(M)) R=M;
		else L=M;
	}
	_P("%.12lf\n",(L+R)/2);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}