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

int N,K;
int F[101010];
int C[101010];
int H[101010];

ll dp[5050];

ll hoge(int f,int c) {
	if(f==0 || c==0) return 0;
	
	int i,x,y;
	FOR(i,c) dp[i]=-1LL<<60;
	dp[c]=0;
	FOR(i,f) {
		for(x=0;x<=c;x++) {
			for(y=0;y<=min(x,K);y++) {
				dp[x-y]=max(dp[x-y],dp[x]+H[y]);
			}
		}
	}
	return dp[0];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N*K) cin>>x, C[x]++;
	FOR(i,N) cin>>x, F[x]++;
	FOR(i,K) cin>>H[i+1];
	
	ll ret=0;
	FOR(i,100001) ret+=hoge(F[i],min(F[i]*K,C[i]));
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}