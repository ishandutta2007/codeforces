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
string S,T;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	set<int> C[2];
	FOR(i,N) if(S[i]!=T[i]) C[S[i]=='0'].insert(i);
	
	if(C[0].size()!=C[1].size()) return _P("-1\n");
	int ret=0;
	while(C[0].size()) {
		x=*C[0].begin();
		y=*C[1].begin();
		if(x<y) {
			i=0;
		}
		else {
			i=1;
			x=y;
		}
		ret++;
		while(1) {
			auto it=C[i^1].lower_bound(x);
			if(it==C[i^1].end()) break;
			y=*it;
			C[i].erase(x);
			C[i^1].erase(y);
			auto it2=C[i].lower_bound(y);
			if(it2==C[i].end()) break;
			x=*it2;
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}