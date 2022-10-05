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

template<class V,int NV> class SegTree_2 {
public:
	V nolink;
	vector<V> val;
	SegTree_2(){val.resize(NV*2); clear(); nolink=-1<<30;};
	void clear() { for(int i=0;i<NV*2;i++) val[i]=-1<<20; }
	
	V getval(int k) {
		int e=1;
		while(val[e]==nolink) e=e*2+(((k*2)&NV)>0), k*=2;
		return val[e];
	}
	
	void update(int x,int y, V v,int l=0,int r=NV,int k=1) {
		if(l>=r) return;
		if(x<=l && r<=y) val[k]=max(val[k],v);
		else if(l < y && x < r) {
			if(val[k]!=nolink) val[k*2]=val[k*2+1]=val[k], val[k]=nolink;
			update(x,y,v,l,(l+r)/2,k*2);
			update(x,y,v,(l+r)/2,r,k*2+1);
		}
	}
};
SegTree_2<int,1<<21> st;

int N;
int E[26][1010101];
int P[1010101];
char C[1010101];
int L[1010101],R[1010101],isS[1010101];
int id,K;
int T[1010101];
int A[1010101];

void dfs(int cur) {
	L[cur]=id;
	if(isS[cur]) id++;
	int i;
	FOR(i,26) if(E[i][cur]>=0) dfs(E[i][cur]);
	R[cur]=id;
}

void dfs2(int cur) {
	if(cur) {
		T[cur]=T[P[cur]]+1;
		if(isS[cur]) {
			T[cur]=min(T[cur],L[cur]-st.getval(L[cur]));
		}
		if(L[cur]<R[cur]) st.update(L[cur],R[cur],L[cur]-T[cur]-1);
	}
	else {
		st.update(L[cur],R[cur],0);
	}
	//cout<<cur<<" "<<T[cur]<<" "<<isS[cur]<<" "<<L[cur]<<" "<<st.getval(L[cur])<<endl;
	int i;
	FOR(i,26) if(E[i][cur]>=0) dfs2(E[i][cur]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(E);
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d %c",&P[i+1],&C[i+1]);
		E[C[i+1]-'a'][P[i+1]]=i+1;
	}
	scanf("%d",&K);
	FOR(i,K) {
		scanf("%d",&A[i]);
		isS[A[i]]=1;
	}
	isS[0]=1;
	
	dfs(0);
	isS[0]=0;
	dfs2(0);
	
	
	FOR(i,K) _P("%d ",T[A[i]]);
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}