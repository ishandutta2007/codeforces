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
ll mo=998244353;
ll fact[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	fact[0]=1;
	for(i=1;i<=300000;i++) fact[i]=fact[i-1]*i%mo;
	
	
	cin>>N;
	map<int,int> M[2];
	map<pair<int,int>,int> L;
	FOR(i,N) {
		cin>>x>>y;
		M[0][x]++;
		M[1][y]++;
		L[{x,y}]++;
	}
	
	ll A=1,B=1,C=1;
	FORR(m,M[0]) A=A*fact[m.second]%mo;
	FORR(m,M[1]) B=B*fact[m.second]%mo;
	pair<int,int> p={-1,-1};
	FORR(m,L) {
		if(m.first.first<p.first || m.first.second<p.second) C=0;
		p=m.first;
		C=C*fact[m.second]%mo;
	}
	
	cout<<(fact[N]+C-A-B+2*mo)%mo<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}