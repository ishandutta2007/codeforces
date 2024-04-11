#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K,NN;
ll L;
int A[1010101];
int num[1010101];
int B[1010101];
ll mo=1000000007;
ll ret;
vector<int> V;
ll dp[2][1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>K;
	
	V.push_back(0);
	FOR(i,N) cin>>A[i], V.push_back(A[i]);
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	FOR(i,N) A[i]=lower_bound(ALL(V),A[i])-V.begin();
	NN=V.size();
	
	FOR(i,NN+1) dp[0][i]=1;
	for(i=1;i<=K;i++) {
		int tar=i&1,cur=tar^1;
		FOR(x,NN+1) dp[tar][x]=0;
		FOR(x,N) {
			dp[tar][A[x]] += dp[cur][A[x]];
			if(dp[tar][A[x]]>=mo) dp[tar][A[x]]-=mo;
			
			ll len=(L/N)+(x<L%N);
			if(len>=i) ret += dp[cur][A[x]]*((len+1-i)%mo)%mo;
		}
		for(x=1;x<=NN;x++) {
			dp[tar][x]+=dp[tar][x-1];
			if(dp[tar][x]>=mo) dp[tar][x]-=mo;
		}
	}
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}