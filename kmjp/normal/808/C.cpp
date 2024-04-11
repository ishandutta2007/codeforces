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

int N,W;
int A[101];
int B[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W;
	FOR(i,N) {
		cin>>A[i];
		B[i]=(A[i]+1)/2;
		W-=B[i];
	}
	if(W<0) return _P("-1\n");
	while(W) {
		int id=-1;
		FOR(i,N) if(A[i]!=B[i]) {
			if(id==-1 || A[i]>A[id] || (A[i]==A[id] && B[i]<B[id]))
				id=i;
		}
		if(id==-1) return _P("-1\n");
		B[id]++;
		W--;
	}
	FOR(i,N) _P("%d%c",B[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}