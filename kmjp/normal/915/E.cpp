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
int L[303030],R[303030],K[303030];
vector<int> C;

static ll const def=0;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> base, tot;
	SegTree_3(){
		int i;
		base.resize(NV*2,0); tot.resize(NV*2,0);
	};
	
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			if(v==0) tot[k]=0;
			else tot[k]=base[k];
		}
		else if(l < y && x < r) {
			if(tot[k]==0) {
				tot[2*k]=tot[2*k+1]=0;
			}
			else if(tot[k]==base[k]) {
				tot[2*k]=base[2*k];
				tot[2*k+1]=base[2*k+1];
			}
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			tot[k]=tot[2*k]+tot[2*k+1];
		}
	}
};
SegTree_3<int,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	Q++;
	
	C.push_back(1);
	C.push_back(N+1);
	FOR(i,Q) {
		if(i==0) {
			L[0]=1,R[0]=N,K[0]=2;
		}
		else {
			scanf("%d%d%d",&L[i],&R[i],&K[i]);
		}
		R[i]++;
		C.push_back(L[i]);
		C.push_back(R[i]);
		K[i]--;
	}
	sort(ALL(C));
	C.erase(unique(ALL(C)),C.end());
	
	FOR(i,C.size()-1) st.base[i+(1<<20)]=C[i+1]-C[i];
	for(i=(1<<20)-1;i>=1;i--) st.base[i]=st.base[2*i]+st.base[2*i+1];
	
	
	FOR(i,Q) {
		x=lower_bound(ALL(C),L[i])-C.begin();
		y=lower_bound(ALL(C),R[i])-C.begin();
		st.update(x,y,K[i]);
		if(i) _P("%d\n",st.tot[1]);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}