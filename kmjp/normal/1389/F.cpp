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

static ll const def=0;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
		FOR(i,NV) val[i+NV]=ma[i+NV]=def;
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

int N;
ll L[202020],R[202020];
int T[202020];
SegTree_3<int,1<<20> S[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<ll> X;
	X.push_back(-1);
	FOR(i,N) {
		cin>>L[i]>>R[i]>>T[i];
		L[i]=2*L[i];
		R[i]=R[i]*2+1;
		T[i]--;
		X.push_back(L[i]);
		X.push_back(R[i]);
	}
	sort(ALL(X));
	X.erase(unique(ALL(X)),X.end());
	vector<pair<int,int>> cand;
	FOR(i,N) {
		L[i]=lower_bound(ALL(X),L[i])-X.begin();
		R[i]=lower_bound(ALL(X),R[i])-X.begin();
		cand.push_back({R[i],i});
	}
	
	sort(ALL(cand));
	int ma=0;
	FORR(c,cand) {
		x=c.second;
		S[T[x]].update(0,L[x],1);
		y=S[T[x]].getval(0,R[x]);
		ma=max(ma,y);
		
		r=S[T[x]^1].getval(R[x],R[x]+1);
		if(y>r) S[T[x]^1].update(R[x],R[x]+1,y-r);
		
	}
	cout<<ma<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}