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

int N,M,P;
pair<int,int> A[202020];
ll BC[1<<20];
int X[202020],Y[202020],Z[202020];

static ll const def=-1LL<<60;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
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
SegTree_3<ll,1<<20> st;
vector<pair<int,int>> ev[1010101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&M,&P);
	
	FOR(i,N) scanf("%d%d",&A[i].first,&A[i].second);
	FOR(i,1<<20) BC[i]=-1LL<<60;
	FOR(i,M) {
		scanf("%d%d",&x,&y);
		BC[x]=max(BC[x],(ll)-y);
	}
	
	for(i=(1<<20)-2;i>=0;i--) BC[i]=max(BC[i],BC[i+1]);
	FOR(i,1<<20) st.update(i,i+1,BC[i]);
	
	FOR(i,P) {
		scanf("%d%d%d",&X[i],&Y[i],&Z[i]);
		ev[X[i]].push_back({Y[i],Z[i]});
	}
	
	ll ma=-1LL<<60;
	sort(A,A+N);
	int pre=0;
	FOR(i,N) {
		while(pre<A[i].first) {
			FORR(e,ev[pre]) {
				st.update(e.first+1,1<<20,e.second);
			}
			pre++;
		}
		ll sc=-A[i].second+st.getval(0,1<<20);
		ma=max(ma,sc);
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}