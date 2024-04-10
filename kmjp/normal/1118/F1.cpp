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
int C[303030];
int B[303030];
vector<int> E[303030];

int dfs(int cur,int pre,int col) {
	int now=0;
	FORR(e,E[cur]) if(e!=pre) now|=dfs(e,cur,col);
	if(C[cur]&(1<<col)) now=1;
	if(now) C[cur] |= 1<<col;
	return now;
}

int dfs2(int cur,int pre) {
	if(C[cur]==2) return 0;
	
	int mi=10101010;
	FORR(e,E[cur]) if(e!=pre) {
		mi=min(mi,dfs2(e,cur));
	}
	if(C[cur]==0) mi++;
	return mi;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	int R[2];
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		if(x) C[i]=1<<(x-1);
		if(x==1) R[0]=i;
		if(x==2) R[1]=i;
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(R[0],-1,0);
	dfs(R[1],-1,1);
	FOR(i,N) if(C[i]==3) return _P("0\n");
	cout<<1+dfs2(R[0],-1)<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}