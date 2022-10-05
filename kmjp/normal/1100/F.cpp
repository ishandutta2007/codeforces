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
int C[505050];
int Q;
int L[505050],R[505050],ret[505050];
vector<int> P[505050];

vector<int>& add(vector<int>& T,int v) {
	FORR(t,T) v=min(v,t^v);
	if(v) T.push_back(v);
	//sort(ALL(T)); reverse(ALL(T));
	return T;
	
}

void dfs(int le,int ri,vector<int>& V) {
	if(V.empty()) return;
	if(le+1==ri) {
		FORR(c,V) ret[c]=C[le];
		return;
	}
	int mi=(ri+le)/2;
	vector<int> A[3];
	FORR(v,V) {
		if(R[v]<=mi) A[0].push_back(v);
		else if(L[v]>=mi) A[1].push_back(v);
		else A[2].push_back(v);
	}
	
	if(A[2].size()) {
		vector<int> T,T2;
		int i;
		for(int i=mi;i<ri;i++) P[i]=add(T,C[i]);
		T.clear();
		for(int i=mi-1;i>=le;i--) P[i]=add(T,C[i]);
		FORR(v,A[2]) {
			T=P[L[v]];
			FORR(x,P[R[v]-1]) add(T,x);
			FORR(t,T) ret[v]=max({ret[v]^t,ret[v]});
		}
	}
	dfs(le,mi,A[0]);
	dfs(mi,ri,A[1]);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	scanf("%d",&N);
	FOR(i,N) scanf("%d",&C[i]);
	scanf("%d",&Q);
	vector<int> V;
	FOR(i,Q) {
		scanf("%d%d",&L[i],&R[i]);
		L[i]--;
		V.push_back(i);
	}
	dfs(0,N,V);
	
	FOR(i,Q) cout<<ret[i]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}