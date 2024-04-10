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

ll A,B,C;
ll X[2],Y[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C;
	cin>>X[0]>>Y[0];
	cin>>X[1]>>Y[1];
	
	double ret=abs(X[1]-X[0])+abs(Y[1]-Y[0]);
	if(A && B) {
		vector<pair<double,double>> S;
		vector<pair<double,double>> T;
		S.push_back({X[0],-1.0*(A*X[0]+C)/B});
		S.push_back({-1.0*(B*Y[0]+C)/A,Y[0]});
		T.push_back({X[1],-1.0*(A*X[1]+C)/B});
		T.push_back({-1.0*(B*Y[1]+C)/A,Y[1]});
		FORR(s,S) FORR(t,T) {
			ret=min(ret,hypot(X[0]-s.first,Y[0]-s.second)+hypot(X[1]-t.first,Y[1]-t.second)+hypot(t.first-s.first,t.second-s.second));
		}
	}
	
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}