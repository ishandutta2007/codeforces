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

int N;
int X[505050],Y[505050],C[505050];

template<class V,int NV> class SegTree_3 {
public:
	vector<V> val;
	vector<pair<V,int>> ma;
	SegTree_3(){
		int i;
		val.resize(NV*2); ma.resize(NV*2);
		FOR(i,NV) val[i+NV]=0, ma[i+NV]={0,i};
		for(i=NV-1;i>=1;i--) ma[i]=max(ma[2*i],ma[2*i+1]);
	};
	
	pair<V,int> getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return {-1LL<<60,0};
		if(x<=l && r<=y) return ma[k];
		auto a=max(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
		a.first+=val[k];
		return a;
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k].first+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=max(ma[k*2],ma[k*2+1]);
			ma[k].first+=val[k];
		}
	}
};

SegTree_3<ll,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<ll> V;
	V.push_back(0);
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>C[i];
		if(X[i]>Y[i]) swap(X[i],Y[i]);
		V.push_back(X[i]);
		V.push_back(Y[i]);
	}
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	st.update(0,2*N+2,-1LL<<60);
	FOR(i,V.size()) {
		st.update(i,i+1,(1LL<<60)+V[i]);
	}
	
	map<int,vector<int>> ev;
	FOR(i,N) {
		X[i]=lower_bound(ALL(V),X[i])-V.begin();
		Y[i]=lower_bound(ALL(V),Y[i])-V.begin();
		ev[Y[i]].push_back(i);
	}
	ll ma=0;
	ll x1=1LL<<30,x2=1LL<<30;
	FORR(e,ev) {
		auto VV=e.second;
		FORR(c,VV) st.update(0,X[c]+1,C[c]);
		auto ret=st.getval(0,e.first+1);
		ret.first-=V[e.first];
		//cout<<V[e.first]<<" - "<<V[ret.second]<<" "<<ret.first<<endl;
		if(ret.first>ma) {
			ma=ret.first;
			x1=V[ret.second];
			x2=V[e.first];
		}
		//FORR(c,VV) st.update(0,X[c],-C[c]);
		
	}
	cout<<ma<<endl;
	cout<<x1<<" "<<x1<<" "<<x2<<" "<<x2<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}