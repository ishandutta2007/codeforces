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
ll A[101010];
ll T;
multiset<ll> L,R;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		T+=A[i];
		L.insert(A[i]);
	}
	
	if(T%2) return _P("NO\n");
	T/=2;
	
	if(L.count(T)) return _P("YES\n");
	
	FOR(i,N) {
		L.erase(L.find(A[i]));
		T-=A[i];
		R.insert(A[i]);
		
		if(T==0) return _P("YES\n");
		if(T>0 && L.count(T)) return _P("YES\n");
		if(T<0 && R.count(-T)) return _P("YES\n");
	}
	
	_P("NO\n");
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}