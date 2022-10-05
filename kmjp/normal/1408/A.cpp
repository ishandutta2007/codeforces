#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int T;
int N;
int A[101],B[101],C[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		FOR(i,N) cin>>C[i];
		vector<int> R;
		R.push_back(A[0]);
		for(i=1;i<N-1;i++) {
			if(A[i]!=R.back()) R.push_back(A[i]);
			else if(B[i]!=R.back()) R.push_back(B[i]);
			else if(C[i]!=R.back()) R.push_back(C[i]);
		}
		if(A[N-1]!=R.back()&&A[N-1]!=R[0]) R.push_back(A[N-1]);
		else if(B[N-1]!=R.back()&&B[N-1]!=R[0]) R.push_back(B[N-1]);
		else R.push_back(C[N-1]);
		FORR(r,R) cout<<r<<" ";
		cout<<endl;
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}