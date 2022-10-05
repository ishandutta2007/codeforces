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

ll B,Q,L,M;
set<int> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>B>>Q>>L>>M;
	FOR(i,M) cin>>x, S.insert(x);
	
	int ret=0;
	FOR(i,202020) {
		if(abs(B)>L) break;
		if(S.count(B)==0) ret++;
		B *= Q;
	}
	
	if(ret>100000) {
		cout<<"inf"<<endl;
	}
	else {
		cout<<ret<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}