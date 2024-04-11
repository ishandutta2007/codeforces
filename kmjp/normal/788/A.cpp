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
	static V const def=-1LL<<60;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
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
ll A[101010];
ll B[101010];
ll C[101010];
ll D[101010];
SegTree_1<ll,1<<20> CC,DD;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	N--;
	ll ma=0;
	FOR(i,N) {
		B[i]=abs(A[i+1]-A[i]);
		ma=max(ma,B[i]);
	}
	FOR(i,N) {
		if(i%2==0) {
			C[i+1]=C[i]+B[i];
			D[i+1]=D[i]-B[i];
		}
		else {
			C[i+1]=C[i]-B[i];
			D[i+1]=D[i]+B[i];
		}
		CC.update(i+1,C[i+1]);
		DD.update(i+1,D[i+1]);
	}
	FOR(i,N) {
		ll v;
		if(i%2==0) v=CC.getval(i+1,N+1)-C[i];
		else v=DD.getval(i+1,N+1)-D[i];
		ma=max(ma,v);
	}
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}