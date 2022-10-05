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
int A[26];
ll dp[1010];
int mis[1010];
ll mo=1000000007;
int ma=0;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,26) cin>>A[i];
	FOR(i,N+1) mis[i]=1010;
	
	dp[0]=1;
	mis[0]=0;
	FOR(i,N) {
		int B[26];
		FOR(j,26) B[j]=A[j];
		int mi=10101;
		for(j=i;j<N;j++) {
			mi=min(mi,A[S[j]-'a']);
			if(j-i+1>mi) break;
			ma=max(ma,j-i+1);
			(dp[j+1]+=dp[i])%=mo;
			mis[j+1]=min(mis[j+1],mis[i]+1);
		}
	}
	
	cout<<dp[N]<<endl;
	cout<<ma<<endl;
	cout<<mis[N]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}