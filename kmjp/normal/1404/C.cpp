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
int A[303030];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;


static ll const def=-3<<20;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,NV) val[i+NV]=ma[i+NV]=0;
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+max(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<int,1<<19> st;
int X[303030],Y[303030];
vector<int> Xs[303030];
int ret[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	int sum=0;
	FOR(i,N) {
		scanf("%d",&A[i]);
		A[i]--;
		if(A[i]>i){
			A[i]=-1303030;
		}
		else {
			A[i]=i-A[i];
			if(A[i]>sum) {
				A[i]=-1303030;
			}
			else {
				bt.add(i,1);
				st.update(i+1,N,-1);
				sum++;
			}
		}
		st.update(i,i+1,A[i]);
	}
	FOR(i,Q) {
		scanf("%d%d",&X[i],&Y[i]);
		Xs[X[i]].push_back(i);
	}
	
	FOR(i,N) {
		FORR(e,Xs[i]) {
			y=N-1-Y[e];
			ret[e]=bt(y);
		}
		if(bt(i)-bt(i-1)) {
			bt.add(i,-1);
			st.update(i,i+1,-1303030);
			st.update(i+1,N,1);
			while(st.getval(i+1,N)>0) {
				int R=N;
				for(j=20;j>=0;j--) if(R-(1<<j)>=i+1 && st.getval(i+1,R-(1<<j))>0) R-=1<<j;
				R--;
				bt.add(R,-1);
				st.update(R,R+1,-1303030);
				st.update(R+1,N,1);
				
			}
			
		}
	}
	FOR(i,Q) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}