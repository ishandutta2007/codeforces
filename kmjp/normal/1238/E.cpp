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

int N,M;
string S;

int num[26][26];
int dp[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>S;
	FOR(i,N-1) {
		num[S[i]-'a'][S[i+1]-'a']++;
		num[S[i+1]-'a'][S[i]-'a']++;
	}
	
	
	int mask;
	for(mask=1;mask<1<<M;mask++) {
		int sum=0;
		dp[mask]=1<<30;
		FOR(x,M) if(mask&(1<<x)) FOR(y,M) if(!(mask&(1<<y))) sum+=num[x][y];
		FOR(i,M) if(mask&(1<<i)) dp[mask]=min(dp[mask],dp[mask^(1<<i)]+sum);
	}
	
	cout<<dp[(1<<M)-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}