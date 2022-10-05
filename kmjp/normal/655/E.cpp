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

int N,M,K;
string T;
ll dp[2002020];
ll mo=1000000007;

ll hoge(string S) {
	int nn[26],i,j;
	int L=S.size();
	FOR(i,K) nn[i]=L+1;
	
	ll ret=0;
	for(i=L;i>=0;i--) {
		dp[i]=1;
		FOR(j,K) dp[i]+=dp[nn[j]];
		dp[i]%=mo;
		ret+=dp[i];
		if(i) nn[S[i-1]]=i;
	}
	
	return dp[0];
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>T;
	M=T.size();
	T+=string(N,'a');
	FORR(r,T) r-='a';
	int pre[26];
	FOR(i,K) pre[i]=-1;
	FOR(i,M) pre[T[i]]=i;
	
	FOR(i,N) {
		x=0;
		FOR(j,K) if(pre[j]<pre[x]) x=j;
		T[M+i]=x;
		pre[x]=M+i;
	}
	cout<<hoge(T)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}