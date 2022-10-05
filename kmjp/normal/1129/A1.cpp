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
		val[entry]=comp(v,val[entry]);
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

int N,M;
vector<int> E[5005];
SegTree_1<ll,1<<20> st,st1;

int tar[5005];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	int ma=0;
	FOR(i,M) {
		cin>>x>>y;
		x--;
		y--;
		if(y<x) y+=N;
		E[x].push_back(y);
		ma=max(ma,(int)E[x].size());
	}
	
	FOR(i,N) {
		sort(ALL(E[i]));
		reverse(ALL(E[i]));
		FOR(j,E[i].size()) {
			st.update(i,N*j+E[i][j]);
			st.update(N+i,N*j+E[i][j]+N);
		}
	}
	FOR(i,N) {
		cout<<(st.getval(i,i+N)-i)<<" ";
	}
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}