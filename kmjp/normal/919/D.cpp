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
string S;
int in[303030];
vector<int> E[303030];
vector<int> C;
int dp[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		in[y-1]++;
	}
	
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	while(Q.size()) {
		int cur=Q.front();
		C.push_back(cur);
		Q.pop();
		FORR(e,E[cur]) {
			in[e]--;
			if(in[e]==0) Q.push(e);
		}
	}
	if(C.size()!=N) return _P("-1\n");
	
	int ret=0;
	for(char c='a';c<='z';c++) {
		ZERO(dp);
		FORR(v,C) {
			if(S[v]==c) dp[v]++;
			ret=max(ret,dp[v]);
			FORR(e,E[v]) dp[e]=max(dp[e],dp[v]);
		}
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}