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
int dp[8];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,8) dp[i]=100000000;
	FOR(i,N) {
		string S;
		cin>>x>>S;
		int mask=0;
		FORR(c,S) mask |= 1<<(c-'A');
		dp[mask]=min(dp[mask],x);
	}
	
	int ret=100000000;
	FOR(i,256) {
		int tot=0;
		int tm=0;
		FOR(j,8) if(i&(1<<j)) {
			tm |= j;
			tot+=dp[j];
		}
		if(tm==7) ret=min(ret,tot);
	}
	if(ret>=10000000) ret=-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}