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
int A[51][51];
int B[51][51];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	FOR(y,H) FOR(x,W) {
		cin>>B[y][x];
		if(A[y][x]>B[y][x]) swap(A[y][x],B[y][x]);
	}
	
	FOR(y,H) FOR(x,W) {
		if(y&&A[y][x]<=A[y-1][x]) return _P("Impossible");
		if(y&&B[y][x]<=B[y-1][x]) return _P("Impossible");
		if(x&&A[y][x]<=A[y][x-1]) return _P("Impossible");
		if(x&&B[y][x]<=B[y][x-1]) return _P("Impossible");
		
	}
	cout<<"Possible"<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}