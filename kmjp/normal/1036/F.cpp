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
ll N;

vector<ll> C;

ll issq(ll V) {
	ll a=sqrt(V);
	if(a*a==V) return 1;
	if((a-1)*(a-1)==V) return 1;
	if((a+1)*(a+1)==V) return 1;
	return 0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	for(ll a=2;a<=1000000;a++) {
		ll v=a*a*a;
		while(v<=1000000000000000000LL) {
			if(!issq(v)) C.push_back(v);
			if((double)v*a>2e18) break;
			v*=a;
		}
	}
	
	sort(ALL(C));
	C.erase(unique(ALL(C)),C.end());
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll ret=N-(ll)sqrt(N+0.5)-(lower_bound(ALL(C),N+1)-C.begin());
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}