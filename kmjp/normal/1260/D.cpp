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

int M,N,K,T;
int A[202020];
int L[202020],R[202020],D[202020];

int ok(int v) {
	if(v>M) return 0;
	int S=A[v-1];
	vector<pair<int,int>> V;
	int i;
	FOR(i,K) if(D[i]>S) V.push_back({L[i],R[i]});
	sort(ALL(V));
	int ret=N+1;
	int PL=0,PR=0;
	FORR(v,V) {
		if(v.first<=PR) {
			PR=max(PR,v.second);
		}
		else {
			if(PL) ret+=(PR-PL+1)*2;
			PL=v.first;
			PR=v.second;
		}
	}
	if(PL) ret+=(PR-PL+1)*2;
	return ret<=T;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>M>>N>>K>>T;
	FOR(i,M) cin>>A[i];
	sort(A,A+M);
	reverse(A,A+M);
	FOR(i,K) cin>>L[i]>>R[i]>>D[i];
	
	int ret=0;
	for(i=20;i>=0;i--) if(ok(ret+(1<<i))) ret+=1<<i;
	
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}