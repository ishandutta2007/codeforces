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


int N;
vector<int> E[303030];
int M;
int P[21][300005],D[300005];
vector<int> VD[302020];
ll up[302020];
map<int,int> down[302020];
map<int,int> path[302020];
vector<pair<int,int>> V[302020];
ll po[302020];

void dfs(int cur) {
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
	VD[D[cur]].push_back(cur);
}
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	cin>>M;
	FOR(i,M) {
		cin>>x>>y;
		x--,y--;
		int lc=lca(x,y);
		if(x==y) {
			po[x]++;
		}
		else if(lc!=x&&lc!=y) {
			up[x]++;
			up[y]++;
			int x2=getpar(x,D[x]-D[lc]-1);
			int y2=getpar(y,D[y]-D[lc]-1);
			V[lc].push_back({x2,y2});
			path[lc][x2]--;
			path[lc][y2]--;
		}
		else {
			if(D[x]<D[y]) swap(x,y);
			up[x]++;
			int x2=getpar(x,D[x]-D[y]-1);
			down[y][x2]++;
			path[y][x2]--;
		}
	}
	ll ret=0;
	for(i=N-1;i>=0;i--) FORR(v,VD[i]) {
		int par=P[0][v];
		if(i) {
			FORR(p,path[v]) path[par][v]+=p.second;
			path[par][v]+=up[v];
		}
		// po
		ret+=1LL*po[v]*(po[v]-1)/2;
		ret+=1LL*po[v]*up[v];
		FORR(p,path[v]) ret+=po[v]*p.second;
		FORR(p,down[v]) ret+=po[v]*p.second;
		ret+=po[v]*V[v].size();
		// up
		FORR(p,down[v]) ret+=up[v]*p.second;
		ret+=up[v]*V[v].size();
		// down*down
		ll ds=0;
		FORR(d,down[v]) {
			ret+=ds*d.second;
			ds+=d.second;
		}
		// down*path
		ll ps=0;
		FORR(p,path[v]) ps+=p.second;
		FORR(d,down[v]) ret+=1LL*d.second*(ps-path[v][d.first]);
		
		// down*V
		// path*V
		FORR2(a,b,V[v]) {
			ret+=ds-down[v][a]-down[v][b];
			ret+=ps-path[v][a]-path[v][b];
		}
		// V*V
		map<int,int> NG;
		map<pair<int,int>,int> NG2;
		int num=0;
		FORR2(a,b,V[v]) {
			ret+=num-NG[a]-NG[b]+NG2[{min(a,b),max(a,b)}];
			num++;
			NG[a]++;
			NG[b]++;
			NG2[{min(a,b),max(a,b)}]++;
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