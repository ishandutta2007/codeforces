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
int A[505050],B[505050];
vector<int> E[505050];
int T[505050];
vector<int> C[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,M) {
		scanf("%d%d",&A[i],&B[i]);
		E[A[i]-1].push_back({B[i]-1});
		E[B[i]-1].push_back({A[i]-1});
	}
	FOR(i,N) {
		scanf("%d",&T[i]);
		T[i]--;
		C[T[i]].push_back(i+1);
	}
	FOR(i,N) {
		set<int> S;
		FORR(e,E[i]) S.insert(T[e]);
		x=0;
		while(S.count(x)) x++;
		if(x!=T[i]) return _P("-1\n");
	}
	
	
	FOR(i,N) FORR(c,C[i]) cout<<c<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}