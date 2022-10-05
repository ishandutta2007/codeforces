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

template<class V,int NV> class RMQ {
private:
	V table[NV+1][1<<NV];
	int LG[1<<NV];
	int NV2;
public:
	static V const def=(1LL<<40);
	V comp(V l,V r){ return min(l,r);};
	RMQ() {
		int i,x;
		NV2=1<<NV;
		LG[1]=0;
		for(i=2;i<NV2;i++) LG[i]=LG[i/2]+1;
		FOR(i,NV) FOR(x,NV2) table[i][x]=def;
	}
	void set(int x,V v){ table[0][x]=v;}
	void build() {
		int i,j,x,y;
		FOR(i,NV) FOR(x,NV2) table[i+1][x]=comp(table[i][x],(x+(1<<i)<NV2)?table[i][x+(1<<i)]:def);
	}
	V query(int L,int R) { //[L,R),
		L=max(0,L), R=min(R,NV2);
		if(R<=L) return def;
		int WL=LG[R-L];
		return comp(table[WL][L],table[WL][R-(1<<WL)]);
	}
	
};

RMQ<ll,18> rmq;

int N;
ll A[201010];
int ret[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll ma=0,mi=1LL<<40;
	vector<pair<ll,int>> V;
	FOR(i,N) {
		cin>>A[i];
		A[i]*=2;
		A[i+N]=A[i];
		V.push_back({-A[i],i});
		rmq.set(i,A[i]);
		rmq.set(i+N,A[i]);
	}
	rmq.build();
	
	sort(ALL(V));
	set<int> did;
	FORR(v,V) {
		int cur=v.second;
		int nex=N;
		
		if(did.size()) {
			nex=*did.lower_bound(cur)-cur;
		}
		
		ll val=rmq.query(cur,cur+nex);
		if(val>=A[cur]/2) {
			if(nex==N) ret[cur]=3*N;
			else ret[cur]=ret[cur+nex]+nex;
		}
		else {
			for(i=18;i>=0;i--) if(nex>(1<<i)) {
				ll val=rmq.query(cur,cur+nex-(1<<i));
				if(val<A[cur]/2) nex-=1<<i;
			}
			ret[cur]=nex-1;
		}
		
		ret[cur+N]=ret[cur];
		did.insert(cur);
		did.insert(cur+N);
	}
	
	FOR(i,N) {
		if(ret[i]>=3*N) ret[i]=-1;
		cout<<ret[i]<<" ";
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}