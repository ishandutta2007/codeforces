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

int N,K;
string S;
int C[303030];
vector<int> V[303030];
vector<int> cand[303030];

template<class V,int NV> class SegTree_MulAdd {
public:
	vector<V> sum,mul,add; // sum stores val after muladd
	SegTree_MulAdd(){sum.resize(NV*2,0); mul.resize(NV*2,1); add.resize(NV*2,0);};

	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 0;
		if(x<=l && r<=y) return sum[k];
		x=max(x,l);
		y=min(y,r);
		V ret=getval(x,y,l,(l+r)/2,k*2)+getval(x,y,(l+r)/2,r,k*2+1);
		return ret*mul[k]+add[k]*(y-x);
	}
	void propagate(int k,int s) {
		mul[k*2]*=mul[k];
		add[k*2]*=mul[k];
		sum[k*2]*=mul[k];
		add[k*2]+=add[k];
		sum[k*2]+=add[k]*s/2;
		mul[k*2+1]*=mul[k];
		add[k*2+1]*=mul[k];
		sum[k*2+1]*=mul[k];
		add[k*2+1]+=add[k];
		sum[k*2+1]+=add[k]*s/2;
		
		mul[k]=1;
		add[k]=0;
	}

	void domul(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			mul[k]*=v;
			add[k]*=v;
			sum[k]*=v;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			domul(x,y,v,l,(l+r)/2,k*2);
			domul(x,y,v,(l+r)/2,r,k*2+1);
			sum[k]=sum[k*2]+sum[k*2+1];
		}
	}
	void doadd(int x,int y,V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			add[k]+=v;
			sum[k]+=(r-l)*v;
		}
		else if(l < y && x < r) {
			propagate(k,r-l);
			doadd(x,y,v/mul[k],l,(l+r)/2,k*2);
			doadd(x,y,v/mul[k],(l+r)/2,r,k*2+1);
			sum[k]=sum[k*2]+sum[k*2+1];
		}
	}
};

SegTree_MulAdd<int, 1<<20> st,ng;



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
UF<606060> uf;
int VN[606060];
vector<int> E[606060];

int id;
int L[606060],R[606060];
int cnt[606060];
int vis[606060];

void dfs(int cur) {
	vis[cur]=1;
	L[cur]=id++;
	FORR(e,E[cur]) dfs(e);
	R[cur]=id;
}

int num() {
	int D=st.getval(0,N+K);
	return (K+D)/2;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	FORR(c,S) c-='0';
	FOR(i,K) {
		cin>>C[i];
		FOR(j,C[i]) {
			cin>>x;
			V[i].push_back(x-1);
			cand[x-1].push_back(i);
		}
	}
	FOR(i,N+K) VN[i]=i;
	
	int ret=0;
	FOR(i,N) {
		FORR(v,cand[i]) {
			if(uf[K+i]!=uf[v]) {
				E[K+i].push_back(VN[uf[v]]);
				uf(v,K+i);
				VN[uf[v]]=K+i;
			}
		}
	}
	
	for(i=N+K-1;i>=0;i--) if(vis[i]==0) dfs(i);
	FOR(i,K) st.doadd(L[i],R[i],-1);
	
	FOR(i,N) {
		int cur=S[i];
		FORR(c,cand[i]) {
			x=st.getval(L[c],R[c]);
			if(x==1) cur^=1;
		}
		
		if(cur==0) {
			if(E[K+i].size()==1) {
				assert(cand[i].size()==1);
				st.domul(L[K+i],R[K+i],-1);
			}
			else {
				int mi=1<<30;
				int id=0;
				
				FOR(j,2) {
					int tar=E[K+i][j];
					if(ng.getval(L[tar],R[tar])) continue;
					st.domul(L[tar],R[tar],-1);
					x=num();
					if(x<mi) mi=x, id=j;
					st.domul(L[tar],R[tar],-1);
				}
				int tar=E[K+i][id];
				st.domul(L[tar],R[tar],-1);
				
			}
		}
		cout<<num()<<endl;
		if(cand[i].size()==1) ng.doadd(L[cand[i][0]],R[cand[i][0]],1);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}