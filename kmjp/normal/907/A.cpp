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

int V[4];
int W[4];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,4) cin>>V[i];
	if(V[2]>V[3]*2) return _P("-1\n");
	if(V[3]>V[2]*2) return _P("-1\n");
	if(V[3]>=V[1]) return _P("-1\n");
	_P("%d\n%d\n%d\n",V[0]*2,V[1]*2,max(V[2],V[3]));
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}