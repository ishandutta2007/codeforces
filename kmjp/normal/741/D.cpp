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
int P[505050];
int mask[505050];
char C[505050];
int D[505050];
vector<pair<int,char>> E[505050];
int ret[505050];

int id;
int L[505050],R[505050],ID[505050];


int ma[1<<22];

void dfs(int cur,int pre) {
	L[cur]=id++;
	ID[L[cur]]=cur;
	FORR(r,E[cur]) if(r.first!=pre) {
		mask[r.first] = mask[cur] ^ (1<<r.second);
		D[r.first] = D[cur] + 1;
		dfs(r.first,cur);
	}
	R[cur]=id;
}

void dfs2(int cur,int pre,int keep) {
	int big=-1,i;
	FORR(r,E[cur]) if(r.first!=pre) {
		if(big==-1 || R[r.first]-L[r.first]>R[big]-L[big]) big = r.first;
	}
	FORR(r,E[cur]) if(r.first!=pre && r.first!=big) dfs2(r.first,cur,0);
	if(big>=0) dfs2(big,cur,1);
	FORR(r,E[cur]) if(r.first!=pre && r.first!=big) {
		for(int x=L[r.first];x<R[r.first];x++) {
			ret[cur] = max(ret[cur], ma[mask[ID[x]]]+D[ID[x]]-2*D[cur]);
			FOR(i,22) ret[cur] = max(ret[cur], ma[(1<<i)^mask[ID[x]]]+D[ID[x]]-2*D[cur]);
		}
		for(int x=L[r.first];x<R[r.first];x++) {
			ma[mask[ID[x]]] = max(ma[mask[ID[x]]],D[ID[x]]);
		}
	}
	ma[mask[cur]] = max(ma[mask[cur]], D[cur]);
	ret[cur] = max(ret[cur], ma[mask[cur]]-D[cur]);
	FOR(i,22) ret[cur] = max(ret[cur], ma[(1<<i)^mask[cur]]-D[cur]);
	FORR(r,E[cur]) if(r.first!=pre) ret[cur] = max(ret[cur], ret[r.first]);
	
	if(keep==0) {
		for(int x=L[cur];x<R[cur];x++) ma[mask[ID[x]]] = -1<<30;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>P[i+1]>>C[i+1];
		C[i+1]-='a';
		P[i+1]--;
		E[P[i+1]].push_back({i+1,C[i+1]});
	}
	
	dfs(0,-1);
	FOR(i,1<<22) ma[i]=-1<<30;
	dfs2(0,-1,1);
	
	FOR(i,N) _P("%d%c",ret[i],(i==N-1)?'\n':' ');
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}