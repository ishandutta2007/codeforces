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
int L[202020],R[202020];
set<pair<int,int>> S;
vector<int> A[202020],D[202020];
vector<int> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		A[L[i]].push_back(i);
		D[R[i]].push_back(i);
	}
	
	FOR(i,201010) {
		FORR(e,A[i]) {
			S.insert({R[e],e});
		}
		while(S.size()>K) {
			x=S.rbegin()->second;
			M.push_back(x+1);
			S.erase({R[x],x});
		}
		FORR(e,D[i]) {
			S.erase({R[e],e});
		}
	}
	
	sort(ALL(M));
	cout<<M.size()<<endl;
	FORR(m,M) cout<<m<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}