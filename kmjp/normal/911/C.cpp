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

int K[3];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K[0]>>K[1]>>K[2];
	sort(K,K+3);
	
	if(K[0]<=1) return _P("YES\n");
	if(K[1]<=2) return _P("YES\n");
	if(K[2]==3 && K[0]==3) return _P("YES\n");
	if(K[0]==2 && K[1]==4 && K[2]==4) return _P("YES\n");
	_P("NO\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}