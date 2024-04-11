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

int N,K;
int A[202],B[202];

int dp[202][30*200];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	FOR(i,202) FOR(j,30*200) dp[i][j]=-1<<30;
	dp[0][0]=0;
	
	FOR(i,N) {
		ll X;
		cin>>X;
		while(X%5==0) X/=5, A[i]++;
		while(X%2==0) X/=2, B[i]++;
		
		for(j=i;j>=0;j--) {
			for(x=30*j;x>=0;x--) {
				dp[j+1][x+A[i]]=max(dp[j+1][x+A[i]],dp[j][x]+B[i]);
			}
		}
	}
	
	int ma=0;
	FOR(i,30*200) ma=max(ma,min(dp[K][i],i));
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}