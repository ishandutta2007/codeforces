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
int A[404040];
ll C[21][21];
ll num[21];
ll dp[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		FOR(j,20) if(j!=A[i]) C[A[i]][j]+=num[j];
		num[A[i]]++;
	}
	
	FOR(i,1<<20) dp[i]=1LL<<60;
	dp[0]=0;
	int mask;
	FOR(mask,1<<20) {
		FOR(i,20) if((mask&(1<<i))==0) {
			ll t=dp[mask];
			FOR(j,20) if(mask&(1<<j)) t+=C[i][j];
			dp[mask|(1<<i)]=min(dp[mask|(1<<i)],t);
		}
	}
	cout<<dp[(1<<20)-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}