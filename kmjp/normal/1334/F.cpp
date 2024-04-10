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

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return 1LL<<60;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
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
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<ll,1<<20> st;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,21> bt;

int N;
int A[505050],P[505050];
int M;
int B[505050];
vector<int> ev[505050];

ll ret[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d",&A[i+1]);
		ev[A[i+1]].push_back(i+1);
	}
	A[N+1]=N+1;
	ev[N+1].push_back(N+1);
	ev[0].push_back(0);
	FOR(i,N) scanf("%d",&P[i+1]);
	scanf("%d",&M);
	FOR(i,M) {
		scanf("%d",&x);
		B[x]=1;
	}
	B[0]=B[N+1]=1;
	N+=2;
	FOR(i,N) ret[i]=1LL<<60;
	
	st.update(1,N,1LL<<60);
	for(i=1;i<N;i++) {
		st.update(0,i,P[i]);
		bt.add(i,P[i]);
	}
	int pre=0;
	for(i=1;i<=N-1;i++) {
		if(B[i]==1) {
			FORR(e,ev[i]) {
				ret[e]=st.getval(0,e)-(bt(1<<20)-bt(e-1));
			}
			
			
			FORR(e,ev[pre]) st.update(e,e+1,1LL<<60);
			FORR(e,ev[i]) st.update(e,e+1,ret[e]-(1LL<<60));
			pre++;
			while(pre<=i) {
				FORR(e,ev[pre]) if(P[e]>0) {
					st.update(0,e,-P[e]);
					bt.add(e,-P[e]);
				}
				pre++;
			}
			pre--;
		}
	}
	if(ret[N-1]>=1LL<<59) {
		cout<<"NO"<<endl;
	}
	else {
		cout<<"YES"<<endl;
		cout<<ret[N-1]<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}