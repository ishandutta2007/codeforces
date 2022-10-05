#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	V comp(V l,V r){
		int a=max(get<0>(l),get<2>(l)+get<0>(r));
		int b=max(get<1>(r),get<2>(r)+get<1>(l));
		int c=get<2>(l)+get<2>(r);
		return {a,b,c};
	};
	
	SegTree_1(){val=vector<V>(NV*2,{0,0,0});};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return {0,0,0};
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, int v) {
		entry += NV;
		val[entry]={max(0,v),max(0,v),v};
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<tuple<int,int,int>,1<<18> st;

int N;
int A[202020];
vector<int> ev[202020];
int ret[202020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i];
		A[i]--;
		ev[A[i]].push_back(i);
		st.update(i,1);
	}
	FOR(i,N) {
		FORR(a,ev[i]) chmax(ret[a],(get<1>(st.getval(0,a))+get<0>(st.getval(a+1,N))+1)/2);
		FORR(a,ev[i]) st.update(a,-1);
	}
	FOR(i,N) st.update(i,1);
	for(i=N-1;i>=0;i--) {
		FORR(a,ev[i]) chmax(ret[a],(get<1>(st.getval(0,a))+get<0>(st.getval(a+1,N))+0)/2);
		FORR(a,ev[i]) st.update(a,-1);
	}
	FOR(i,N) cout<<ret[i]<<" ";
	cout<<endl;
	
		
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}