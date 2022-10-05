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

int N,B,K,X;
ll fact[101010];
ll fact2[101010];
ll fact3[101010];
int OC[11];
ll dp[1050][100];
ll dp2[1050][100];
ll dp3[1050][100];
ll mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>B>>K>>X;
	FOR(i,N) cin>>x, OC[x]++;
	
	fact[0]=fact2[0]=fact3[0]=1;
	FOR(i,1020) fact[i+1]=fact[i]*10%X;
	FOR(i,1020) fact2[i+1]=fact2[i]*fact[1000]%X;
	FOR(i,1020) fact3[i+1]=fact3[i]*fact2[1000]%X;
	
	dp[0][0]=dp2[0][0]=dp3[0][0]=1;
	FOR(i,1000) FOR(y,X) FOR(x,10) (dp[i+1][(y*10+x)%X] += dp[i][y]*OC[x])%=mo;
	FOR(i,1000) FOR(x,X) FOR(y,X)  (dp2[i+1][(fact2[1]*y+x)%X] += dp2[i][y]*dp[1000][x])%=mo;
	FOR(i,1001) FOR(x,X) FOR(y,X)  (dp3[i+1][(fact3[1]*y+x)%X] += dp3[i][y]*dp2[1000][x])%=mo;
	
	ll ret=0;
	FOR(x,X) FOR(y,X) FOR(z,X) if((z*fact3[B/1000000]*fact2[B/1000%1000]+y*fact3[B/1000000]+x)%X==K)
		(ret+=dp[B%1000][z]*dp3[B/1000000][x]%mo*dp2[B/1000%1000][y])%=mo;
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}