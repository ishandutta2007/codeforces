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
int A[12],B[12];
int MA[12];
int MB[12];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x>>y;
		A[i] = (1<<x) | (1<<y);
	}
	FOR(i,M) {
		cin>>x>>y;
		B[i] = (1<<x) | (1<<y);
	}
	
	vector<int> CA[12],CB[12];
	int a[2]={},b[2]={};
	FOR(i,N) FOR(j,M) if(__builtin_popcount(A[i]&B[j])==1) MA[i] |= 1<<j;
	FOR(i,M) FOR(j,N) if(__builtin_popcount(B[i]&A[j])==1) MB[i] |= 1<<j;
	
	FOR(i,1200) {
		FOR(x,N) if(MA[x]==0) FOR(y,M) MB[y] &= ~(1<<x);
		FOR(x,M) if(MB[x]==0) FOR(y,N) MA[y] &= ~(1<<x);
	}
	
	int cand=0;
	int cantsure=0;
	FOR(i,N) {
		int mc=0;
		FOR(j,M) if((MA[i]&(1<<j)) && (MB[j]&(1<<i))) {
			cand |= A[i]&B[j];
			mc |= A[i]&B[j];
		}
		if(__builtin_popcount(mc)>1) return _P("-1\n");
	}
	FOR(j,M) {
		int mc=0;
		FOR(i,N) if((MA[i]&(1<<j)) && (MB[j]&(1<<i))) {
			cand |= A[i]&B[j];
			mc |= A[i]&B[j];
		}
		if(__builtin_popcount(mc)>1) return _P("-1\n");
	}
	
	if(__builtin_popcount(cand)>1) {
		_P("0\n");
	}
	else if(__builtin_popcount(cand)==1) {
		FOR(x,10) if(cand & (1<<x)) cout<<x<<endl;
	}
	else {
		_P("-1\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}