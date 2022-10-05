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
ll K;
int P[1010101];
int Q[1010101];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	ll mi=1LL*N*(N+1)/2;
	ll ma=0;
	set<int> S;
	for(i=1;i<=N;i++) {
		ma+=max(i,N+1-i);
		P[i]=Q[i]=i;
	}
	if(K<mi) return _P("-1\n");
	K=min(K,ma);
	cout<<K<<endl;
	K-=mi;
	for(x=1,y=N;K>=y-x&&x<y;x++,y--) {
		K-=y-x;
		swap(P[x],P[y]);
	}
	swap(P[x],P[x+K]);
	
	FOR(i,N) cout<<P[i+1]<<" ";
	cout<<endl;
	FOR(i,N) cout<<Q[i+1]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}