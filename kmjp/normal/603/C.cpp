#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int A[101010];
int grund[13000];

int dodo(int v) {
	
	if(v<=30) return grund[v];
	if(v%2==1) return 0;
	if(v/2%2==1) return 1;
	return 3-dodo(v/2);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	ll xo=0;
	cin>>N>>K;
	for(i=1;i<=50;i++) {
		FOR(j,3) {
			if(grund[i-1]==grund[i]) grund[i]++;
			if(K%2) {
				if(i%2==0 && grund[i]==grund[i/2]) grund[i]++;
			}
			else {
				if(i%2==0 && grund[i]==0) grund[i]++;
			}
		}
	}
	
	FOR(i,N) {
		cin>>A[i];
		if(K%2==0) {
			if(A[i]==1) xo^=1;
			else if(A[i]==2) xo^=2;
			else xo ^= (A[i]%2)^1;
		}
		else {
			xo ^= dodo(A[i]);
		}
	}
	
	if(xo==0) _P("Nicky\n");
	else _P("Kevin\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}