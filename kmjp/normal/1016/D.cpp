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

int H,W;
ll A[101],B[101];
ll C[101][101];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(i,H) cin>>A[i];
	FOR(i,W) cin>>B[i];
	
	FOR(i,40) {
		x=y=0;
		FOR(j,H) if(A[j]&(1LL<<i)) x^=1;
		FOR(j,W) if(B[j]&(1LL<<i)) y^=1;
		if(x!=y) return _P("NO\n");
		
		FOR(y,H-1) if(A[y]&(1LL<<i)) C[y][W-1] |= 1LL<<i;
		ll ret=A[H-1]&(1LL<<i);
		FOR(x,W-1) if(B[x]&(1LL<<i)) {
			C[H-1][x] |= 1LL<<i;
			ret ^= (1LL<<i);
		}
		C[H-1][W-1] |= ret;
	}
	cout<<"YES"<<endl;
	FOR(y,H) {
		FOR(x,W) cout<<C[y][x]<<" ";
		cout<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}