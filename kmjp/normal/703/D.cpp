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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME],val[1<<ME];
	V total(int e) {V s=0;e++;while(e) s^=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { val[e++]+=v; while(e<=1<<ME) bit[e-1]^=v,e+=e&-e;}
	int lower_bound(V val) {
		V tv=0; int i,ent=0;
		for(i=ME-1;i>=0;i--) if(tv+bit[ent+(1<<i)-1]<val) tv+=bit[ent+(1<<i)-1],ent+=(1<<i);
		return ent;
	}
};

int N,M;
int A[1010101],X[1010101];
int L[1010101],R[1010101],ret[1010101];
vector<int> RR[1010101];
map<int,int> pre;
BIT<int,21> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) scanf("%d",&A[i+1]);
	
	scanf("%d",&M);
	FOR(i,M) {
		scanf("%d%d",&L[i],&R[i]);
		RR[R[i]].push_back(i);
	}
	
	int T=0;
	for(i=1;i<=N;i++) {
		
		if(pre.count(A[i])) {
			bt.add(1,A[i]);
			bt.add(pre[A[i]]+1,A[i]);
		}
		pre[A[i]]=i;
		FORR(r,RR[i]) ret[r]=bt.total(L[r]);
	}
	
	FOR(i,M) _P("%d\n",ret[i]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}