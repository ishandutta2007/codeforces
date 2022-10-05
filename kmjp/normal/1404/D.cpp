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
int col[1010101];
int P[1010101];
vector<int> C[505050];
vector<int> E[1010101];

void dfs(int cur,int c) {
	if(col[cur]!=-1) return;
	col[cur]=c;
	FORR(e,E[cur]) dfs(e,c^1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	if(N%2==0) {
		cout<<"First"<<endl;
		FOR(i,N) cout<<(i+1)<<" ";
		FOR(i,N) cout<<(i+1)<<" ";
		cout<<endl;
		return;
	}
	
	cout<<"Second"<<endl;
	for(i=1;i<=2*N;i++) {
		cin>>P[i];
		C[P[i]].push_back(i);
	}
	
	for(i=1;i<=N;i++) {
		E[i].push_back(i+N);
		E[i+N].push_back(i);
		E[C[i][0]].push_back(C[i][1]);
		E[C[i][1]].push_back(C[i][0]);
	}
	
	MINUS(col);
	for(i=1;i<=2*N;i++) if(col[i]==-1) dfs(i,0);
	
	ll sum=0;
	for(i=1;i<=2*N;i++) if(col[i]) sum+=i;
	
	x=1;
	if(sum%(2*N)) x=0;
	for(i=1;i<=2*N;i++) if(col[i]==x) cout<<i<<" ";
	cout<<endl;	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}