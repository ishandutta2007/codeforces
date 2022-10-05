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

string S;
int N,C[2];

vector<int> V[202020];
queue<int> Q[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	FORR(c,S) {
		c-='0';
		C[c]++;
	}
	
	if(C[0]<=C[1]) return _P("-1\n");
	FOR(i,C[0]-C[1]) Q[0].push(i);
	FOR(i,N) {
		if(Q[S[i]].empty()) return _P("-1\n");
		x=Q[S[i]].front();
		Q[S[i]].pop();
		V[x].push_back(i+1);
		Q[S[i]^1].push(x);
	}
	
	cout<<C[0]-C[1]<<endl;
	FOR(i,C[0]-C[1]) {
		cout<<V[i].size();
		FORR(v,V[i]) cout<<" "<<v;
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}