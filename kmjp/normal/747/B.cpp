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
string S;

int C[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FORR(c,S) {
		if(c=='A') C[0]++;
		if(c=='G') C[1]++;
		if(c=='C') C[2]++;
		if(c=='T') C[3]++;
	}
	FORR(c,S) if(c=='?') {
		if(C[0]<N/4) c='A',C[0]++;
		else if(C[1]<N/4) c='G',C[1]++;
		else if(C[2]<N/4) c='C',C[2]++;
		else if(C[3]<N/4) c='T',C[3]++;
		else return _P("===\n");
	}
	
	if(C[0]!=C[1] || C[0]!=C[2] || C[0]!=C[3]) return _P("===\n");
	if(C[1]!=C[2] || C[1]!=C[3] || C[2]!=C[3]) return _P("===\n");
	cout<<S<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}