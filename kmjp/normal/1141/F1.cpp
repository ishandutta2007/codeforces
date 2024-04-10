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
int A[5050];
map<ll,vector<pair<int,int>>> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N) {
		ll cur=0;
		set<ll> S;
		for(j=i;j<N;j++) {
			cur+=A[j];
			if(S.count(cur)==0) {
				S.insert(cur);
				M[cur].push_back({j,i});
			}
		}
	}
	
	vector<pair<int,int>> ret;
	FORR(m,M) {
		vector<pair<int,int>> C=m.second;
		sort(ALL(C));
		vector<pair<int,int>> T;
		int pre=-1;
		FORR(c,C) {
			if(c.second>pre) {
				T.push_back(c);
				pre=c.first;
			}
		}
		
		
		if(T.size()>ret.size()) swap(T,ret);
	}
	cout<<ret.size()<<endl;
	FORR(r,ret) cout<<r.second+1<<" "<<r.first+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}