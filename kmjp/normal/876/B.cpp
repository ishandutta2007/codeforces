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

int N,K,M;
int A[101010];
vector<int> V[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>M;
	FOR(i,N) {
		cin>>A[i];
		V[A[i]%M].push_back(A[i]);
	}
	FOR(i,M) if(V[i].size()>=K) {
		_P("Yes\n");
		FOR(j,K) _P("%d%c",V[i][j],(j==K-1)?'\n':' ');
		return;
	}
	_P("No\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}