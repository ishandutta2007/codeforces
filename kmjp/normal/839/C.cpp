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
vector<int> E[101010];
double ret;

void dfs(int cur,int pre,double prob,int dep) {
	if(E[cur].size()==1) {
		ret+=dep*prob;
	}
	else {
		FORR(e,E[cur]) if(e!=pre) {
			dfs(e,cur,prob/(E[cur].size()-1),dep+1);
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	if(N==1) return _P("0\n");
	
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	FORR(e,E[0]) dfs(e,0,1.0/E[0].size(),1);
	
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}