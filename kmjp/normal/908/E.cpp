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

int M,N;
string S[1010];
ll mo=1000000007;
ll dp[1010][1010];
ll B[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	dp[0][0]=1;
	for(i=1;i<=1000;i++) {
		for(j=1;j<=i;j++) {
			dp[i][j]=(dp[i-1][j-1]+j*dp[i-1][j]%mo);
			B[i]+=dp[i][j];
		}
		B[i]%=mo;
	}
	cin>>M>>N;
	FOR(y,N) cin>>S[y];
	map<ll,int> masks;
	FOR(x,M) {
		ll mask=0;
		FOR(y,N) if(S[y][x]=='1') mask |= 1LL<<y;
		masks[mask]++;
	}
	ll ret=1;
	FORR(r,masks) (ret*=B[r.second])%=mo;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}