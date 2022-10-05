#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll A,B,C,L;
ll ret;
ll dp[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A>>B>>C>>L;
	
	dp[0]=1;
	for(i=1;i<=300000;i++) dp[i]=dp[i-1]+i/2+1;
	
	for(i=0;i<=L;i++) {
		ll a=A+i;
		ll left = L-i;
		ret += (left+1)*(left+2)/2;
	}
	FOR(j,3) {
		for(i=0;i<=L;i++) {
			ll a=A+i;
			ll left = L-i;
			// B+b+C+c<=a
			ll x=min(left,a-B-C);
			if(x>=0) ret -= (x+1)*(x+2)/2;
		}
		if(j==0) swap(A,B);
		if(j==1) swap(A,C);
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}