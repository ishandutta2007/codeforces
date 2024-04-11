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

int M;
int A[202020],B[202020],C[202020];
pair<int,int> P[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M;
	FOR(i,M) cin>>A[i];
	FOR(i,M) cin>>B[i], P[i]={B[i],i};
	sort(A,A+M);
	sort(P,P+M);
	FOR(i,M) C[P[M-1-i].second]=A[i];
	FOR(i,M) _P("%d%c",C[i],(i==M-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}