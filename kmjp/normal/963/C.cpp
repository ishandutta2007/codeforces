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
ll H[202020],W[202020],C[202020];
map<pair<ll,ll>,ll> M;
map<ll,vector<ll>> Ws;
map<ll,vector<ll>> Hs;
vector<ll> Wall,Hall;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll g=0;
	FOR(i,N) {
		cin>>W[i]>>H[i]>>C[i];
		M[{H[i],W[i]}]=C[i];
		g=__gcd(g,C[i]);
		Wall.push_back(W[i]);
		Hall.push_back(H[i]);
		Hs[H[i]].push_back(W[i]);
		Ws[W[i]].push_back(H[i]);
	}
	sort(ALL(Wall));
	sort(ALL(Hall));
	Wall.erase(unique(ALL(Wall)),Wall.end());
	Hall.erase(unique(ALL(Hall)),Hall.end());
	
	FORR(w,Ws) {
		if(w.second.size()!=Hall.size()) return _P("0\n");
		sort(ALL(w.second));
	}
	FORR(h,Hs) {
		if(h.second.size()!=Wall.size()) return _P("0\n");
		sort(ALL(h.second));
	}
	FOR(i,Hall.size()) {
		FOR(j,Wall.size()) {
			double a=M[{Hall[0],Wall[0]}];
			double b=M[{Hall[0],Wall[j]}];
			double c=M[{Hall[i],Wall[0]}];
			double d=M[{Hall[i],Wall[j]}];
			if(abs(b/a-d/c)>=1e-10) return _P("0\n");
		}
	}
	
	ll ret=0;
	for(ll a=1;a*a<=g;a++) {
		if(g%a==0) {
			ret++;
			if(a*a!=g) ret++;
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}