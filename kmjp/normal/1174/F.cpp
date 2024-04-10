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
vector<int> E[202020];
int D[202020];
int V[202020];
int G[202020];
int C[202020];
int TX;

int query(char C,int X) {
	cout<<C<<" "<<X<<endl;
	cin>>X;
	return X;
	
}

void dfs(int cur,int pre,int d) {
	D[cur]=d;
	G[cur]=cur;
	V[cur]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur,d+1);
		V[cur]+=V[e];
		if(V[C[cur]]<V[e]) {
			C[cur]=e;
			G[cur]=G[e];
		}
	}
}

int dfs2(int cur) {
	int td=query('d',G[cur]);
	int dis=(TX-D[cur]+D[G[cur]]-D[cur]-td)/2;
	while(dis--) cur=C[cur];
	
	if(D[cur]==TX) return cur;
	return dfs2(query('s',cur));
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	dfs(1,1,0);
	TX=query('d',1);
	x=dfs2(1);
	cout<<"! "<<x<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}