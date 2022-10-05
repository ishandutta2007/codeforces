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
int P[505050],W[505050];
vector<pair<int,int>> E[505050];
ll D[505050];

vector<int> cand;
int L[505050],R[505050];
int QL[505050],QR[505050];
vector<int> QS[505050];
ll ret[505050];

static ll const def=1LL<<60;
template<class V,int NV> class SegTree_3 {
public:
	vector<V> val, ma;
	SegTree_3(){
		int i;
		val.resize(NV*2,0); ma.resize(NV*2,0);
	};
	
	V getval(int x,int y,int l=0,int r=NV,int k=1) {
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return ma[k];
		return val[k]+min(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) {
			val[k]+=v;
			ma[k]+=v;
		}
		else if(l < y && x < r) {
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
			ma[k]=val[k]+min(ma[k*2],ma[k*2+1]);
		}
	}
};
SegTree_3<ll,1<<20> st;

void dfs(int cur, ll dep) {
	D[cur]=dep;
	L[cur]=cand.size();
	FORR(e,E[cur]) dfs(e.first,dep+e.second);
	if(E[cur].empty()) {
		cand.push_back(cur);
	}
	R[cur]=cand.size();
}

void dfs2(int cur) {
	
	FORR(q,QS[cur]) {
		int CL=lower_bound(ALL(cand),QL[q])-cand.begin();
		int CR=lower_bound(ALL(cand),QR[q])-cand.begin();
		ret[q]=st.getval(CL,CR);
	}
	
	FORR(e,E[cur]) {
		st.update(0,cand.size(),e.second);
		st.update(L[e.first],R[e.first],-2*e.second);
		dfs2(e.first);
		st.update(0,cand.size(),-e.second);
		st.update(L[e.first],R[e.first],+2*e.second);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(i,N-1) {
		scanf("%d%d",&P[i+2],&W[i+2]);
		E[P[i+2]].push_back({i+2,W[i+2]});
	}
	dfs(1,0);
	FOR(i,Q) {
		scanf("%d%d%d",&x,&QL[i],&QR[i]);
		QR[i]++;
		QS[x].push_back(i);
	}
	FOR(i,cand.size()) st.update(i,i+1,D[cand[i]]);
	dfs2(1);
	FOR(i,Q) cout<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}