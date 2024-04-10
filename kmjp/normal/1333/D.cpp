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
string S,T;
vector<int> ret[3030303];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	T=S;
	int NR=0;
	vector<int> cand[3030];
	FOR(i,N) {
		FOR(x,N-1) {
			if(S[x]=='R'&&S[x+1]=='L') {
				cand[i].push_back(x);
				swap(S[x],S[x+1]);
				x++;
			}
		}
	}
	
	int mi=0,ma=0;
	FOR(i,N) {
		if(cand[i].size()) mi=i+1;
		ma+=cand[i].size();
	}
	if(K<mi || K>ma) {
		return _P("-1\n");
	}
	int lef=K-mi;
	int cur=0;
	FOR(i,mi) {
		x=0;
		y=min(lef,(int)cand[i].size()-1);
		lef-=y;
		FOR(j,y) {
			ret[cur].push_back(cand[i][x]);
			cur++;
			x++;
		}
		for(;x<cand[i].size();x++) {
			ret[cur].push_back(cand[i][x]);
		}
		cur++;
	}
	assert(cur==K);
	FOR(i,K) {
		_P("%d",ret[i].size());
		FORR(e,ret[i]) {
			_P(" %d",e+1);
		}
		_P("\n");
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}