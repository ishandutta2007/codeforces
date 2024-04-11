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

int N,K,A,M;
int X[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>A>>M;
	
	set<int> S;
	S.insert(0);
	S.insert(N+1);
	int num=(N+1)/(A+1);
	FOR(i,M) {
		cin>>X[i];
		auto it=S.lower_bound(X[i]);
		auto it2=it;
		it--;
		num -= (*it2-*it-1+1)/(A+1);
		num += (X[i]-*it-1+1)/(A+1);
		num += (*it2-X[i]-1+1)/(A+1);
		S.insert(X[i]);
		if(num<K) return _P("%d\n",i+1);
	}
	_P("-1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}