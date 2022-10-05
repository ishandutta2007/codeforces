#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M,Q;
int P[202020];
int U[303030],V[303030],T[303030];
int A[505050],B[505050];
int rep[1010101],rt[1010101];

vector<int> VE[1010101];
int par[1010101][20];
int id;
int Lid[1010101],Rid[1010101];

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<1010101> uf;

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=0;
	pair<V,int> comp(pair<V,int> l,pair<V,int> r){ return max(l,r);}
	SegTree_Pair(){
		val.resize(NV*2);
		int i;
		FOR(i,NV) val[i+NV]=make_pair(def,i);
		for(i=NV-1;i>=1;i--) val[i]=comp(val[2*i],val[2*i+1]);
	};
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return make_pair(def,NV);
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=make_pair(v,entry-NV);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_Pair<int,1<<20> st;

void dfs(int cur) {
	Lid[cur]=id++;
	FORR(e,VE[cur]) dfs(e);
	Rid[cur]=id;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&M,&Q);
	MINUS(par);
	FOR(i,N) {
		scanf("%d",&P[i]);
		rep[i]=i;
		rt[i]=1000000;
	}
	FOR(i,M) {
		scanf("%d%d",&x,&y);
		U[i]=x-1;
		V[i]=y-1;
		T[i]=500000+i;
	}
	FOR(i,Q) {
		scanf("%d%d",&A[i],&B[i]);
		B[i]--;
		if(A[i]==2) T[B[i]]=i;
	}
	int nex=N;
	vector<pair<int,int>> E;
	FOR(i,M) E.push_back({-T[i],i});
	sort(ALL(E));
	FORR(e,E) {
		x=uf[U[e.second]];
		y=uf[V[e.second]];
		if(x!=y) {
			VE[nex].push_back(rep[x]);
			VE[nex].push_back(rep[y]);
			par[rep[x]][0]=nex;
			par[rep[y]][0]=nex;
			rt[nex]=-e.first;
			rep[x]=rep[y]=nex++;
			uf(x,y);
		}
	}
	
	
	FOR(i,nex) {
		if(par[i][0]==-1) {
			par[i][0]=nex;
			VE[nex].push_back(i);
		}
	}
	par[nex][0]=nex;
	rt[nex]=-1;
	nex++;
	FOR(j,19) {
		FOR(i,nex) {
			par[i][j+1]=par[par[i][j]][j];
		}
	}
	
	dfs(nex-1);
	FOR(i,N) st.update(Lid[i],P[i]);
	FOR(i,Q) {
		if(A[i]==1) {
			int cur=B[i];
			for(j=19;j>=0;j--) if(rt[par[cur][j]]>=i) cur=par[cur][j];
			auto a=st.getval(Lid[cur],Rid[cur]);
			//cout<<"!"<<i<<" "<<B[i]<<" "<<cur<<" "<<Lid[cur]<<" "<<Rid[cur]<<"     "<<a.first<<":"<<a.second<<endl;
			_P("%d\n",a.first);
			st.update(a.second,0);
			
		}
	}
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}