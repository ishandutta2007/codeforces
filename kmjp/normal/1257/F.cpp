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
int A[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	
	map<vector<int>,int> M;
	FOR(x,1<<15) {
		vector<int> C;
		FOR(i,N) {
			y=(A[i]>>15)^x;
			C.push_back(__builtin_popcount(y));
		}
		for(i=N-1;i>=0;i--) C[i]-=C[0];
		M[C]=(x<<15);
	}
	
	FOR(x,1<<15) {
		vector<int> C;
		FOR(i,N) {
			y=(A[i]&((1<<15)-1))^x;
			C.push_back(__builtin_popcount(y));
		}
		for(i=N-1;i>=0;i--) {
			C[i]-=C[0];
			C[i]=-C[i];
		}
		if(M.count(C)) {
			cout<<(M[C]|x)<<endl;
			return;
		}
	}
	cout<<-1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}