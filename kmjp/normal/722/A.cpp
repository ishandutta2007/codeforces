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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	if(S[3]>='6') S[3]='0';
	
	if(N==12) {
		if(S[0]=='0' && S[1]=='0') S[1]='1';
		if((S[0]-'0')*10+(S[1]-'0')>=13) {
			if(S[1]=='0') S[0]='1';
			else S[0]='0';
		}
	}
	else {
		if((S[0]-'0')*10+(S[1]-'0')>=24) {
			S[0]='0';
		}
	}
	
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}