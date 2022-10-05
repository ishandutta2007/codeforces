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

int H,Q;
ll CL,CR;
vector<pair<ll,ll>> O,O2;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>Q;
	CL=0,CR=1LL<<(H-1);
	ll L,R;
	
	while(Q--) {
		cin>>x>>L>>R>>y;
		L -= 1LL<<(x-1);
		L <<= H-x;
		
		R++;
		R -= 1LL<<(x-1);
		R <<= H-x;
		
		if(y==1) {
			CL=max(L,CL);
			CR=min(R,CR);
		}
		else {
			O.emplace_back(L,R);
			O2.emplace_back(R,L);
		}
	}
	
	sort(ALL(O));
	sort(ALL(O2));
	reverse(ALL(O2));
	FORR(r,O) if(r.first<=CL && CL<r.second) CL=r.second;
	FORR(r,O2) if(r.second<CR && CR<=r.first) CR=r.second;
	
	if(CL+1<CR) return _P("Data not sufficient!\n");
	if(CL>=CR) return _P("Game cheated!\n");
	cout << CL + (1LL<<(H-1)) << endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}