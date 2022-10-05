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
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>K;
	
	if(K==0) {
		cin>>s;
		if(s=="0") return _P("Yes\n");
		if(s=="?") {
			int turn=0;
			FOR(i,N) {
				cin>>s;
				if(s!="?") turn++;
			}
			return _P("%s\n",(turn%2==1)?"Yes":"No");
		}
		else return _P("No\n");
	}
	else {
		ll tot=0;
		int fail=0;
		FOR(i,N+1) {
			cin>>s;
			if(s=="?") {
				return _P("%s\n",(N%2==1)?"Yes":"No");
			}
			if(tot%abs(K)) fail=1;
			tot /= K;
			tot += atoi(s.c_str());
		}
		
		if(tot || fail) return _P("No\n");
		_P("Yes\n");
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}