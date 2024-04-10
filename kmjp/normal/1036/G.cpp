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
vector<int> E[1010101];
vector<int> src,sink;
int in[1010101],out[1010101];
int reachable[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[y-1].push_back(x-1);
		in[y-1]++;
		out[x-1]++;
	}
	
	FOR(i,N) {
		if(in[i]==0) src.push_back(i);
		if(out[i]==0) sink.push_back(i);
	}
	
	FOR(i,sink.size()) {
		queue<int> Q;
		Q.push(sink[i]);
		reachable[sink[i]] |= 1<<i;
		while(Q.size()) {
			x=Q.front();
			Q.pop();
			
			FORR(e,E[x]) if((reachable[e]&(1<<i))==0) {
				reachable[e] |= 1<<i;
				Q.push(e);
			}
		}
	}
	
	for(int mask=1;mask<(1<<src.size())-1;mask++) {
		int tmask=0;
		FOR(i,src.size()) if(mask&(1<<i)) tmask |= reachable[src[i]];
		if(__builtin_popcount(mask) >= __builtin_popcount(tmask)) return _P("NO\n");
	}
	return _P("YES\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}