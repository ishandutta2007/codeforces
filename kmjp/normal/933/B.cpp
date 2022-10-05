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

ll P,K;
vector<ll> V;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>P>>K;
	while(P) {
		ll Q=P/K;
		ll R=P-Q*K;
		if(R<0) Q--,R+=K;
		if(R>=K) Q++,R-=K;
		V.push_back(R);
		P=-Q;
	}
	
	cout<<V.size()<<endl;
	FOR(i,V.size()) {
		cout<<V[i];
		if(i==V.size()-1) cout<<endl;
		else cout<<" ";
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}