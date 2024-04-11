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

int N,K,L;
int A[101010];
int mi[101010];
int did[101010];
vector<int> V[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>L;
	FOR(i,N*K) cin>>A[i];
	sort(A,A+N*K);
	k=0;
	while(k<N*K&&A[k]-A[0]<=L) k++;
	if(k<N) return _P("0\n");
	
	FOR(i,k) V[i/K].push_back(A[i]);
	
	for(i=N-1;i>=0;i--) {
		if(V[i].size()) break;
		--k;
		V[i].push_back(V[k/K].back());
		V[k/K].pop_back();
	}
	
	
	
	ll ret=0;
	FOR(i,N) ret+=V[i][0];
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}