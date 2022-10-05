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

template<class V,int NV> class SegTree_ma {
public:
	vector<V> val;
	static V const def=-(1<<30);
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_ma(){val=vector<V>(NV*2,def);};
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
template<class V,int NV> class SegTree_mi {
public:
	vector<V> val;
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_mi(){val=vector<V>(NV*2,def);};
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
SegTree_ma<int,1<<18> sma[32];
SegTree_mi<int,1<<18> smi[32];
int N,K,Q;
int A[202020][5];

void update(int i) {
	int j,mask;
	FOR(j,K) scanf("%d",&A[i][j]);
	FOR(mask,1<<K) {
		int sum=0;
		FOR(j,K) {
			if(mask&(1<<j)) sum+=A[i][j];
			else sum-=A[i][j];
		}
		sma[mask].update(i,sum);
		smi[mask].update(i,sum);
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	int mask;
	scanf("%d%d",&N,&K);
	FOR(i,N) update(i);

	scanf("%d",&Q);
	while(Q--) {
		scanf("%d",&i);
		if(i==1) {
			scanf("%d",&i);
			update(i-1);
		}
		else {
			int L,R;
			scanf("%d%d",&L,&R);
			L--;
			int ma=0;
			FOR(mask,1<<K) ma=max(ma,sma[mask].getval(L,R)-smi[mask].getval(L,R));
			_P("%d\n",ma);
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}