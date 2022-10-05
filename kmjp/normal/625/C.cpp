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

int N,K;
int A[501][501];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	int v=N*N;
	int sum=0;
	FOR(y,N) {
		for(x=N-1;x>=K-1;x--) A[y][x]=v--;
		sum += A[y][K-1];
	}
	FOR(y,N) for(x=K-2;x>=0;x--) A[y][x]=v--;
	
	_P("%d\n",sum);
	FOR(y,N) FOR(x,N) _P("%d%c",A[y][x],(x==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}