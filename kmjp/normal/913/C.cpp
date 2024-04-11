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
ll L,C[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L;
	FOR(i,31) {
		if(i<N) cin>>C[i];
		else C[i]=1LL<<61;
		if(i) C[i]=min(C[i],2*C[i-1]);
	}
	
	ll mi=1LL<<60;
	ll tot=0;
	for(i=30;i>=0;i--) {
		if(L&(1<<i)) {
			tot+=C[i];
		}
		else {
			mi=min(mi,tot+C[i]);
		}
	}
	mi=min(mi,tot);
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}