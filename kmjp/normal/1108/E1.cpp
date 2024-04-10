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

template<class V,int NV> class SegTree_3_ma {
public:
	vector<V> val, ma;
	SegTree_3_ma(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return -1<<30;
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
SegTree_3_ma<int,1<<20> pl,mi;

int N,M;
int A[101010],L[101010],R[101010];
vector<int> add[101010];
vector<int> del[101010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>A[i];
		pl.update(i,i+1,A[i]);
		mi.update(i,i+1,-A[i]);
	}
	FOR(i,M) {
		cin>>L[i]>>R[i];
		L[i]--;
		pl.update(L[i],R[i],-1);
		mi.update(L[i],R[i],1);
		add[L[i]].push_back(R[i]);
		del[R[i]].push_back(L[i]);
	}
	
	int dif=-1,best=0;
	FOR(i,N) {
		FORR(a,add[i]) {
			pl.update(i,a,1);
			mi.update(i,a,-1);
		}
		FORR(a,del[i]) {
			pl.update(a,i,-1);
			mi.update(a,i,1);
		}
		x=pl.getval(0,N)+mi.getval(0,N);
		if(x>dif) dif=x, best=i;
	}
	
	vector<int> V;
	FOR(i,M) if(best<L[i]||R[i]<=best) V.push_back(i+1);
	cout<<dif<<endl;
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}