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
int A[505050];
ll mo=1000000007;
vector<pair<int,int>> V;

template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) (bit[0][entry-1]+=val0)%=mo, (bit[1][entry-1] += val1)%=mo, entry += entry & -entry;
	}
	V total(int entry) {
		if(entry<0) return 0;
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) (v0+=bit[0][entry-1])%=mo, (v1+=bit[1][entry-1])%=mo, entry -= entry & -entry;
		return (e*v0+v1)%mo;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val%mo,mo-val*(L-1)%mo);
		update(R+1,mo-val%mo,val*R%mo);
	}
};
BIT_r<ll,20> lef,ri;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> did;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d",&A[i]);
		V.push_back({A[i],i});
	}
	sort(ALL(V));
	ll ret=0;
	FORR(v,V) {
		x=v.second;
		int num=N-x;
		ll mor=did(x);
		ri.add(x,N-1,1);
		ret+=A[x]*(ri.total(N-1)-ri.total(x-1)-mor*num%mo)%mo*(x+1)%mo;
		mor=did(N)-did(x);
		ret+=A[x]*(lef.total(x)-mor*(x+1)%mo)%mo*num%mo;
		lef.add(0,x,1);
		did.add(x,1);
	}
	cout<<(ret%mo+mo)%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}