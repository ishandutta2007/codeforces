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
ll L,R;
ll mo=1000000007;
int num[3];

ll dp[202020][3];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R;
	L--;
	num[0]=R/3-L/3;
	num[1]=(R+2)/3-(L+2)/3;
	num[2]=(R+1)/3-(L+1)/3;
	
	dp[0][0]=1;
	FOR(i,N) {
		dp[i+1][0]=(dp[i][0]*num[0]+dp[i][1]*num[2]+dp[i][2]*num[1])%mo;
		dp[i+1][1]=(dp[i][0]*num[1]+dp[i][1]*num[0]+dp[i][2]*num[2])%mo;
		dp[i+1][2]=(dp[i][0]*num[2]+dp[i][1]*num[1]+dp[i][2]*num[0])%mo;
	}
	cout<<dp[N][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}