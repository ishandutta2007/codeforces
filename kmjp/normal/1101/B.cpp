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

string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int L,R;
	cin>>S;
	int state=0;
	FOR(L,S.size()) {
		if(state==0) {
			if(S[L]=='[') state=1;
		}
		if(state==1) {
			if(S[L]==':') break;
		}
	}
	state=0;
	for(R=S.size()-1;R>=0;R--) {
		if(state==0) {
			if(S[R]==']') state=1;
		}
		if(state==1) {
			if(S[R]==':') break;
		}
	}
	
	if(L>=R) {
		cout<<-1<<endl;
	}
	else {
		int ret=4;
		for(i=L+1;i<R;i++) if(S[i]=='|') ret++;
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}