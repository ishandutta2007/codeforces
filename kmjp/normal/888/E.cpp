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
ll M,A[101];

vector<ll> X;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	N=35;
	
	for(int mask=0;mask<1<<18;mask++) {
		ll tot=0;
		FOR(i,18) if(mask&(1<<i)) tot+=A[i];
		X.push_back(tot%M);
		X.push_back(tot%M+M);
	}
	sort(ALL(X));
	
	ll ret=0;
	for(int mask=0;mask<1<<17;mask++) {
		ll tot=0;
		FOR(i,17) if(mask&(1<<i)) tot+=A[18+i];
		tot%=M;
		x = lower_bound(ALL(X),2*M-tot)-X.begin();
		ret=max(ret,(tot+X[x-1])%M);
		
	}
	
	
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}