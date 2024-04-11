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
int P[20][505050],D[505050];
ll ret[505050];
vector<int> E[505050];

vector<int> ev[505050];

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void dfs(int cur,int dep) {
	D[cur]=dep;
	ev[D[cur]].push_back(cur);
	FORR(e,E[cur]) dfs(e,dep+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	
	int root=-1;
	FOR(i,N) {
		scanf("%d",&P[0][i+1]);
		if(P[0][i+1]==0) root=i+1, P[0][i+1]=root;
		else E[P[0][i+1]].push_back(i+1);
	}
	
	dfs(root,0);
	FOR(i,19) FOR(x,N) P[i+1][x+1]=P[i][P[i][x+1]];
	
	for(i=1;i<=N;i++) if(ev[i].size()) {
		FORR(e,ev[i]) ret[e]=ret[P[0][e]]+D[e];
		FOR(j,2) {
			vector<vector<int>> V;
			ll sum=0;
			FOR(x,ev[i].size()) {
				int e=ev[i][x];
				if(x==0) {
					V.push_back({e,-1,0});
				}
				else {
					while(1) {
						int cand=V.back()[0];
						int lc=lca(cand,e);
						if(V.back()[1]<D[lc]) {
							V.push_back({e,D[lc],x});
							break;
						}
						sum-=1LL*(V[V.size()-1][2]-V[V.size()-2][2])*(V[V.size()-1][1]+1);
						V.pop_back();
					}
					sum+=1LL*(V[V.size()-1][2]-V[V.size()-2][2])*(V[V.size()-1][1]+1);
					ret[e]+=sum;
				}
				
			}
			reverse(ALL(ev[i]));
		}
	}
	
	FOR(i,N) printf("%" PRIu64 "%c", ret[i+1],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}