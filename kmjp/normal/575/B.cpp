#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,K;
ll fact2[1010100];
ll mo=1000000007;
ll ret;

vector<int> E[101010];
int P[21][100005],D[100005];
int up[101010],down[101010];
map<pair<int,int>,int> mp;

void dfs(int cur) {
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
}
void dfs2(int cur,int pre) {
	ITR(it,E[cur]) if(*it!=pre) {
		dfs2(*it,cur);
		up[cur]+=up[*it];
		down[cur]+=down[*it];
	}
	if(mp[{cur,pre}]) ret += fact2[up[cur]]+mo-1;
	if(mp[{pre,cur}]) ret += fact2[down[cur]]+mo-1;
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
	
	scanf("%d",&N);
	FOR(i,N-1) {
		scanf("%d%d%d",&x,&y,&r);
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
		mp[{x-1,y-1}]=0;
		mp[{y-1,x-1}]=r;
	}
	
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	fact2[0]=1;
	FOR(i,1000005) fact2[i+1]=fact2[i]*2%mo;
	
	scanf("%d",&K);
	int cur=0,tar;
	FOR(i,K) {
		scanf("%d",&tar);
		tar--;
		int lc = lca(cur,tar);
		up[cur]++,up[lc]--;
		down[tar]++,down[lc]--;
		cur=tar;
	}
	dfs2(0,-1);
	
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	//if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}