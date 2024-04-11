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

ll N,M;
ll mo=1000000007;
ll rev2 = (mo+1)/2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	ll ret=0;
	ll g;
	for(g=1;g<=min(5000000LL,M);g++) {
		ret+=N%g;
		if(ret>=mo) ret-=mo;
	}
	if(M>5000000) {
		for(ll x=0;;x++) {
			ll L=max(N/(x+1)+1,g);
			ll R=min(M,(x?N/x:M));
			if(R<g) break;
			if(L>R) continue;
			ll a=(N%mo)*((R-L+1)%mo)%mo;
			ll b=x*((L+R)%mo)%mo*((R-L+1)%mo)%mo*rev2%mo;
			ret+=mo+a-b;
			while(ret>=mo) ret-=mo;
		}
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