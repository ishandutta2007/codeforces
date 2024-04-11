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

int N,K;
int A[2020],S[2020];

set<int> B,cand;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>K>>N;
	FOR(i,K) {
		cin>>A[i];
		S[i+1]=S[i]+A[i];
	}
	FOR(i,N) cin>>x, B.insert(x);
	FOR(i,K) cand.insert(*B.begin()-S[i+1]);
	
	int ok=0;
	FORR(c,cand) {
		set<int> C=B;
		x = c;
		FOR(i,K) {
			x+=A[i];
			C.erase(x);
		}
		if(C.empty()) ok++;
	}
	cout<<ok<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}