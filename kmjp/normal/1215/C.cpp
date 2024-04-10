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
string S,T;
vector<int> A,B;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S>>T;
	
	FOR(i,N) {
		if(S[i]=='a' && T[i]=='b') A.push_back(i+1);
		if(S[i]=='b' && T[i]=='a') B.push_back(i+1);
	}
	vector<pair<int,int>> R;
	if((A.size()+B.size())%2) return _P("-1\n");
	while(A.size()>=2) {
		R.push_back({A.back(),A[A.size()-2]});
		A.pop_back();
		A.pop_back();
	}
	while(B.size()>=2) {
		R.push_back({B.back(),B[B.size()-2]});
		B.pop_back();
		B.pop_back();
	}
	if(A.size()) {
		R.push_back({A[0],A[0]});
		R.push_back({A[0],B[0]});
	}
	cout<<R.size()<<endl;
	FORR(r,R) cout<<r.first<<" "<<r.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}