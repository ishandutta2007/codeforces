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

ll X0,Y0,V,T;
int N;
ll X,Y,R;
vector<pair<double,double>> range;

void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=atan(1)*4;
	
	cin>>X0>>Y0>>V>>T;
	V=min(V*T,6*1000000000LL);
	
	cin>>N;
	FOR(i,N) {
		cin>>X>>Y>>R;
		X-=X0;
		Y-=Y0;
		if(X*X+Y*Y<=R*R) return _P("1\n");
		if(R==0) continue;
		double D=sqrt(X*X+Y*Y);
		if(V<D-R) continue;
		double at=atan2(Y,X);
		double dif=asin(R/D);
		if((double)V*V+(double)R*R<D*D) {
			double A=(double)V*V+D*D-(double)R*R;
			A /= 2*V*D;
			dif = acos(A);
		}
		if(at+dif>pi) {
			range.push_back({at-dif,pi});
			range.push_back({-pi,at+dif-2*pi});
		}
		else if(at-dif<-pi) {
			range.push_back({-pi,at+dif});
			range.push_back({at-dif+2*pi,pi});
			
		}
		else {
			range.push_back({at-dif,at+dif});
		}
	}
	
	sort(ALL(range));
	double pre=-pi;
	double tot=0;
	FORR(r,range) {
		pre=max(pre,r.first);
		if(r.second-pre>0) tot+=r.second-pre;
		pre=max(pre,r.second);
	}
	_P("%.12lf\n",tot/(2*pi));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}