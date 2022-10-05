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
int A[1010][1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int tot=0;
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	FOR(y,H) {
		int good=0;
		FOR(x,W) {
			if(A[y][x]==1) good=1;
			else tot+=good;
		}
		good=0;
		FOR(x,W) {
			if(A[y][W-1-x]==1) good=1;
			else tot+=good;
		}
	}
	FOR(x,W) {
		int good=0;
		FOR(y,H) {
			if(A[y][x]==1) good=1;
			else tot+=good;
		}
		good=0;
		FOR(y,H) {
			if(A[H-1-y][x]==1) good=1;
			else tot+=good;
		}
	}
	cout<<tot<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}