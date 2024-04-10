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

int T;
int N;
int A[303030],B[303030];
vector<int> AE[303030],BE[303030];
int id;
int L[303030],R[303030],re[303030];
set<int> alive;
int num;

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
		val[entry]=v; //
		while(entry>1) entry>>=1, val[entry]=comp(val[entry*2],val[entry*2+1]);
	}
};
SegTree_1<int,1<<19> st;

void dfs(int cur) {
	L[cur]=id++;
	re[L[cur]]=cur;
	FORR(e,BE[cur]) dfs(e);
	R[cur]=id;
}
int ma;

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void dfs2(int cur) {
	
	
	bt.add(L[cur],1);
	int sub=bt(R[cur]-1)-bt(L[cur]);
	if(sub==0) num++;
	st.update(L[cur],R[cur]);
	//
	int x=-1,i;
	if(st.getval(0,L[cur])>=R[cur]) {
		x=0;
		for(i=20;i>=0;i--) if(x+(1<<i)<L[cur] && st.getval(x+(1<<i),L[cur])>=R[cur]) x+=1<<i;
		int t=re[x];
		sub=bt(R[t]-1)-bt(L[t]);
		if(sub==1) num--;
	}
	
	ma=max(ma,num);
	
	FORR(e,AE[cur]) dfs2(e);
	
	bt.add(L[cur],-1);
	sub=bt(R[cur]-1)-bt(L[cur]);
	if(sub==0) num--;
	st.update(L[cur],0);
	
	if(x!=-1) {
		int t=re[x];
		sub=bt(R[t]-1)-bt(L[t]);
		if(sub==0) num++;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		FOR(i,N) AE[i].clear(),BE[i].clear();
		
		for(i=1;i<N;i++) {
			scanf("%d",&A[i]);
			A[i]--;
			AE[A[i]].push_back(i);
		}
		for(i=1;i<N;i++) {
			scanf("%d",&B[i]);
			B[i]--;
			BE[B[i]].push_back(i);
		}
		id=0;
		dfs(0);
		
		ma=0;
		dfs2(0);
		
		cout<<ma<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}