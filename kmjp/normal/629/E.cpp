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
vector<int> E[101010];
int P[21][200005],D[200005];

int sub_v[101010];
ll sub_d[101010];
ll par_d[101010];

void dfs(int cur) {
	sub_v[cur]=1;
	ITR(it,E[cur]) if(*it!=P[0][cur]) {
		D[*it]=D[cur]+1;
		P[0][*it]=cur;
		dfs(*it);
		sub_v[cur]+=sub_v[*it];
		sub_d[cur]+=sub_d[*it]+sub_v[*it];
	}
}

void dfs2(int cur,ll p) {
	par_d[cur]=p;
	ll tot=p+sub_d[cur];
	ITR(it,E[cur]) if(*it!=P[0][cur]) {
		ll p2=tot-(sub_d[*it]+sub_v[*it])+(N-sub_v[*it]);
		dfs2(*it,p2);
	}
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	dfs2(0,0);
	while(M--) {
		cin>>x>>y;
		x--,y--;
		if(D[x]>D[y]) swap(x,y);
		int lc=lca(x,y);
		
		ll base=(D[x]-D[lc])+(D[y]-D[lc])+1;
		double xs,ys=sub_d[y]*1.0/sub_v[y];
		if(x==lc) {
			int yp=getpar(y,D[y]-D[x]-1);
			xs=(par_d[x]+sub_d[x]-(sub_d[yp]+sub_v[yp]))*1.0/(N-sub_v[yp]);
		}
		else {
			xs=sub_d[x]*1.0/sub_v[x];
		}
		_P("%.12lf\n",base+xs+ys);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}