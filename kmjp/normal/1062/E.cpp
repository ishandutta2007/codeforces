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

int N,Q;

vector<int> E[200005];
int P[21][200005],D[200005];
int id;
int ID[202020];

int lca(int a,int b) {
	if(a<0) return b;
	if(b<0) return a;
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=17;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=17;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}

void dfs(int cur) {
	ID[cur]=id++;
	ITR(it,E[cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
}

template<class V,int NV> class RMQ {
private:
	V table[NV+1][1<<NV];
	int LG[1<<NV];
	int NV2;
public:
	static V const def=-(1<<30);
	RMQ() {
		int i,x;
		NV2=1<<NV;
		LG[1]=0;
		for(i=2;i<NV2;i++) LG[i]=LG[i/2]+1;
		FOR(i,NV) FOR(x,NV2) table[i][x]=def;
	}
	void set(int x,V v){ table[0][x]=v;}
	void build() {
		int i,j,x,y;
		FOR(i,NV) FOR(x,NV2) {
			if(table[i][x]==def) {
				table[i+1][x]=def;
			}
			else if(x+(1<<i)<NV2 && table[i][x+(1<<i)]!=def) {
				table[i+1][x]=lca(table[i][x],table[i][x+(1<<i)]);
			}
			else {
				table[i+1][x]=table[i][x];
			}
		}
	}
	V query(int L,int R) { //[L,R),
		if(R<=L) return def;
		int WL=LG[R-L];
		return lca(table[WL][L],table[WL][R-(1<<WL)]);
	}
	
};
RMQ<int,18> rmq;

template<class V,int NV> class SegTree_Pair {
public:
	vector<pair<V,int> > val;
	static V const def=-(1<<20);
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
SegTree_Pair<int,1<<18> st[2];


void solve() {
	int i,j,k,l,r,x,y; string s;
	int A,B;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>x;
		E[x-1].push_back(i+1);
	}
	
	dfs(0);
	FOR(i,17) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	FOR(i,N) {
		rmq.set(i,i);
		st[0].update(i,ID[i]);
		st[1].update(i,-ID[i]);
	}
	rmq.build();
	
	
	while(Q--) {
		cin>>A>>B;
		A--;
		x=st[0].getval(A,B).second;
		y=st[1].getval(A,B).second;
		
		int x2=D[lca(rmq.query(A,x),rmq.query(x+1,B))];
		int y2=D[lca(rmq.query(A,y),rmq.query(y+1,B))];
		if(x2>y2) {
			cout<<(x+1)<<" "<<x2<<endl;
		}
		else {
			cout<<(y+1)<<" "<<y2<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}