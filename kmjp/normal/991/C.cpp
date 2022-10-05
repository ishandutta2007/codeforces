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

ll N;

ll how(ll v) {
	ll L=N;
	if(v<=0) return 0;
	
	ll a=0,b=0;
	while(L) {
		a+=min(L,v);
		L-=min(L,v);
		b+=L/10;
		L-=L/10;
	}
	
	return a>=b;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ret=N;
	for(i=60;i>=0;i--) if(how(ret-(1LL<<i))) ret-=1LL<<i;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}