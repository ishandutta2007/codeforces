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
int L[101];
int A[101];
set<int> S;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) S.insert(i+1);
	cin>>x;
	FOR(i,M-1) {
		cin>>y;
		if(A[x]==0) {
			A[x]=y-x;
			while(A[x]<1) A[x]+=N;
			while(A[x]>N) A[x]-=N;
			if(S.count(A[x])==0) return _P("-1\n");
			S.erase(A[x]);
		}
		if((x+A[x])%N != y%N) return _P("-1\n");
		swap(x,y);
	}
	
	FOR(i,N) {
		if(A[i+1]==0) {
			A[i+1]=*S.begin();
			S.erase(S.begin());
		}
		_P("%d%c",A[i+1],(i==N-1)?'\n':' ');
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}