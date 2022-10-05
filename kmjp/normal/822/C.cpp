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

int N,X;
ll L[202020],R[202020],C[202020];
vector<int> F[202020],T[202020];
ll dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) {
		cin>>L[i]>>R[i]>>C[i];
		if(R[i]-L[i]+1>=X) continue;
		F[L[i]].push_back(i);
		T[R[i]].push_back(i);
	}
	FOR(i,202000) dp[i]=1LL<<60;
	ll mi=1LL<<60;
	FOR(i,202000) {
		FORR(e,F[i]) {
			int left=X-(R[e]-L[e]+1);
			mi=min(mi,C[e]+dp[left]);
		}
		FORR(e,T[i]) {
			int left=R[e]-L[e]+1;
			dp[left]=min(dp[left],C[e]);
		}
	}
	if(mi==1LL<<60) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}