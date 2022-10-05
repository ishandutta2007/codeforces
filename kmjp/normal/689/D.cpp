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
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
template<class V,int NV> class SegTree_2 {
public:
	vector<V> val;
	static V const def=1LL<<40;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_2(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

int N;
ll A[202020];
ll B[202020];
SegTree_1<ll,1<<18> st1;
SegTree_2<ll,1<<18> st2;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i], A[i]+=2000000000, st1.update(i,A[i]);
	FOR(i,N) cin>>B[i], B[i]+=2000000000, st2.update(i,B[i]);
	
	ll ret=0;
	FOR(i,N) if(A[i]<=B[i]) {
		if(st1.getval(i,N)<st2.getval(i,N)) continue;
		int L=N;
		int R=i;
		for(j=18;j>=0;j--) {
			if(L-(1<<j)>=i && st1.getval(i,L-(1<<j))>=st2.getval(i,L-(1<<j))) L-=1<<j;
			if(R+(1<<j)<=N && st1.getval(i,R+(1<<j))<=st2.getval(i,R+(1<<j))) R+=1<<j;
		}
		//_P("%d %d %d\n",i,L,R);
		if(L<=R) ret += R-L+1;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}