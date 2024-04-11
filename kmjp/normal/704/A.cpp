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


int N,Q;
set<pair<int,int>> S;
set<int> NT[303030];
int UR;
vector<int> EV;
void solve() {
	int i,j,k,l,r,x,y; string s;
	scanf("%d%d",&N,&Q);
	FOR(i,Q) {
		scanf("%d%d",&x,&y);
		if(x==1) {
			NT[y].insert(i);
			S.insert({i,y});
			UR++;
			EV.push_back(i);
		}
		if(x==2) {
			FORR(r,NT[y]) S.erase({r,y});
			NT[y].clear();
		}
		if(x==3) {
			while(S.size()) {
				auto e=*S.begin();
				if(e.first>EV[y-1]) break;
				S.erase(e);
				NT[e.second].erase(e.first);
			}
		}
		_P("%d\n",S.size());
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}