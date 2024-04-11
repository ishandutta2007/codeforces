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

const ll mo0=1000000007,mo1=1000000009;
const ll add0=1000010007, add1=1003333331;
ll mul0,mul1;

pair<ll,ll> add(pair<ll,ll> v,int c) {
	return {(v.first*mul0+c+add0)%mo0,(v.second*mul1+c+add1)%mo1};

}

int N;
int C[301010];
string S;
vector<int> E[303030];
set<pair<ll,ll> > SS[303030];
map<int,int> MP;

void dfs(int cur,int pre,pair<ll,ll> v) {
	int mal=0,ind=0,i;
	v=add(v,S[cur]);
	FOR(i,E[cur].size()) if(E[cur][i]!=pre) {
		dfs(E[cur][i],cur,v);
		if(SS[E[cur][i]].size()>mal) mal=SS[E[cur][i]].size(), ind=E[cur][i];
	}
	
	if(mal) swap(SS[cur],SS[ind]);
	FOR(i,E[cur].size()) if(E[cur][i]!=pre && E[cur][i] != ind) {
		FORR(r,SS[E[cur][i]]) SS[cur].insert(r);
	}
	SS[cur].insert(v);
	MP[SS[cur].size()+C[cur]]++;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	mul0=10009+(((ll)&mul0)>>5)%259;
	mul1=10007+(((ll)&mul1)>>5)%257;
	
	cin>>N;
	FOR(i,N) cin>>C[i];
	cin>>S;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,-1,{1,1});
	cout<<MP.rbegin()->first<<endl;
	cout<<MP.rbegin()->second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}