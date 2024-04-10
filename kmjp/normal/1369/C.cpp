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

int T,N,K;
int A[202020],W[202020];
vector<int> V[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		FOR(i,N) cin>>A[i];
		FOR(i,K) {
			cin>>W[i];
			V[i].clear();
		}
		sort(A,A+N);
		sort(W,W+K);
		reverse(W,W+K);
		FOR(i,K) V[K-1-i].push_back(A[N-1-i]);
		ll sum=0;
		x=0;
		FOR(i,K) {
			W[i]--;
			FOR(j,W[i]) V[i].push_back(A[x++]);
			sort(ALL(V[i]));
			sum+=V[i][0];
			sum+=V[i].back();
		}
		cout<<sum<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}