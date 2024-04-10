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
string S[1010101];
int A[1010101],B[1010101];
int in[1010101][2];
int val[1010101];
int ret[1010101];

int dfs(int cur) {
	if(S[cur]=="IN") {
		val[cur]=A[cur];
	}
	else if(S[cur]=="NOT") {
		val[cur]=dfs(A[cur])^1;
	}
	else if(S[cur]=="AND") {
		val[cur]=dfs(A[cur]) & dfs(B[cur]);
	}
	else if(S[cur]=="OR") {
		val[cur]=dfs(A[cur]) | dfs(B[cur]);
	}
	else if(S[cur]=="XOR") {
		val[cur]=dfs(A[cur]) ^ dfs(B[cur]);
	}
	return val[cur];
}

void dfs2(int cur,int v0,int v1) {
	if(S[cur]=="IN") {
		if(A[cur]==0) ret[cur]=v1;
		else ret[cur]=v0;
	}
	else if(S[cur]=="NOT") {
		dfs2(A[cur],v1,v0);
	}
	else if(S[cur]=="AND") {
		dfs2(A[cur],v0,(val[B[cur]]==1)?v1:v0);
		dfs2(B[cur],v0,(val[A[cur]]==1)?v1:v0);
	}
	else if(S[cur]=="OR") {
		dfs2(A[cur],(val[B[cur]]==1)?v1:v0,v1);
		dfs2(B[cur],(val[A[cur]]==1)?v1:v0,v1);
	}
	else if(S[cur]=="XOR") {
		dfs2(A[cur],(val[B[cur]])?v1:v0,(val[B[cur]])?v0:v1);
		dfs2(B[cur],(val[A[cur]])?v1:v0,(val[A[cur]])?v0:v1);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<=N;i++) {
		cin>>S[i];
		if(S[i]=="IN" || S[i]=="NOT") {
			cin>>A[i];
		}
		else {
			cin>>A[i]>>B[i];
		}
	}
	
	dfs(1);
	dfs2(1,0,1);
	for(i=1;i<=N;i++) if(S[i]=="IN") cout<<ret[i];
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}