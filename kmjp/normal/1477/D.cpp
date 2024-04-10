#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int T,N,M;

set<int> E[505050],F[505050];
int P[505050],Q[505050];
int vis[505050];
int cv=0;
vector<int> C[505050];

int dfs(int cur) {
	vis[cur]=1;
	FORR(e,F[cur]) if(vis[e]==0) {
		int ret=dfs(e);
		if(ret==0) Q[cur]=Q[e]=cur;
	}
	return Q[cur]>=0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&M);
		FOR(i,N+1) E[i].clear(),C[i].clear(),P[i]=Q[i]=-1,F[i].clear(),vis[i]=0;
		
		FOR(i,M) {
			scanf("%d%d",&x,&y);
			E[x-1].insert(y-1);
			E[y-1].insert(x-1);
		}
		set<int> L;
		FOR(i,N) {
			C[E[i].size()].push_back(i);
			L.insert(i);
		}
		x=N;
		while(x&&C[x-1].size()) {
			y=C[x-1][0];
			P[y]=Q[y]=x;
			vis[y]=1;
			L.erase(y);
			x--;
			FOR(i,x+1) C[i].clear();
			FORR(e,E[y]) {
				E[e].erase(y);
				C[E[e].size()].push_back(e);
			}
		}
		if(L.size()) {
			
			while(L.size()) {
				queue<int> QU;
			
				QU.push(*L.begin());
				L.erase(L.begin());
				while(QU.size()) {
					x=QU.front();
					QU.pop();
					vector<int> del;
					FORR(l,L) {
						if(E[x].count(l)==0) {
							F[x].insert(l);
							F[l].insert(x);
							QU.push(l);
							del.push_back(l);
						}
					}
					FORR(d,del) L.erase(d);
				}
			}
			FOR(i,N) if(vis[i]==0&&F[i].size()) {
				x=dfs(i);
				if(x==0) Q[i]=Q[*F[i].begin()];
			}
			FOR(i,N+1) C[i].clear();
			FOR(i,N) if(P[i]!=Q[i]&&Q[i]!=i) C[Q[i]].push_back(i);
			x=1;
			FOR(i,N) if(C[i].size()) {
				FOR(j,C[i].size()) {
					P[C[i][j]]=x+j;
					Q[C[i][j]]=x+j+1;
				}
				P[i]=x+C[i].size();
				Q[i]=x;
				x+=C[i].size()+1;
			}
		}
		
		
		FOR(i,N) _P("%d ",P[i]);
		_P("\n");
		FOR(i,N) _P("%d ",Q[i]);
		_P("\n");
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}