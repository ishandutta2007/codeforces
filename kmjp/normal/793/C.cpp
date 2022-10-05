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
long double X1,X2,Y1,Y2;
long double RX,RY,VX,VY;
long double L,R;

pair<long double,long double> hoge() {
	long double L,R;
	L=0,R=1e9;
	
	if(VX==0) {
		if(RX<=X1 || RX>=X2) return {1,0};
	}
	else if(VX>0) {
		if(X2<=RX) return {1,0};
		L=max(L,(X1-RX)*1.0/VX);
		R=min(R,(X2-RX)*1.0/VX);
	}
	else if(VX<0) {
		if(RX<=X1) return {1,0};
		L=max(L,(RX-X2)*1.0/(-VX));
		R=min(R,(RX-X1)*1.0/(-VX));
	}
	
	if(VY==0) {
		if(RY<=Y1 || RY>=Y2) return {1,0};
	}
	else if(VY>0) {
		if(Y2<=RY) return {1,0};
		L=max(L,(Y1-RY)*1.0/VY);
		R=min(R,(Y2-RY)*1.0/VY);
	}
	else if(VY<0) {
		if(RY<=Y1) return {1,0};
		L=max(L,(RY-Y2)*1.0/(-VY));
		R=min(R,(RY-Y1)*1.0/(-VY));
	}
	
	return {L,R};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	L=0,R=1e9;
	
	cin>>N;
	cin>>X1>>Y1>>X2>>Y2;
	FOR(i,N) {
		cin>>RX>>RY>>VX>>VY;
		auto ret=hoge();
		L=max(L,ret.first);
		R=min(R,ret.second);
	}
	
	if(L>R-1e-12) return _P("-1\n");
	_P("%.12lf\n",(double)L);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}