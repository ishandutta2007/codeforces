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
string S[2];

char other(char a,char b) {
	char c='a';
	if(c==a||c==b) c++;
	if(c==a||c==b) c++;
	return c;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	cin>>S[0]>>S[1];
	
	cout<<"YES"<<endl;
	if(S[0]==S[1]) {
		if(S[0][0]==S[0][1]) {
			FOR(i,N) cout<<"abc";
		}
		else {
			FOR(i,N) cout<<S[0][1];
			FOR(i,N) cout<<S[0][0];
			FOR(i,N) cout<<other(S[0][0],S[0][1]);
		}
		return;
	}
	
	if(S[0][0]==S[0][1] && S[1][0]==S[1][1]) {
		FOR(i,N) cout<<"abc";
	}
	else if(S[0][0]==S[0][1]) {
		FOR(i,N) cout<<S[1][1]<<S[1][0]<<other(S[1][0],S[1][1]);
	}
	else if(S[1][0]==S[1][1]) {
		FOR(i,N) cout<<S[0][1]<<S[0][0]<<other(S[0][0],S[0][1]);
	}
	else {
		if(S[0][0]==S[1][1]&&S[0][1]==S[1][0]) {
			FOR(i,N) cout<<S[0][0];
			FOR(i,N) cout<<other(S[0][0],S[0][1]);
			FOR(i,N) cout<<S[0][1];
		}
		
		else if(S[0][0]==S[1][0]) {
			FOR(i,N) cout<<S[0][1];
			FOR(i,N) cout<<S[1][1];
			FOR(i,N) cout<<S[0][0];
		}
		else if(S[0][1]==S[1][1]) {
			FOR(i,N) cout<<S[0][1];
			FOR(i,N) cout<<S[0][0];
			FOR(i,N) cout<<S[1][0];
		}
		else if(S[0][1]==S[1][0]) {
			FOR(i,N) cout<<S[1][1];
			FOR(i,N) cout<<S[0][1];
			FOR(i,N) cout<<S[0][0];
		}
		else if(S[0][0]==S[1][1]) {
			FOR(i,N) cout<<S[0][1];
			FOR(i,N) cout<<S[0][0];
			FOR(i,N) cout<<S[1][0];
		}
		else {
			assert(0);
		}
	}
	
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}