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
int T[20],C[2][20];
int NM[2][1<<16];
int dp[1<<16][200];
int TT[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s>>C[0][i]>>C[1][i];
		T[i]=s=="B";
		TT[0]+=C[0][i];
		TT[1]+=C[1][i];
		for(int mask=0;mask<1<<N;mask++) if(mask&(1<<i)) NM[T[i]][mask]++;
	}
	
	MINUS(dp);
	dp[0][0]=0;
	for(int mask=0;mask<1<<N;mask++) {
		FOR(i,200) if(dp[mask][i]>=0) {
			FOR(j,N) if((mask & (1<<j))==0) {
				int mask2 = mask | (1<<j);
				int r = i + min(C[0][j],NM[0][mask]);
				int b = dp[mask][i] + min(C[1][j],NM[1][mask]);
				dp[mask2][r]=max(dp[mask2][r],b);
			}
		}
	}
	
	
	int ret=max(TT[0],TT[1]);
	FOR(i,200) if(dp[(1<<N)-1][i]>=0) ret=min(ret,max(TT[0]-i,TT[1]-dp[(1<<N)-1][i]));
	
	cout<<ret+N<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}