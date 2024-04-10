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
vector<int> E[202020];
vector<int> RE[202020];
vector<int> ne[202020];
int D[202020],mi[202020];
int K;
vector<int> P;
int cand[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		RE[y-1].push_back(x-1);
	}
	FOR(i,N) D[i]=202020;
	
	cin>>K;
	FOR(i,K) cin>>x, P.push_back(x-1);
	D[P.back()]=0;
	queue<int> Q;
	Q.push(P.back());
	while(Q.size()) {
		int cur=Q.front();
		Q.pop();
		FORR(e,RE[cur]) if(D[e]>D[cur]+1) {
			D[e]=D[cur]+1;
			Q.push(e);
		}
	}
	
	FOR(i,N) {
		mi[i]=202020;
		FORR(e,E[i]) mi[i]=min(mi[i],D[e]);
		FORR(e,E[i]) cand[i]+=D[e]==mi[i];
	}
	
	int L=0,R=0;
	FOR(i,P.size()-1) {
		if(D[P[i+1]]==mi[P[i]]) {
			if(cand[P[i]]>1) R++;
		}
		else {
			L++;
			R++;
		}
	}
	cout<<L<<" "<<R<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}