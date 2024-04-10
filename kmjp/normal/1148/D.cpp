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
int A[303030],B[303030];
int F[303030];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> V[2];
	FOR(i,N) {
		cin>>A[i]>>B[i];
		
		if(A[i]<B[i]) {
			V[0].push_back({-A[i],i});
		}
		else {
			V[1].push_back({A[i],i});
		}
	}
	
	sort(ALL(V[0]));
	sort(ALL(V[1]));
	if(V[0].size()<V[1].size()) swap(V[0],V[1]);
	_P("%d\n",V[0].size());
	FORR(v,V[0]) _P("%d ",v.second+1);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}