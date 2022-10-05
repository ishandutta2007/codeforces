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
ll A[1010101];
int L[1010101],R[1010101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) scanf("%d",&A[i]);
	
	ll ret=0;
	
	FOR(j,2) {
		vector<pair<int,int>> V;
		V.push_back({-1,1<<30});
		FOR(i,N) {
			while(V.back().second<=A[i]) V.pop_back();
			L[i]=V.back().first;
			V.push_back({i,A[i]});
		}
		V.clear();
		V.push_back({N,1<<30});
		for(i=N-1;i>=0;i--) {
			while(V.back().second<A[i]) V.pop_back();
			R[i]=V.back().first;
			V.push_back({i,A[i]});
		}
		FOR(i,N) ret+=A[i]*(R[i]-i)*(i-L[i]);
		
		FOR(i,N) A[i]=-A[i];
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}