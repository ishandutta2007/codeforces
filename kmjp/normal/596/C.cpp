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

int N;
int X[101010],Y[101010];

int W[101010];
int ret[202020],px[202020];
map<pair<int,int>,int> pt;

void solve() {
	int i,j,k,l,r,x,y,w; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		pt[{X[i],Y[i]}]=i;
	}
	for(i=-100000;i<0;i++) px[101010+i]=-i;
	FOR(i,N) {
		cin>>w;
		int wp=w+101010;
		if(pt.count({px[wp],w+px[wp]})==0) return _P("NO\n");
		ret[i]=r=pt[{px[wp],w+px[wp]}];
		pt.erase({X[r],Y[r]});
		px[wp]++;
		if(pt.count({X[r]-1,Y[r]}) || pt.count({X[r],Y[r]-1})) return _P("NO\n");
	}
	
	_P("YES\n");
	FOR(i,N) _P("%d %d\n",X[ret[i]],Y[ret[i]]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}