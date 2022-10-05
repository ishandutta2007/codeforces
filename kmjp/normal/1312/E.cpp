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
int A[505];

int ok[505][505];
int dp[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(ok);
	FOR(i,N) {
		cin>>A[i];
		ok[i][i+1]=A[i];
	}
	for(int len=2;len<=N;len++) {
		for(i=0;i+len<=N;i++) {
			for(x=i+1;x<i+len;x++) {
				if(ok[i][x]>=0 && ok[x][i+len]>=0 && ok[i][x]==ok[x][i+len]) {
					ok[i][i+len]=ok[i][x]+1;
				}
			}
		}
	}
	
	
	
	FOR(i,N+1) dp[i]=1010;
	dp[0]=0;
	FOR(i,N) if(dp[i]<1000) {
		for(x=i+1;x<=N;x++) if(ok[i][x]>=0) dp[x]=min(dp[x],dp[i]+1);
	}
	cout<<dp[N]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}