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
ll C[101010];
int U[101010],V[101010];
vector<pair<int,int>> E[101010];
ll R[101010];
int col[101010];
ll P[2];
int tree[101010];
int in[101010];

void dfs(int cur,int c) {
	col[cur]=c;
	P[c]+=C[cur];
	FORR(e,E[cur]) {
		if(col[e.first]==-1) {
			tree[e.second]=1;
			dfs(e.first,c^1);
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>C[i];
	FOR(i,M) {
		cin>>U[i]>>V[i];
		U[i]--,V[i]--;
		E[U[i]].push_back({V[i],i});
		E[V[i]].push_back({U[i],i});
	}
	MINUS(col);
	dfs(0,0);
	
	if(P[0]!=P[1]) {
		FOR(i,M) if(col[U[i]]==col[V[i]]) break;
		if(i==M) return _P("NO\n");
		R[i]=(P[col[U[i]]]-P[col[U[i]]^1])/2;
		C[U[i]]-=R[i];
		C[V[i]]-=R[i];
	}
	
	queue<int> Q;
	FOR(i,N) {
		FORR(e,E[i]) if(tree[e.second]) in[i]++;
		if(in[i]==1) Q.push(i);
	}
	while(Q.size()) {
		
		int cur=Q.front();
		Q.pop();
		
		int id=-1;
		FORR(e,E[cur]) if(tree[e.second]) id=e.second;
		
		if(id>=0) {
			int op=U[id]+V[id]-cur;
			R[id]=C[cur];
			tree[id]=0;
			C[cur]=0;
			C[op]-=R[id];
			in[op]--;
			if(in[op]==1) Q.push(op);
			
		}
		
	}
	
	cout<<"YES"<<endl;
	FOR(i,M) cout<<R[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}