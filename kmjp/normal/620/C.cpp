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

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	x=0;
	vector<pair<int,int>> V;
	set<int> S;
	FOR(i,N) {
		cin>>y;
		if(S.count(y)) {
			V.push_back({x+1,i+1});
			x=i+1;
			S.clear();
		}
		else {
			S.insert(y);
		}
	}
	if(V.empty()) _P("-1\n");
	else {
		V.back().second=N;
		_P("%d\n",V.size());
		FORR(r,V) _P("%d %d\n",r.first,r.second);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}