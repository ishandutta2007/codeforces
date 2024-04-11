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

vector<int> S[2];
int P[101];
int res;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int p=0;
	x=0;
	while(1) {
		cin>>s;
		S[p].push_back(x);
		P[x]=p;
		x++;
		cin>>s;
		if(s=="+") p=0;
		if(s=="-") p=1;
		if(s=="=") {
			cin>>s;
			res = atoi(s.c_str());
			break;
		}
	}
	int mipl=S[0].size(),mapl=S[0].size()*res;
	int mimi=S[1].size(),mami=S[1].size()*res;
	
	x=-1,y=-1;
	if(mipl-mimi>=res && mipl-mami<=res) x=mipl, y=res-x;
	if(mapl-mimi>=res && mapl-mami<=res) x=mapl, y=res-x;
	if(mapl-mimi>=res && mipl-mimi<=res) y=mimi, x=res+y;
	if(mapl-mami>=res && mipl-mami<=res) y=mami, x=res+y;
	if(x==-1) return _P("Impossible\n");
	int pi=0,mi=0;
	_P("Possible\n");
	FOR(i,S[0].size()+S[1].size()) {
		if(i) _P(" %c ","+-"[P[i]]);
		if(P[i]==0) _P("%d",x/S[0].size()+(pi<x%S[0].size())), pi++;
		if(P[i]==1) _P("%d",y/S[1].size()+(mi<y%S[1].size())), mi++;
	}
	_P(" = %d\n",res);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}