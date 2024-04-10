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

ll W;
ll C[9];
ll dp[9][840];
ll ret;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>W;
	ll sum=0;
	
	FOR(i,840) FOR(j,9) dp[j][i]=-1LL<<60;
	dp[0][0]=0;
	
	for(i=1;i<=8;i++) {
		cin>>C[i];
		FOR(x,840) if(dp[i-1][x]>=0) {
			FOR(y,840) if(C[i]>=y && dp[i-1][x]+y*i<=W) {
				ll add=min((C[i]-y)/840,(W-(dp[i-1][x]+y*i))/(840*i));
				dp[i][(x+y*i)%840]=max(dp[i][(x+y*i)%840],dp[i-1][x]+y*i+add*(840*i));
			}
		}
	}
	
	ll ret=0;
	FOR(i,840) ret=max(ret,dp[8][i]);
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}