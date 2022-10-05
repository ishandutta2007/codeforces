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
string S[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	int beu=-1;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i];
		if(S[i][0]=='0') return _P("0\n");
		if(S[i][0]!='1') beu=i;
		FOR(j,S[i].size()-1) if(S[i][j+1]!='0') beu=i;
	}
	if(beu==-1) {
		cout<<1;
		FOR(i,N) FOR(j,S[i].size()-1) cout<<0;
	}
	else {
		cout<<S[beu];
		FOR(i,N) if(i!=beu) FOR(j,S[i].size()-1) cout<<0;
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}