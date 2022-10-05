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
	V bit[1<<ME];
	V operator[](int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<ll,20> bt;

template<class V,int NV> class SegTree_1 {
public:
	vector<V> val;
	static V const def=1LL<<60;
	V comp(V l,V r){ return min(l,r);};
	
	SegTree_1(){val=vector<V>(NV*2,1LL<<60);};
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

int N,Q;
ll AS;
set<int> S;
SegTree_1<ll,1<<20> penalty;

void update(int cur) {
	if(cur<=1 || cur>=N) return;
	S.erase(cur);
	penalty.update(cur,1LL<<60);
	if(bt[cur]<bt[cur-1]&&bt[cur]<bt[cur+1]) {
		S.insert(cur);
	}
	else {
		penalty.update(cur,max({0LL,bt[cur-1]-bt[cur],bt[cur+1]-bt[cur]}));
	}
}

ll hoge(int cur,int add) {
	ll ret=0;
	ret-=abs(bt[cur]-bt[cur-1]);
	ret+=abs(bt[cur]+add-bt[cur-1]);
	ret-=abs(bt[cur]-bt[cur+1]);
	ret+=abs(bt[cur]+add-bt[cur+1]);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	int pre=0;
	for(i=1;i<=N;i++) {
		scanf("%d",&x);
		bt.add(i,x-pre);
		if(i>1) AS+=abs(x-pre);
		pre=x;
	}
	for(i=2;i<=N-1;i++) update(i);
	S.insert(N+1);
	S.insert(N+2);
	
	scanf("%d",&Q);
	while(Q--) {
		int T,L,R,X;
		scanf("%d%d%d%d",&T,&L,&R,&X);
		if(T==1) {
			ll ret= AS + max(hoge(L,X),hoge(R,X));
			auto it=S.lower_bound(L);
			if(*it<=R) ret = max(ret, AS + hoge(*it,X));
			ll p=penalty.getval(L,R+1);
			if(p<X) ret=max(ret,AS+X+X-2*p);
			
			cout<<ret<<endl;
		}
		else {
			AS-=abs(bt[L]-bt[L-1]);
			AS-=abs(bt[R]-bt[R+1]);
			bt.add(L,X);
			bt.add(R+1,-X);
			AS+=abs(bt[L]-bt[L-1]);
			AS+=abs(bt[R]-bt[R+1]);
			update(L);
			update(L-1);
			update(R);
			update(R+1);
		}
	}
	
	
}

int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}