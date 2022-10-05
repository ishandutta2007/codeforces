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

int N,root,M;
int A[101010];
int X,K;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<int,1<<18> dst[21];

int id=1;
int D[101010];
int L[101010];
int R[101010];
int P[20][101010];

int dmi[20][101010];
int ID[101010];
int rev[101010];
vector<pair<int,int>> V[201010];
vector<int> E[101010];

void dfs(int cur,int pre,int d) {
	P[0][cur]=pre;
	if(pre==-1) P[0][cur]=cur;
	D[cur]=d;
	rev[id]=cur;
	L[cur]=id;
	V[d].push_back({id,0});
	id++;
	
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
	
	R[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&root);
	root--;
	FOR(i,N) {
		scanf("%d",&A[i]);
		FOR(j,20) dmi[j][i]=A[i];
	}
	FOR(i,N-1) {
		scanf("%d%d",&x,&y);
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(root,-1,0);
	id=1;
	FOR(i,N+1) {
		FORR(v,V[i]) ID[rev[v.first]]=v.second=id++;
	}
	FOR(j,N) {
		dmi[0][P[0][j]]=min(dmi[0][P[0][j]],A[j]);
	}
	FOR(i,19) {
		FOR(j,N) {
			P[i+1][j]=P[i][P[i][j]];
			dmi[i+1][j]=min(dmi[i+1][j],dmi[i][j]);
			dmi[i+1][P[i][j]]=min(dmi[i+1][P[i][j]],dmi[i][j]);
		}
		FOR(j,N) dst[i].update(ID[j],dmi[i][j]);
	}
	
	
	int ret=0;
	scanf("%d",&M);
	while(M--) {
		scanf("%d%d",&X,&K);
		X=(X+ret)%N;
		K=(K+ret)%N;
		
		ret=A[X];
		int TL=L[X],TR=R[X];
		int dep=D[X];
		for(j=18;j>=0;j--) if(K&(1<<j)) {
			auto it=lower_bound(ALL(V[dep]),make_pair(L[X],0));
			auto it2=lower_bound(ALL(V[dep]),make_pair(R[X],0));
			if(it!=it2) {
				it2--;
				x=it->second;
				y=it2->second+1;
				ret=min(ret,dst[j].getval(x,y));
			}
			dep+=1<<j;
		}
		_P("%d\n",ret);
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}