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

int N,Q;
int A[101010];
int P[101010],K[101010];
vector<int> E[500];
const int DI=400;
int ret[101010];
int dp[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) cin>>A[i];
	
	cin>>Q;
	FOR(i,Q) {
		cin>>P[i]>>K[i];
		if(K[i]<=DI) E[K[i]].push_back(i);
		else {
			while(P[i]<=N) {
				ret[i]++;
				P[i]=P[i]+A[P[i]]+K[i];
			}
		}
	}
	for(i=1;i<=DI;i++) {
		for(j=N;j>=1;j--) {
			if(j+A[j]+i>N) dp[j]=1;
			else dp[j]=1+dp[j+A[j]+i];
		}
		FORR(e,E[i]) ret[e]=dp[P[e]];
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}