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

int N,K;
vector<ll> C[4],S[4];

multiset<int> X,Y;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>r>>x>>y;
		C[x*2+y].push_back(r);
	}
	
	FOR(i,4) {
		sort(ALL(C[i]));
		S[i].push_back(0);
		FOR(j,C[i].size()) S[i].push_back(S[i][j]+C[i][j]);
	}
	
	if(C[1].size()+C[3].size()<K) return _P("-1\n");
	if(C[2].size()+C[3].size()<K) return _P("-1\n");
	ll ret=1LL<<60;
	for(i=0;i<=K;i++) {
		if(i<=C[1].size() && i<=C[2].size() && K-i<=C[3].size()) ret=min(ret,S[1][i]+S[2][i]+S[3][K-i]);
	}
	if(ret==1LL<<60) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}