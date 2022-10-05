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
string S;
set<char> C;
vector<char> V;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	FORR(c,S) C.insert(c);
	FORR(c,C) V.push_back(c);
	
	string T;
	if(K>N) {
		T=S;
		FOR(i,K-N) T.push_back(V[0]);
	}
	else {
		for(i=K-1;i>=0;i--) {
			if(S[i]==V.back()) continue;
			T=S.substr(0,i);
			T+=*C.lower_bound(S[i]+1);
			while(T.size()<K) T.push_back(V[0]);
			break;
		}
	}
	cout<<T<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}