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
int U[101010],V[101010];
vector<int> E[101010];
int fix[101010],in[101010];

int ok(int S) {
	int i;
	S=min(S,M);
	FOR(i,N) E[i].clear();
	ZERO(in);
	FOR(i,S) E[U[i]].push_back(V[i]), in[V[i]]++;
	
	int left=N;
	queue<int> Q;
	FOR(i,N) if(in[i]==0) Q.push(i);
	
	while(Q.size()) {
		if(Q.size()>1) return 0;
		left--;
		int x=Q.front();
		Q.pop();
		FORR(r,E[x]) if(--in[r]==0) Q.push(r);
	}
	
	return left==0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) cin>>U[i]>>V[i], U[i]--, V[i]--;
	
	int ret=1<<20;
	for(i=19;i>=0;i--) if(ok(ret-(1<<i))) ret-=1<<i;
	
	if(ret>M) ret=-1;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}