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
set<int> E[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		E[x-1].insert(y-1);
		E[y-1].insert(x-1);
	}
	
	int ret=0;
	set<pair<int,int>> S;
	FOR(i,N) S.insert({E[i].size(),i});
	while(S.size()) {
		if(S.begin()->first>=2) break;
		if(S.begin()->first==0) {
			ret++;
			S.erase(S.begin());
		}
		else if(S.begin()->first==1) {
			x=S.begin()->second;
			y=*E[x].begin();
			S.erase(S.begin());
			S.erase({E[y].size(),y});
			E[y].erase(x);
			S.insert({E[y].size(),y});
		}
		
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}