#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int K;
ll F[6];
int Q;
int N;

ll dp[1010101];
ll p10[8];
int FS[10]={0,0,0,1,0,0,2,0,0,3};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p10[0]=1;
	FOR(i,6) p10[i+1]=p10[i]*10;
	
	cin>>K;
	FOR(i,6) cin>>F[i];
	
	FOR(i,1000001) dp[i]=-1LL<<60;
	dp[0]=0;
	FOR(i,6) {
		int cand=3*(K-1);
		int cur=1;
		while(cand) {
			int num=min(cand,cur);
			
			ll sc=num*F[i];
			ll v=num*3*p10[i];
			for(j=999999;j>=v;j--) dp[j]=max(dp[j],dp[j-v]+sc);
			cand-=num;
			cur*=2;
		}
	}
	
	FOR(i,6) {
		for(j=999999;j>=0;j--) {
			for(x=1;x<=9;x++) if(j>=x*p10[i]) dp[j]=max(dp[j],dp[j-x*p10[i]]+FS[x]*F[i]);
		}
	}
	
	
	
	cin>>Q;
	while(Q--) {
		cin>>N;
		cout<<dp[N]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}