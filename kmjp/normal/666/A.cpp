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
int L;

int dp[101010][5];
set<string> SS;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	L=S.size();
	dp[L][2]=1;
	for(x=L-2;x>=5;x--) {
		
		if(x+2==L) {
			dp[x][2]=1;
		}
		else if(x+3==L) {
			dp[x][3]=1;
		}
		else {
			if(dp[x+2][2]) {
				if(S[x]!=S[x+2] || S[x+1]!=S[x+3]) dp[x][2]=1;
			}
			if(dp[x+2][3]) dp[x][2]=1;
			if(dp[x+3][2]) dp[x][3]=1;
			if(dp[x+3][3]) {
				if(S[x]!=S[x+3] || S[x+1]!=S[x+4] || S[x+2]!=S[x+5]) dp[x][3]=1;
			}
		}
		if(dp[x][2]) SS.insert(S.substr(x,2));
		if(dp[x][3]) SS.insert(S.substr(x,3));
	}
	cout<<SS.size()<<endl;
	FORR(r,SS) cout<<r<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}