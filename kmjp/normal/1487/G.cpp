#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int N;
int C[505];
ll from[404][404][3][4];
ll to[404][404][3][4];
ll dp[404][404];
const ll mo=998244353;
int NG[404][404];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,26) cin>>C[i];
	
	FOR(x,26) FOR(y,26) {
		from[(x==0)+(y==0)][(x==1)+(y==1)][x<2?x:2][y<2?y:((x==y)?2:3)]++;
	}
	
	FOR(i,N-2) {
		ZERO(to);
		FOR(x,N) FOR(y,N) FOR(j,3) FOR(k,4) if(from[x][y][j][k]) {
			ll v=from[x][y][j][k];
			if(j!=0) (to[x+1][y][min(k,2)][0]+=v)%=mo;
			if(j!=1) (to[x][y+1][min(k,2)][1]+=v)%=mo;
			if(j==0||j==1) {
				if(k>=2) {
					(to[x][y][min(k,2)][2]+=v)%=mo;
					(to[x][y][min(k,2)][3]+=v*23)%=mo;
				}
				else {
					(to[x][y][k][2]+=v*24)%=mo;
				}
			}
			else {
				if(k==0||k==1) (to[x][y][k][2]+=v*23)%=mo;
				else if(k==2) {
					(to[x][y][k][3]+=v*23)%=mo;
				}
				else {
					(to[x][y][2][2]+=v)%=mo;
					(to[x][y][2][3]+=v*22)%=mo;
				}
			}
		}
		swap(from,to);
	}
	ll ret=0;
	FOR(x,N+1) FOR(y,N+1) {
		FOR(i,3) FOR(j,4) dp[x][y]+=from[x][y][i][j];
		dp[x][y]%=mo;
		ret+=dp[x][y];
	}
	ret%=mo;
	// 1NG
	FOR(i,26) {
		for(x=C[i]+1;x<=N;x++) FOR(y,N+1)  ret-=dp[x][y];
		ret%=mo;
	}
	// 2NG
	FOR(y,26) FOR(x,y) NG[C[x]+1][C[y]+1]++;
	for(x=1;x<=N;x++) for(y=1;y<=N;y++) {
		NG[x][y]+=NG[x-1][y]+NG[x][y-1]-NG[x-1][y-1];
		(ret+=dp[x][y]*NG[x][y])%=mo;
	}
	cout<<ret<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}