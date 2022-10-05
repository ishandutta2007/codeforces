#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

ll N;
int Q;
map<int,pair<char,int> > M;
int X,Y;
char D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	M[0]={'U',0};
	M[N+1]={'L',0};
	
	while(Q--) {
		cin>>X>>Y>>D;
		
		if(M.count(X)) {
			_P("0\n");
			continue;
		}
		
		auto it=M.lower_bound(X);
		if(D=='L') it--, x=X-it->first;
		else x=it->first-X;
		if(D==it->second.first) x+=it->second.second;
		
		_P("%d\n",x);
		M[X]={D,x};
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}