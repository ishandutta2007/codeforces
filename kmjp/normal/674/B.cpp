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
int A,B,C,D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	cin>>A>>B>>C>>D;
	vector<int> V;
	for(i=1;i<=N;i++) {
		if(i==A) continue;
		if(i==B) continue;
		if(i==C) continue;
		if(i==D) continue;
		V.push_back(i);
	}
	if(N==4 || K<=N) return _P("-1\n");
	_P("%d %d ",A,C);
	FOR(i,V.size()) _P("%d ",V[i]);
	_P("%d %d\n",D,B);
	_P("%d %d ",C,A);
	FOR(i,V.size()) _P("%d ",V[i]);
	_P("%d %d\n",B,D);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}