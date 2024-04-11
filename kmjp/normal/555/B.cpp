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

int N,M;
ll L[202020],R[202020],MA[202020],MI[202020],A[202020];
int id[202020];
set<pair<ll,int> > EV;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M;
	FOR(i,N) cin>>L[i]>>R[i];
	FOR(i,M) {
		cin>>A[i];
		EV.insert({A[i],i+1000000});
	}
	
	FOR(i,N-1) {
		MI[i]=L[i+1]-R[i];
		MA[i]=R[i+1]-L[i];
		EV.insert({MI[i],i});
	}
	
	set<pair<ll,int> > S;
	
	FORR(r,EV) {
		int ev = r.second;
		if(ev<1000000) {
			S.insert({MA[ev],ev});
		}
		else if(ev<2000000) {
			ev-=1000000;
			auto s=S.begin();
			if(s==S.end()) continue;
			
			if(A[ev]>s->first) return _P("No\n");
			id[s->second]=ev+1;
			S.erase(s);
		}
	}
	
	if(S.size()) return _P("No\n");
	_P("Yes\n");
	FOR(i,N-1) _P("%d ",id[i]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}