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
string S;
int dp[5050][5050];
int sum[5050][5050];
int pre[28];
int mo=1000000007;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	
	for(i=1;i<=N;i++) {
		sum[i][0]=1;
		int c = S[i-1]-'a';
		for(j=1;j<=N;j++) {
			dp[i][j]=((ll)dp[i][j-1]+sum[i][j-1]-sum[pre[c]][j-1]+mo)%mo;
			sum[i+1][j]=(sum[i][j]+dp[i][j])%mo;
		}
		pre[c]=i+1;
	}
	
	cout<<sum[N+1][N]%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}