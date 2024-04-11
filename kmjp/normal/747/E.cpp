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

deque<string> D;
string S;
int MD;
vector<string> V[1010100];

void dfs(int d) {
	V[d].push_back(D.front());
	MD=max(MD,d);
	D.pop_front();
	int x=atoi(D.front().c_str());
	D.pop_front();
	int i;
	FOR(i,x) dfs(d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	D.push_back("");
	FORR(c,S) {
		if(c==',') D.push_back("");
		else D.back().push_back(c);
	}
	while(D.size()) dfs(0);
	cout<<MD+1<<endl;
	FOR(i,MD+1) {
		FOR(j,V[i].size()) _P("%s%c",V[i][j].c_str(),(j==V[i].size()-1)?'\n':' ');
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}