#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
ll T;
ll G[202020],C[202020];
ll D[202020];
vector<pair<ll,ll>> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>T;
	FOR(i,N) cin>>G[i]>>C[i];
	
	set<pair<ll,ll>> S={{0,0}};
	ll sum=0;
	FOR(i,N) {
		if(i>0) {
			cin>>x;
			sum+=x;
		}
		C[i]=(C[i]+sum)%T;
		if(C[i]<=G[i]) {
			V.push_back({G[i]-C[i],T-C[i]});
			S.insert({(G[i]-C[i]+T-1)%T,0LL});
		}
		else {
			V.push_back({T-(C[i]-G[i]),T});
			V.push_back({0,T-C[i]});
			S.insert({(T-(C[i]-G[i])+T-1)%T,0LL});
		}
		S.insert({(T-C[i])%T,0LL});
	}
	FORR2(a,b,V) {
		
		pair<ll,ll> cand={0,1LL<<60};
		
		while(1) {
			auto it=S.lower_bound(make_pair(a,0LL));
			if(it==S.end()) break;
			if(it->first>=b) break;
			auto p=*it;
			S.erase(it);
			p.second+=b-p.first;
			p.first=b%T;
			if(p.second<cand.second) cand=p;
		}
		if(cand.second!=1LL<<60) S.insert(cand);
	}
	ll mi=1LL<<60;
	FORR(a,S) mi=min(mi,a.second);
	cout<<mi+sum<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}