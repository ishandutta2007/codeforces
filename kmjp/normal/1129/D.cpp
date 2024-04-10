#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int A[101010];
int B1[101010],B2[101010];
int num[101010];
int dp[101010];
ll ret;
int mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	dp[0]=1;
	ll sum=1;
	for(i=1;i<=N;i++) {
		cin>>x;
		for(j=B2[x];j<B1[x];j++) if(--num[j]==K) sum+=dp[j];
		for(j=B1[x];j<i;j++) if(++num[j]==K+1) sum-=dp[j];
		
		sum%=mo;
		dp[i]=sum;
		B2[x]=B1[x];
		B1[x]=i;
		
		sum=(sum+dp[i])%mo;
		if(sum>=mo) sum-=mo;
	} 
	cout<<(dp[N]%mo+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}