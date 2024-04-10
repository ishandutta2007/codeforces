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

int N,M,K;
vector<pair<int,int>> E[202020];

map<ll,ll> D[202020];
vector<vector<int>> Es;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>x>>y>>r;
		Es.push_back({r,x-1,y-1});
	}
	sort(ALL(Es));
	if(Es.size()>K) Es.resize(K);
	FORR(e,Es) {
		E[e[1]].push_back({e[2],e[0]});
		E[e[2]].push_back({e[1],e[0]});
	}
	
	set<pair<ll,ll>> S;
	FOR(i,N) {
		D[i][i]=0;
		S.insert({0,1000000LL*i+i});
	}
	
	while(S.size()) {
		auto a=*S.begin();
		S.erase(S.begin());
		int st=a.second/1000000;
		int cur=a.second%1000000;
		if(D[st][cur]!=a.first) continue;
		if(a.first && st<cur) {
			K--;
			if(K==0) {
				cout<<a.first<<endl;
				return;
			}
		}
		FORR(e,E[cur]) if(D[st].count(e.first)==0 || D[st][e.first]>a.first+e.second) {
			D[st][e.first]=a.first+e.second;
			S.insert({a.first+e.second,st*1000000LL+e.first});
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}