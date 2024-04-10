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

int A[202020],B[202020];
vector<int> E[202020];
int C[202020];


void dfs(int cur,int col) {
	if(C[cur]==-1) {
		C[cur]=col;
		FORR(e,E[cur]) dfs(e,col^1);
	}
	else if(C[cur]!=col) {
		cout<<"NO"<<endl;
		exit(0);
	}
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	MINUS(C);
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--;B[i]--;
		E[A[i]].push_back(B[i]);
		E[B[i]].push_back(A[i]);
	}
	
	dfs(0,0);
	
	cout<<"YES"<<endl;
	FOR(i,M) {
		if(C[A[i]]) cout<<1;
		else cout<<0;
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}