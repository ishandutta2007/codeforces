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

int T,N,M;
ll C[505050];
vector<int> E[505050];
int num[505050];
map<vector<int>,ll> mp;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d\n",&T);
	while(T--) {
		scanf("%d%d\n",&N,&M);
		FOR(i,N) {
			scanf("%lld",&C[i]);
			E[i].clear();
			num[i]=0;
		}
		FOR(i,M) {
			scanf("%d%d\n",&x,&y);
			E[y-1].push_back(x-1);
		}
		mp.clear();
		FOR(i,N) if(E[i].size()) {
			sort(ALL(E[i]));
			mp[E[i]]+=C[i];
		}
		
		ll g=0;
		FORR(m,mp) g=__gcd(g,m.second);
		_P("%lld\n",g);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}