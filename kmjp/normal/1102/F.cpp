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

int H,W;
int A[16][101010];

int dp[16][16][1<<16];
int tab[16][16];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		FOR(x,W) cin>>A[y][x];
	}
	
	FOR(x,H) FOR(y,H) {
		tab[x][y]=1<<30;
		FOR(i,W) tab[x][y]=min(tab[x][y],abs(A[x][i]-A[y][i]));
	}
	
	MINUS(dp);
	FOR(y,H) dp[y][y][1<<y]=1<<30;
	
	int mask;
	FOR(mask,1<<H) FOR(x,H) if(mask&(1<<x)) {
		FOR(y,H) if((mask&(1<<y)) && dp[x][y][mask]>=0) {
			FOR(i,H) if((mask&(1<<i))==0) {
				dp[x][i][mask | (1<<i)] = max(dp[x][i][mask | (1<<i)], min(dp[x][y][mask],tab[y][i]));
			}
		}
	}
	
	int ma=0;
	FOR(x,H) FOR(y,H) {
		if(dp[x][y][(1<<H)-1]>=0) {
			int ret=dp[x][y][(1<<H)-1];
			FOR(i,W-1) ret=min(ret,abs(A[x][i+1]-A[y][i]));
			ma=max(ma,ret);
		}
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}