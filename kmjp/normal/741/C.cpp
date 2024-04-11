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
int A[202020],B[202020];
int C[202020];
int X[202020];

void dfs(int cur,int col) {
	int oth=cur^1;
	
	if(X[C[oth]%N]>=0) return;
	int ocol = col^1;
	
	int tar;
	if(C[oth]>=N) {
		tar=A[C[oth]%N];
		X[C[oth]%N]=ocol^1;
	}
	else {
		tar=B[C[oth]];
		X[C[oth]]=ocol;
	}
	
	dfs(tar,col);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(X);
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i];
		A[i]--;
		B[i]--;
		C[A[i]]=i;
		C[B[i]]=N+i;
	}
	FOR(i,N) if(X[i]==-1) {
		X[i]=0;
		dfs(A[i],0);
	}
	
	FOR(i,N) _P("%d %d\n",X[i]+1,(X[i]^1)+1);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}