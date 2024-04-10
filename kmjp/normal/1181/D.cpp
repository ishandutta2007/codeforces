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
int C[505050];
vector<int> A[505050];
set<pair<ll,int>> S;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
	void set(int e,V v) { add(e,v-val[e]);}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};
BIT<int,20> bt;

int ret[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&M,&Q);
	FOR(i,N) {
		scanf("%d",&x);
		C[x]++;
	}
	for(i=1;i<=M;i++) A[C[i]].push_back(i);
	FOR(i,Q) {
		ll d;
		scanf("%" PRId64 ,&d);
		S.insert({d,i});
	}
	ll did=N;
	int tot=0;
	for(i=1;i<=500001;i++) {
		FORR(v,A[i-1]) bt.add(v,1), tot++;
		if(S.empty()) break;
		while(S.size() && S.begin()->first<=did+tot) {
			auto p=*S.begin();
			S.erase(S.begin());
			ret[p.second]=bt.lower_bound(p.first-did);
		}
		did+=tot;
	}
	while(S.size()) {
		auto p=*S.begin();
		S.erase(S.begin());
		ret[p.second]=(p.first-1-did)%M+1;
	}
	
	FOR(i,Q) _P("%d\n",ret[i]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}