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

int N,M;
vector<vector<int>> G;
ll mo=1000000007;
int yes[1010101];
vector<int> NG[1010100];
map<vector<int>,int> MP;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		map<int,int> M;
		vector<vector<int>> VV;
		FOR(j,x) {
			cin>>y;
			M[y-1]++;
			yes[y-1]=1;
		}
		FORR(r,M) {
			if(VV.size()<=r.second) VV.resize(r.second+1);
			VV[r.second].push_back(r.first);
		}
		FORR(r,VV) if(r.size()) G.push_back(r);
	}
	G.push_back(vector<int>());
	FOR(i,M) if(yes[i]==0) G.back().push_back(i);
	FOR(i,G.size()) FORR(c,G[i]) NG[c].push_back(i);
	
	FOR(i,M) MP[NG[i]]++;
	ll ret=1;
	FORR(r,MP) for(i=1;i<=r.second;i++) ret=ret*i%mo;
	
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}