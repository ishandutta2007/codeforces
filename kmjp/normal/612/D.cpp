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

int N,K;
vector<pair<int,int>> R;
set<int> S;
vector<pair<int,int>> E;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>x>>y;
		E.push_back({x,0});
		E.push_back({y,1});
	}
	sort(ALL(E));
	
	int num=0;
	FORR(r,E) {
		if(r.second==0) {
			num++;
			if(num==K) R.push_back({r.first,0});
		}
		else {
			if(num==K) R.back().second=r.first;
			num--;
		}
	}
	
	
	_P("%d\n",R.size());
	FORR(r,R) _P("%d %d\n",r.first,r.second);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}