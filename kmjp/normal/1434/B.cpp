#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=-1;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=comp(v,val[entry]); //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<20> st;


int N;
int E[202020];

int L[202020],R[202020];
int did[202020];
vector<int> add[202020];
vector<int> ret;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,2*N) {
		cin>>s;
		if(s=="-") {
			cin>>E[i];
			R[E[i]]=i;
			x=st.getval(E[i]+1,N+1);
			L[E[i]]=x+1;
			st.update(E[i],i);
			add[L[E[i]]].push_back(E[i]);
		}
	}
	
	set<pair<int,int>> S;
	FOR(i,2*N) {
		FORR(e,add[i]) S.insert({R[e],e});
		if(E[i]==0) {
			if(S.empty()) return _P("NO\n");
			auto it=S.begin();
			if(it->first<i) return _P("NO\n");
			ret.push_back(it->second);
			S.erase(S.begin());
		}
	}
	
	cout<<"YES"<<endl;
	FORR(r,ret) cout<<r<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}