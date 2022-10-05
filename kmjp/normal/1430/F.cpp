#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
int L[2020],R[2020],A[2020];
ll dp[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N+1) dp[i]=1LL<<60;
	dp[0]=0;
	FOR(i,N) cin>>L[i]>>R[i]>>A[i];
	FOR(i,N) {
		ll cur=dp[i];
		ll lef=K;
		for(j=i;j<N;j++) {
			ll fin;
			if(A[j]<=lef) {
				lef-=A[j];
				fin=L[j];
			}
			else {
				ll ene=A[j]-lef;
				ll need=(ene+(K-1))/K;
				if(need>R[j]-L[j]) break;
				fin=L[j]+need;
				lef=(K-ene%K)%K;
			}
			cur+=A[j];
			if(j<N-1&&fin<L[j+1]) {
				dp[j+1]=min(dp[j+1],cur+lef);
			}
			else if(j==N-1) {
				dp[N]=min(dp[N],cur);
			}
		}
	}
	
	if(dp[N]>1LL<<59) cout<<-1<<endl;
	else cout<<dp[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}