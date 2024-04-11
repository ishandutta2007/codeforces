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
vector<int> E[1010101];
int P[1010101];
ll T[1010101];

ll S;
int dfs(int cur,int pre) {
	vector<int> PP;
	P[cur]=-1;
	FORR(e,E[cur]) if(e!=pre) {
		int x=dfs(e,cur);
		if(x>=0 && PP.size()<=1) PP.push_back(x);
		T[cur]+=T[e];
	}
	
	if(PP.size()>=2) {
		_P("%d %d\n",PP[0]+1,PP[1]+1);
		exit(0);
	}
	if(PP.size()>=1 && (pre>=0 && T[cur]==S*2)) {
		_P("%d %d\n",PP[0]+1,cur+1);
		exit(0);
	}
	if(T[cur]==S) return cur;
	if(PP.size()) return PP[0];
	return -1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int root=0;
	FOR(i,N) {
		cin>>x>>T[i];
		x--;
		if(x>=0) E[x].push_back(i);
		else root=i;
		S+=T[i];
	}
	if(S%3) return _P("-1\n");
	S/=3;
	
	auto p=dfs(root,-1);
	_P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}