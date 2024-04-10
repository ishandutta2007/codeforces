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

string S,T;
int N,M;
const ll mo=998244353;

ll dp[3030][3030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	N=S.size();
	M=T.size();
	
	FOR(i,N) {
		if(i>=M || T[i]==S[0]) dp[i][i+1]=2;
	}
	for(int pos=1;pos<N;pos++) {
		for(x=0;x+pos<=N;x++) {
			// front
			if(x>0 && (x-1>=M||T[x-1]==S[pos])) (dp[x-1][x+pos]+=dp[x][x+pos])%=mo;
			// back
			if(x+pos<N&&(x+pos>=M||T[x+pos]==S[pos])) (dp[x][x+pos+1]+=dp[x][x+pos])%=mo;
		}
	}
	ll ret=0;
	for(i=M;i<=N;i++) {
		ret+=dp[0][i];
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}