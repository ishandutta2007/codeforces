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
int P[1010101];
int L[1010101],R[1010101];

int Lma[1010101],Rma[1010101];
vector<int> delL[1010101],delR[1010101];
vector<int> QL[1010101],QR[1010101];
template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> sum;
BIT<int,20> mu;

ll ret[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	for(i=1;i<=N;i++) {
		scanf("%d",&P[i]);
		Lma[i]=st.getval(P[i],N+1);
		delL[Lma[i]].push_back(i);
		st.update(P[i],i);
		sum.add(i,i-Lma[i]);
	}
	FOR(i,st.val.size()) st.val[i]=0;
	for(i=N;i>=1;i--) {
		Rma[i]=N+1-st.getval(P[i],N+1);
		delR[Rma[i]].push_back(i);
		st.update(P[i],N+1-i);
	}
	
	FOR(i,Q) {
		scanf("%d",&L[i]);
		QL[L[i]].push_back(i);
	}
	FOR(i,Q) {
		scanf("%d",&R[i]);
		QR[R[i]].push_back(i);
	}
	
	FOR(i,N+1) {
		FORR(q,QL[i]) ret[q]+=(sum(R[q])-sum(L[q]-1))-1LL*i*(mu(R[q])-mu(L[q]-1));
		FORR(x,delL[i]) {
			sum.add(x,x+1-(sum(x)-sum(x-1)));
			mu.add(x,1);
		}
	}
	ZERO(mu.bit);
	ZERO(sum.bit);
	for(i=1;i<=N;i++) {
		sum.add(i,Rma[i]-i-1);
	}
	for(i=N+1;i>=1;i--) {
		FORR(q,QR[i]) ret[q]+=(sum(R[q])-sum(L[q]-1))+1LL*i*(mu(R[q])-mu(L[q]-1));
		FORR(x,delR[i]) {
			sum.add(x,-x-(sum(x)-sum(x-1)));
			mu.add(x,1);
		}
	}
	
	FOR(i,Q) cout<<ret[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}