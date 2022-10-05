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
int A[505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int S=0;
	vector<int> B,C;
	FOR(i,N) {
		cin>>A[i];
		S+=A[i];
		if(A[i]>1) B.push_back(i);
		else C.push_back(i);
	}
	
	if(S<2*(N-1)) return _P("NO\n");
	
	int ret=(B.size()-1)+min(2,(int)C.size());
	vector<pair<int,int>> R;
	FOR(i,B.size()-1) {
		R.push_back({B[i],B[i+1]});
		A[B[i]]--;
		A[B[i+1]]--;
	}
	if(C.size()) {
		R.push_back({B[0],C.back()});
		A[B[0]]--;
		C.pop_back();
	}
	if(C.size()) {
		R.push_back({B.back(),C.back()});
		A[B.back()]--;
		C.pop_back();
	}
	
	FORR(b,B) {
		while(A[b] && C.size()) {
			A[b]--;
			R.push_back({b,C.back()});
			C.pop_back();
		}
	}
	cout<<"YES "<<ret<<endl;
	cout<<R.size()<<endl;
	FORR(r,R) cout<<(r.first+1)<<" "<<(r.second+1)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}