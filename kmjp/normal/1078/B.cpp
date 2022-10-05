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
int A[105];

int dp[2][105][10501];
int mo[2]={1000000007,1000000021};
int cnt[105];
const int N_=1020;
int C_[2][N_][N_];

set<int> S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int sum=0;
	FOR(i,N) {
		cin>>A[i];
		cnt[A[i]]++;
		sum+=A[i];
		S.insert(A[i]);
	}
	
	if(S.size()<=2) {
		cout<<N<<endl;
		return;
	}
	
	FOR(x,2) {
		FOR(i,N_) C_[x][i][0]=C_[x][i][i]=1;
		for(i=1;i<N_;i++) for(j=1;j<i;j++) C_[x][i][j]=(C_[x][i-1][j-1]+C_[x][i-1][j])%mo[x];
	}
	
	FOR(i,2) {
		dp[i][0][0]=1;
		FOR(j,N) {
			for(x=j;x>=0;x--) {
				FOR(y,x*100+1) if(dp[i][x][y]) {
					dp[i][x+1][y+A[j]]+=dp[i][x][y];
					if(dp[i][x+1][y+A[j]]>=mo[i]) dp[i][x+1][y+A[j]]-=mo[i];
				}
			}
		}
	}
	
	int ma=0;
	for(i=1;i<=100;i++) for(j=1;j<=cnt[i];j++) if(dp[0][j][i*j]==C_[0][cnt[i]][j]&&dp[1][j][i*j]==C_[1][cnt[i]][j]) ma=max(ma,j);
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}