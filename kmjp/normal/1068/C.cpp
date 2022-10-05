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
vector<int> V[5050];



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	for(i=1;i<=N;i++) V[i].push_back(i);
	FOR(i,M) {
		cin>>x>>y;
		V[x].push_back(N+1+i);
		V[y].push_back(N+1+i);
	}
	for(i=1;i<=N;i++) {
		cout<<V[i].size()<<endl;
		FORR(v,V[i]) cout<<i<<" "<<v<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}