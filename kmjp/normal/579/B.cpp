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
int pa[801];
pair<int,int> go[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(pa);
	cin>>N;
	FOR(i,2*N-1) {
		FOR(x,i+1) cin>>y, go[y]={i+1,x};
	}
	
	for(x=1000000;x>=0;x--) if(go[x].first) {
		if(pa[go[x].first]<0 && pa[go[x].second]<0) {
			pa[go[x].first]=go[x].second+1;
			pa[go[x].second]=go[x].first+1;
		}
	}
	FOR(i,2*N) _P("%d ",pa[i]);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}