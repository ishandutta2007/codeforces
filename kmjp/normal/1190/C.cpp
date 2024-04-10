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

int N,K;
string S;

template<class V,int NV> class SegTree_max {
public:
	vector<V> val;
	static V const def=-(1<<30);
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_max(){val=vector<V>(NV*2,def);};
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
template<class V,int NV> class SegTree_min {
public:
	vector<V> val;
	static V const def=1<<30;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_min(){val=vector<V>(NV*2,def);};
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

SegTree_max<int,1<<20> sma[2];
SegTree_min<int,1<<20> smi[2];
int C[2][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	FOR(i,N) {
		C[0][i+1]=C[0][i];
		C[1][i+1]=C[1][i];
		C[S[i]-'0'][i+1]++;
		sma[S[i]-'0'].update(i,i);
		smi[S[i]-'0'].update(i,i);
	}
	
	for(i=0;i+K<=N;i++) {
		int L[2],R[2];
		L[0]=C[0][i];
		R[0]=C[0][N]-C[0][i+K];
		L[1]=C[1][i];
		R[1]=C[1][N]-C[1][i+K];
		
		if(L[0]+R[0]==0 || L[1]+R[1]==0) return _P("tokitsukaze\n");
	}
	for(i=0;i+K<=N;i++) {
		int L[2],R[2];
		L[0]=min(smi[0].getval(0,i),smi[0].getval(i+K,N+1));
		L[1]=min(smi[1].getval(0,i),smi[1].getval(i+K,N+1));
		R[0]=max(sma[0].getval(0,i),sma[0].getval(i+K,N+1));
		R[1]=max(sma[1].getval(0,i),sma[1].getval(i+K,N+1));
		
		if(R[0]-L[0]<=K-1 && R[1]-L[1]<=K-1) continue;
		return _P("once again\n");
	}
	
	_P("quailty\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}