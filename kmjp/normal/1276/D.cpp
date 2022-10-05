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
vector<pair<int,int>> E[202020];
int U[202020],V[202020];
const ll mo=998244353;

ll dp[202020][3];

void dfs(int cur,int pre) {
	sort(ALL(E[cur]));
	int d=0;
	vector<ll> prefix,suffix;
	vector<ll> vs;
	prefix.push_back(1);
	suffix.push_back(1);
	FORR(e,E[cur]) {
		if(e.second==pre) {
			d=lower_bound(ALL(E[cur]),e)-E[cur].begin();
		}
		else {
			dfs(e.second,cur);
			prefix.push_back(prefix.back()*(dp[e.second][0]+dp[e.second][1])%mo);
			vs.push_back(e.second);
		}
	}
	reverse(ALL(E[cur]));
	FORR(e,E[cur]) if(e.second!=pre) {
		suffix.push_back(suffix.back()*(dp[e.second][0]+dp[e.second][2])%mo);
	}
	reverse(ALL(E[cur]));
	reverse(ALL(suffix));
	int i;
	/*
	cout<<cur<<" "<<d<<" "<<prefix.size()<<":"<<suffix.size()<<endl;
	FORR(p,prefix) cout<<p<<" ";
	cout<<endl;
	FORR(p,suffix) cout<<p<<" ";
	cout<<endl;
	*/
	dp[cur][1]=prefix[d]*suffix[d]%mo;
	dp[cur][2]=prefix.back();
	FOR(i,vs.size()) {
		if(i<d) (dp[cur][0]+=prefix[i]*dp[vs[i]][2]%mo*suffix[i+1])%=mo;
		else (dp[cur][2]+=prefix[i]*dp[vs[i]][2]%mo*suffix[i+1])%=mo;
	}
	
	//cout<<"!"<<cur<<" "<<dp[cur][0]<<" "<<dp[cur][1]<<" "<<dp[cur][2]<<endl;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>U[i]>>V[i];
		U[i]--;
		V[i]--;
		E[U[i]].push_back({i,V[i]});
		E[V[i]].push_back({i,U[i]});
	}
	E[0].push_back({N-1,N});
	
	dfs(0,N);
	cout<<(dp[0][0]+dp[0][1])%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}