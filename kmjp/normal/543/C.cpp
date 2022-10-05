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

int N,M;
string S[30];
int A[30][30];
int exc[30][256];
int exm[30][256];
ll dp[1<<20];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>S[i];
	FOR(y,N) FOR(x,M) cin>>A[y][x];
	
	FOR(i,M) {
		for(j='a';j<='z';j++) {
			int ma=0, tot=0;
			FOR(x,N) if(S[x][i]==j) {
				exm[i][j] |= 1<<x;
				ma=max(ma,A[x][i]);
				tot += A[x][i];
			}
			exc[i][j] = tot-ma;
		}
	}
	FOR(i,1<<N) dp[i]=1LL<<50;
	dp[(1<<N)-1]=0;
	for(int mask=(1<<N)-1;mask>0;mask--) {
		int mid=0;
		while((mask&(1<<mid))==0) mid++;
		FOR(i,M) {
			dp[mask ^ (1<<mid)] = min(dp[mask ^ (1<<mid)], dp[mask]+A[mid][i]);
			dp[mask & ~exm[i][S[mid][i]]] = min(dp[mask & ~exm[i][S[mid][i]]], dp[mask]+exc[i][S[mid][i]]);
		}
	}
	cout<<dp[0]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}