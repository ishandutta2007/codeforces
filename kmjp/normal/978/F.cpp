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


int N,M;
int R[202020];
int A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	map<int,vector<int>> MP;
	cin>>N>>M;
	FOR(i,N) {
		cin>>R[i];
		MP[R[i]].push_back(i);
	}
	int tot=0;
	FORR(m,MP) {
		FORR(e,m.second) A[e]=tot;
		tot+=m.second.size();
	}
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		if(R[x]>R[y]) A[x]--;
		if(R[y]>R[x]) A[y]--;
	}
	
	FOR(i,N) cout<<A[i]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}