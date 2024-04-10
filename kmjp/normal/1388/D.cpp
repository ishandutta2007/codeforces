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
ll A[202020],B[202020];
vector<int> E[202020];
ll ret;
vector<int> R;

ll dfs(int cur) {
	FORR(e,E[cur]) A[cur]+=dfs(e);
	ret+=A[cur];
	return max(A[cur],0LL);
	
}

void dfs2(int cur) {
	FORR(e,E[cur]) if(A[e]>=0) dfs2(e);
	R.push_back(cur);
	FORR(e,E[cur]) if(A[e]<0) dfs2(e);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> cand;
	FOR(i,N) {
		cin>>A[i];
	}
	FOR(i,N) {
		cin>>B[i];
		if(B[i]>=0) E[B[i]-1].push_back(i);
	}
	
	FOR(i,N) if(B[i]==-1) dfs(i);
	FOR(i,N) if(B[i]==-1) dfs2(i);
	
	cout<<ret<<endl;
	FORR(r,R) cout<<r+1<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}