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

int N,M,K;
int A[5050],B[5050],C[5050];
int more[5050];
int chance[5050];
vector<int> E[5050];
vector<int> cand[5050];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
		if(K<A[i]) return _P("-1\n");
		more[i]=K-A[i];
		K+=B[i];
		chance[i]=i;
	}
	more[N]=K;
	FOR(i,M) {
		cin>>x>>y;
		chance[y-1]=max(chance[y-1],x-1);
	}
	FOR(i,N) E[chance[i]].push_back(i);
	for(i=N-1;i>=0;i--) {
		more[i]=min(more[i],more[i+1]);
		FORR(e,E[i]) cand[more[i+1]].push_back(C[e]);
	}
	
	int ret=0;
	multiset<int> S;
	for(i=5000;i>=1;i--) {
		FORR(e,cand[i]) S.insert(e);
		if(S.size()) {
			ret+=*S.rbegin();
			S.erase(S.find(*S.rbegin()));
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