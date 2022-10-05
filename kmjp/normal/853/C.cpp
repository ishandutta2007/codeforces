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

int N,Q;
int P[202020];

template<class V,int NV> class SegTree_1 {
public:
	vector<vector<V>> val;
	static V const def=0;
	V comp(V l,V r){ return max(l,r);};
	
	SegTree_1(){val.resize(NV*2);};
	pair<V,V> getval(int x,int y,int a,int b,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return make_pair(0,0);
		if(x<=l && r<=y) {
			return make_pair(
			lower_bound(ALL(val[k]),a+1)-val[k].begin(),
			lower_bound(ALL(val[k]),b+1)-val[k].begin());
		}
		auto A=getval(x,y,a,b,l,(l+r)/2,k*2);
		auto B=getval(x,y,a,b,(l+r)/2,r,k*2+1);
		return make_pair(A.first+B.first,A.second+B.second);
	}
	void set(int entry,V v) {
		val[entry+NV].clear();
		val[entry+NV].push_back(v);
	}
	void build() {
		for(int i=NV-1;i>=1;i--) {
			val[i].clear();
			int a=0,b=0;
			int x=i*2,y=i*2+1;
			while(a<val[x].size() || b<val[y].size()) {
				if(a==val[x].size()) {
					val[i].push_back(val[y][b++]);
				}
				else if(b==val[y].size()) {
					val[i].push_back(val[x][a++]);
				}
				else if(val[x][a]<val[y][b]) {
					val[i].push_back(val[x][a++]);
				}
				else {
					val[i].push_back(val[y][b++]);
				}
			}
		}
	}
};
SegTree_1<int,1<<18> st;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	for(i=1;i<=N;i++) {
		scanf("%d",&P[i]);
		st.set(i,P[i]);
	}
	
	st.build();
	
	while(Q--) {
		int L,R,U,D;
		scanf("%d%d%d%d",&L,&D,&R,&U);
		ll ret=1LL*N*(N-1)/2;
		// up/down
		int up=N-U;
		int down=D-1;
		ret-=(1LL*up*(up-1)+1LL*down*(down-1))/2;
		//left/right
		up=N-R;
		down=L-1;
		ret-=(1LL*up*(up-1)+1LL*down*(down-1))/2;
		//LU
		auto a=st.getval(1,L,U,D-1);
		up=(L-1)-a.first;
		down=a.second;
		ret+=(1LL*up*(up-1)+1LL*down*(down-1))/2;
		a=st.getval(R+1,N+1,U,D-1);
		up=(N-R)-a.first;
		down=a.second;
		ret+=(1LL*up*(up-1)+1LL*down*(down-1))/2;
		cout<<ret<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}