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

int N,M,Q;
int P[202020],A[202020];
int re[202020];
int nex[202020];
int ne[202020][20];
int tar[202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1<<30; 
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	if(N==1) {
		FOR(i,Q) cout<<1;
		cout<<endl;
		return;
	}
	
	FOR(i,N) {
		cin>>P[i];
		re[P[i]]=i;
	}
	FOR(i,M) {
		cin>>A[i];
		A[i]=re[A[i]];
	}
	FOR(i,N) nex[i]=M;
	
	ne[M][0]=M;
	for(i=M-1;i>=0;i--) {
		ne[i][0]=nex[(A[i]+1)%N];
		nex[A[i]]=i;
		tar[i]=i;
	}
	
	FOR(i,19) {
		FOR(j,M+1) ne[j][i+1]=ne[ne[j][i]][i];
		if((N-1)&(1<<i)) {
			FOR(j,M) tar[j]=ne[tar[j]][i];
		}
	}
	FOR(i,M) {
		st.update(i+1,tar[i]+1);
	}
	
	FOR(i,Q) {
		int L,R;
		cin>>L>>R;
		x=st.getval(L,R+1);
		if(x<=R) cout<<1;
		else cout<<0;
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}