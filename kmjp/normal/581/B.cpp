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

int N;
int H[101010];
int R[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>N;
	
	
	FOR(i,N) cin>>H[i];
	int ma=0;
	for(i=N-1;i>=0;i--) {
		if(H[i]>ma) R[i]=0;
		else R[i]=ma+1-H[i];
		ma=max(ma,H[i]);
	}
	FOR(i,N) _P("%d ",R[i]);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}