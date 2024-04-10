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

int N,T;
vector<int> L[3];

ll dp[52][52][52][52];
ll dp2[3][52][2505];
ll dp3[52][52][2505];
ll mo=1000000007;
ll fact[55];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,N) {
		cin>>x>>y;
		L[y-1].push_back(x);
	}
	dp[1][0][0][0]=1;
	dp[0][1][0][1]=1;
	dp[0][0][1][2]=1;
	FOR(i,51) FOR(j,51) FOR(k,51) {
		FOR(x,3) FOR(y,3) if(x!=y) {
			if(y==0) (dp[i+1][j][k][0]+=dp[i][j][k][x])%=mo;
			if(y==1) (dp[i][j+1][k][1]+=dp[i][j][k][x])%=mo;
			if(y==2) (dp[i][j][k+1][2]+=dp[i][j][k][x])%=mo;
		}
	}
	FOR(i,3) {
		dp2[i][0][0]=1;
		FOR(j,L[i].size()) {
			for(x=j;x>=0;x--) for(y=x*50;y>=0;y--) if(dp2[i][x][y]) {
				(dp2[i][x+1][y+L[i][j]]+=dp2[i][x][y])%=mo;
			}
		}
	}
	
	fact[0]=1;
	for(i=1;i<=50;i++) fact[i]=fact[i-1]*i%mo;
	
	int xc,yc,z;
	ll ret=0;
	for(x=0;x<=L[0].size();x++) for(xc=x;xc<=x*50;xc++) if(dp2[0][x][xc]) {
		for(y=0;y<=L[1].size();y++) for(yc=y;yc<=y*50;yc++) if(dp2[1][y][yc]) {
			(dp3[x][y][xc+yc]+=fact[x]*fact[y]%mo*dp2[0][x][xc]%mo*dp2[1][y][yc])%=mo;
		}
	}
	for(x=0;x<=L[0].size();x++) for(y=0;y<=L[1].size();y++) for(xc=0;xc<=50*(x+y);xc++) if(dp3[x][y][xc]) {
		for(z=0;z<=L[2].size();z++) {
			int le=T-xc;
			if(le>=0 && dp2[2][z][le]) {
				ret+=dp3[x][y][xc]*fact[z]%mo*dp2[2][z][le]%mo*(dp[x][y][z][0]+dp[x][y][z][1]+dp[x][y][z][2]);
				ret%=mo;
			}
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}