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
int P[2020];
vector<int> E[2020];
int C[2020];
int child[2020];
vector<int> cand;
int num[2020];
vector<int> valid;

int dfs(int cur){
	child[cur]=1;
	FORR(e,E[cur]) child[cur]+=dfs(e);
	if(child[cur]-1<C[cur]) {
		cout<<"NO"<<endl;
		exit(0);
	}
	return child[cur];
}

void dfs2(int cur) {
	num[cur]=valid[C[cur]];
	valid.erase(valid.begin()+C[cur]);
	FORR(e,E[cur]) dfs2(e);
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int root=0;
	FOR(i,N) {
		cin>>P[i+1]>>C[i+1];
		E[P[i+1]].push_back(i+1);
		if(P[i+1]==0) root=i+1;
	}
	dfs(root);
	FOR(i,N) valid.push_back(i+1);
	dfs2(root);
	cout<<"YES"<<endl;
	FOR(i,N) cout<<num[i+1]<<" ";
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}