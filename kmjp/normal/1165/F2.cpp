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

int N,M;
int K[202020];
vector<int> C[402020];
vector<int> cand[402020];
int ok(int d) {
	int i;
	if(d<=0) return 0;
	FOR(i,d+1) cand[i].clear();
	int lef=0;
	FOR(i,N) {
		int ma=0;
		FORR(c,C[i]) if(c<=d) ma=c;
		if(ma) cand[ma].push_back(i);
		lef+=K[i];
	}
	
	int R=0;
	for(i=1;i<=d;i++) {
		R++;
		FORR(c,cand[i]) {
			int mi=min(K[c],R);
			lef-=mi;
			R-=mi;
		}
	}
	return R>=2*lef;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>K[i];
	FOR(i,M) {
		cin>>x>>y;
		C[y-1].push_back(x);
	}
	
	FOR(i,N) sort(ALL(C[i]));
	
	int ret=400000;
	for(i=19;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}