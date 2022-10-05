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
int N,M;
vector<int> E[101010];
vector<ll> C;
const ll mo=1000000007;

int dfs(int cur,int pre) {
	int v=1;
	FORR(e,E[cur]) if(e!=pre) v+=dfs(e,cur);
	
	if(v<N) C.push_back(1LL*v*(N-v));
	return v;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		C.clear();
		dfs(0,0);
		
		sort(ALL(C));
		vector<ll> P;
		cin>>M;
		FOR(i,M) {
			cin>>x;
			P.push_back(x);
		}
		sort(ALL(P));
		while(P.size()>C.size()) {
			ll a=P.back();
			P.pop_back();
			P.back()=P.back()*a%mo;
		}
		
		reverse(ALL(C));
		reverse(ALL(P));
		while(P.size()<C.size()) P.push_back(1);
		ll ret=0;
		FOR(i,P.size()) {
			(ret+=(P[i]%mo)*(C[i]%mo))%=mo;
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}