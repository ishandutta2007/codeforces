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
int C[202020];
int W[202020];
set<pair<int,int>> P;
vector<int> E[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>A[i];
		C[A[i]]++;
	}
	for(i=1;i<=N;i++) {
		W[i]=i;
		if(C[i]==0) P.insert({W[i],i});
	}
	
	for(i=N-2;i>=0;i--) {
		x=P.begin()->second;
		P.erase(P.begin());
		E[A[i]].push_back(x);
		W[A[i]]=max(W[x],W[A[i]]);
		x=A[i];
		C[x]--;
		if(C[x]==0) P.insert({W[x],x});
	}
	
	cout<<x<<endl;
	for(i=1;i<=N;i++) FORR(e,E[i]) cout<<e<<" "<<i<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}