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

int N;
string S[2020];

string rev(string s) {
	FORR(r,s) {
		if(r=='+') r='*';
		else r='+';
	}
	return s;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	S[0]="+";
	FOR(i,N) {
		FOR(j,1<<i) {
			S[j+(1<<i)] = S[j]+rev(S[j]);
			S[j] += S[j];
		}
	}
	FOR(i,1<<N) cout<<S[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}