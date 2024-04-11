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

const int ME=300005;
vector<int> LL[ME];
int L[ME],R[ME],eid;
int ST[ME];

int N,Q,K;
vector<int> E[200005];
int P[21][200005],D[200005];

void dfs(int cur) {
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
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

void EulerTour(int cur,int pre=-1) {
	int i;
	FOR(i,E[cur].size()) if(E[cur][i]==pre) {
		E[cur].erase(E[cur].begin()+i);
		break;
	}
	L[cur]=eid++;
	ITR(it,E[cur]) {
		EulerTour(*it,cur);
		LL[cur].push_back(L[*it]);
	}
	R[cur]=eid;
}

int hoge(vector<int>& V,int st) {
	
	int i,N;
	N=V.size();
	
	vector<pair<int,int>> VV;
	FORR(r,V) VV.push_back({L[r],r});
	sort(VV.begin(),VV.end());
	FOR(i,N) V[i]=VV[i].second;
	
	set<pair<int,int>> Q;
	FOR(i,N-1) Q.insert({-D[lca(V[i],V[i+1])],i});

	vector<pair<int,int>> nex;
	FOR(i,N) nex.push_back({i-1,i+1});
	nex[0].first=0;
	nex[N-1].second=N-1;
	
	int cost=0;
	while(Q.size()) {
		auto r=*Q.begin();
		Q.erase(Q.begin());
		
		int x=r.second;
		int y=nex[x].second;
		
		if(x!=nex[x].first) Q.erase({-D[lca(V[x],V[nex[x].first])],nex[x].first});
		if(y!=nex[y].second) Q.erase({-D[lca(V[y],V[nex[y].second])],y});
		
		int lc=lca(V[x],V[y]);
		if(abs(ST[lc])<st) ST[lc]=0;
		if(ST[V[x]]==st && ST[V[y]]==st && P[0][V[y]]==V[x]) return -1;
		if(ST[V[x]]>=st && ST[V[y]]>=st) cost++;
		
		if(ST[lc]==0 || ST[lc]%2) {
			if(ST[V[x]]>0 && ST[V[y]]>0) ST[lc]=-st;
			else if(ST[V[x]]<0 && ST[V[y]]<0) ST[lc]=-st-1;
			else ST[lc]=st+1;
		}
		
		V[x]=lc;
		if(x!=nex[x].first) Q.insert({-D[lca(V[x],V[nex[x].first])],nex[x].first});
		if(y!=nex[y].second) {
			nex[nex[y].second].first=x;
			nex[x].second=nex[y].second;
			Q.insert({-D[lca(V[x],V[nex[y].second])],x});
		}
		else nex[x].second=x;
	}
	
	return cost;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	int go=0;
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		if(i==0 && x==2) go=1;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	EulerTour(0);
	
	cin>>Q;
	int st;
	FOR(st,Q) {
		cin>>K;
		vector<int> V;
		FOR(i,K) cin>>x, x--, V.push_back(x), ST[x]=(st+1)*2;
		
		cout<<hoge(V,(st+1)*2)<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}