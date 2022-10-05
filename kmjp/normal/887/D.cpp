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

int N,A,B,C,D,S,L;
int T[303030];
int Q[303030];
ll AS[303030];
ll AL[303030];
ll AR[303030];
ll BS[303030];

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1LL<<60;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,def);};
	V getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return def;
		if(x<=l && r<=y) return val[k];
		return comp(getval(x,y,l,(l+r)/2,k*2),getval(x,y,(l+r)/2,r,k*2+1));
	}
	void update(int entry, V v) {
		entry += NV;
		val[entry]=v;
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};

SegTree_1<ll,1<<20> BR;

int ok(int t) {
	if(t>T[N-1]) {
		if(AL[N]<0) return 0;
		return 1;
	}
	
	int st=lower_bound(T,T+N,t)-T;
	int en=lower_bound(T+st,T+N,t+L)-T;
	st++;
	en++;
	
	if(AL[st-1]<0) return 0;
	if(AS[st-1]+(BR.getval(st,en)-BS[st-1])<0) return 0;
	/*
	if(en<=N) {
		if(AS[st-1]+(BS[en-1]-BS[st-1])+(AR[en]-AS[en-1])<0) return 0;
	}
	*/
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d%d%d%d%d",&N,&A,&B,&C,&D,&S,&L);
	AS[0]=BS[0]=S;
	BR.update(0,S);
	vector<int> cand;
	
	cand.push_back(0);
	FOR(i,N) {
		scanf("%d%d",&T[i],&Q[i]);
		if(Q[i]==0) {
			AS[i+1]=AS[i]-B;
			BS[i+1]=BS[i]-D;
		}
		else {
			AS[i+1]=AS[i]+A;
			BS[i+1]=BS[i]+C;
		}
		BR.update(i+1,BS[i+1]);
		cand.push_back(T[i]+1);
		cand.push_back(T[i]-L+1);
	}
	AL[0]=AS[0];
	for(i=1;i<=N;i++) AL[i]=min(AL[i-1],AS[i]);
	AR[N]=AS[N];
	for(i=N-1;i>=0;i--) AR[i]=min(AR[i+1],AS[i]);
	
	sort(ALL(cand));
	cand.erase(unique(ALL(cand)),cand.end());
	
	FORR(c,cand) if(c>=0 && ok(c)) {
		cout<<c<<endl;
		return;
	}
	cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}