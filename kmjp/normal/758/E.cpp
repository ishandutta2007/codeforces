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

int N;
int A[202020],B[202020],W[202020],P[202020];
ll M[202020];
vector<pair<int,int>> E[202020];
ll TW[202020];
ll TR[202020];

deque<int> R[202020];


void dfs(int cur,int pre) {
	
	FORR(e,E[cur]) if(e.second!=pre) {
		dfs(e.second,cur);
		TW[cur]+=TW[e.second];
		if(R[cur].size()<R[e.second].size()) swap(R[cur],R[e.second]);
		FORR(r,R[e.second]) R[cur].push_back(r);
		TR[cur]+=TR[e.second];
	}
	
	FORR(e,E[cur]) if(e.second==pre) {
		int x = e.first;
		
		while(P[e.first]<TW[cur]) {
			if(R[cur].empty()) {
				cout<<-1<<endl;
				exit(0);
			}
			int id=R[cur].front();
			ll red = min(M[id],TW[cur]-P[e.first]);
			TW[cur]-=red;
			W[id]-=red;
			P[id]-=red;
			M[id]-=red;
			TR[cur]-=red;
			if(M[id]==0) R[cur].pop_front();
		}
		
		M[e.first]=min(M[e.first],P[e.first]-(TW[cur]-TR[cur]));
		R[cur].push_back(e.first);
		TW[cur]+=W[e.first];
		TR[cur]+=M[e.first];
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>A[i]>>B[i]>>W[i]>>P[i];
		A[i]--;
		B[i]--;
		E[A[i]].push_back({i,B[i]});
		E[B[i]].push_back({i,A[i]});
		M[i]=min(W[i]-1,P[i]);
	}
	
	dfs(0,-1);
	_P("%d\n",N);
	FOR(i,N-1) _P("%d %d %d %d\n",A[i]+1,B[i]+1,W[i],P[i]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}