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

int T;
ll D,M;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	
	cin>>T;
	while(T--) {
		cin>>D>>M;
		ll dp[33]={};
		
		ll ret=0;
		dp[0]=1;
		for(i=1;i<=32;i++) {
			
			ll num=0;
			if(D<=((1LL<<i)-1)) {
				num=D-((1LL<<(i-1))-1);
			}
			else {
				num=(1LL<<i)-(1LL<<(i-1));
			}
			FOR(x,i) (dp[i]+=dp[x]*num)%=M;
			ret+=dp[i];
			
			if(D<=(1LL<<i)-1) break;
		}
		cout<<ret%M<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}