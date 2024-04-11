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

int N,C;
vector<int> K[505050];
int NG[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>C;
	FOR(i,N) {
		cin>>x;
		K[i].resize(x);
		FOR(j,x) cin>>K[i][j], K[i][j]--;
	}
	
	int L=0,R=C-1;
	FOR(i,N-1) {
		FOR(j,K[i].size()) {
			if(K[i+1].size()==j) return _P("-1\n");
			if(K[i][j]==K[i+1][j]) continue;
			
			if(K[i][j]>K[i+1][j]) {
				NG[0]++;
				NG[C-K[i][j]]--;
				NG[C-K[i+1][j]]++;
			}
			else {
				NG[C-K[i+1][j]]++;
				NG[C-K[i][j]]--;
			}
			
			break;
		}
	}
	FOR(i,C) {
		if(i) NG[i]+=NG[i-1];
		if(NG[i]==0) return _P("%d\n",i);
	}
	_P("-1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}