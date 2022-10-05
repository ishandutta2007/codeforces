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

const ll mo=998244353;

ll modpow(ll a, ll n = mo-2) {
	ll r=1;a%=mo;
	while(n) r=r*((n%2)?a:1)%mo,a=a*a%mo,n>>=1;
	return r;
}


template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		if(l.second==0) return r;
		if(r.second==0) return l;
		V P;
		P.first=(l.first+l.second*r.first)%mo;
		P.second=l.second*r.second%mo;
		return P;
	};
	
	SegTree_1(){val=vector<V>(NV*2,{0LL,0LL});};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0LL,0LL};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v; //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<pair<ll,ll>,1<<18> st;
int N,Q;

ll count(int a,int b) {
	auto p=st.getval(a,b);
	return p.first*modpow(p.second)%mo;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	
	FOR(i,N) {
		cin>>x;
		st.update(i,{1LL,x*modpow(100)%mo});
	}
	set<int> S;
	S.insert(0);
	S.insert(N);
	ll ret=count(0,N);
	
	FOR(i,Q) {
		cin>>x;
		x--;
		if(S.count(x)) {
			auto it=S.find(x);
			int a=*prev(it);
			int b=*next(it);
			ret-=count(a,x);
			ret-=count(x,b);
			S.erase(x);
			ret+=count(a,b);
		}
		else {
			auto it=S.lower_bound(x);
			int b=*it;
			int a=*prev(it);
			ret-=count(a,b);
			S.insert(x);
			ret+=count(a,x);
			ret+=count(x,b);
		}
		ret=(ret%mo+mo)%mo;
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}