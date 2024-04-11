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


int N,L,R;
int A[101010],B[101010];
pair<int,int> P[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>L>>R;
	FOR(i,N) cin>>A[i];
	FOR(i,N) cin>>P[i].first, P[i].second=i;
	
	sort(P,P+N);
	int pre=-1LL<<30;
	FOR(i,N) {
		x=P[i].second;
		int need=pre+1+A[x];
		if(need>R) return _P("-1\n");
		need=max(L,need);
		B[x]=need;
		pre=B[x]-A[x];
	}
	
	FOR(i,N) _P("%d%c",B[i],(i==N-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}