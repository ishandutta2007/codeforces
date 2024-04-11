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
int A[1<<22];
int S[1<<22];
vector<int> V;

void dfs(int v) {
	if(S[v]==1) return;
	S[v]=1;
	if(A[v]) {
		V.push_back(v);
		A[v]=0;
	}
	int i;
	FOR(i,22) if(v&(1<<i)) dfs(v^(1<<i));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,M) {
		scanf("%d",&x);
		A[x]=1;
	}
	
	int ret=0;
	FOR(i,1<<22) if(A[i]) {
		ret++;
		V.push_back(i);
		while(V.size()) {
			x=V.back();
			V.pop_back();
			dfs(x^((1<<22)-1));
		}
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}