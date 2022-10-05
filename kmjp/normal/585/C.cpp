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



void dfs(ll X,ll Y) {
	if(X>Y) {
		if(Y==1) cout<<(X-1)<<"A"<<endl;
		else {
			cout<<X/Y<<"A";
			dfs(X%Y,Y);
		}
	}
	else {
		if(X==1) cout<<(Y-1)<<"B"<<endl;
		else {
			cout<<Y/X<<"B";
			dfs(X,Y%X);
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	ll X,Y;
	
	cin>>X>>Y;
	if(__gcd(X,Y)>1) return _P("Impossible\n");
	dfs(X,Y);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}