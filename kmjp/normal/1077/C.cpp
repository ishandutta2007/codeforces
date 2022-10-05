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
int A[202020];
multiset<ll> M;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll S=0;
	FOR(i,N) {
		cin>>A[i];
		M.insert(A[i]);
		S+=A[i];
	}
	
	vector<int> ret;
	FOR(i,N) {
		S-=A[i];
		M.erase(M.find(A[i]));
		
		if(S%2==0 && M.count(S/2)) ret.push_back(i+1);
		
		S+=A[i];
		M.insert(A[i]);
		
	}
	
	cout<<ret.size()<<endl;
	FORR(r,ret) cout<<r<<" ";
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}