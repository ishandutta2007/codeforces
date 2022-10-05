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


int N,Q;
int A[101010];
int L[101010],X[101010];
vector<int> PQ[101010];
ll ret[101010];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>A[i];
	FOR(i,Q) {
		cin>>L[i]>>X[i];
		L[i]--;
		PQ[L[i]].push_back(i);
	}
	vector<pair<int,int>> mask;
	ll zero=1;
	FOR(i,N) {
		x=A[i];
		FORR(m,mask) if(x&m.second) x^=m.first;
		if(x==0) zero=zero*2%mo;
		else {
			y=0;
			for(j=0;j<20;j++) if(x&(1<<j)) y=1<<j;
			FORR(m,mask) if(m.first&y) m.first^=x;
			mask.push_back({x,y});
		}
		
		FORR(p,PQ[i]) {
			int v=X[p];
			FORR(m,mask) if(v&m.second) v^=m.first;
			if(v==0) ret[p]=zero;
			
		}
		
	}
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}