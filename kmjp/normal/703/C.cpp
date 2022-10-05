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
ll W,V,U;
ll X[101010],Y[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W>>V>>U;
	FOR(i,N) cin>>X[i]>>Y[i];
	X[N]=X[0];
	Y[N]=Y[0];
	int up=0,down=0;
	FOR(i,N) {
		if(Y[i]*V-X[i]*U>0) up++;
		if(Y[i]*V-X[i]*U<0) down++;
	}
	
	if(up==0 || down==0) return _P("%.12lf\n",W/1.0/U);
	double ma=0;
	FOR(i,N) if(X[i]>=0) ma=max(ma,max(X[i]*1.0/V,Y[i]*1.0/U) + (W-Y[i])*1.0/U);
	_P("%.12lf\n",ma);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}