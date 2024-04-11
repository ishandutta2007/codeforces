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

template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) bit[0][entry-1]+=val0, bit[1][entry-1] += val1, entry += entry & -entry;
	}
	V total(int entry) {
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		return e*v0+v1;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,-val*(L-1));
		update(R+1,-val,val*R);
	}
};

BIT_r<ll,20> bt;
vector<int> E[200005];
int P[21][200005],D[200005];
int L[200005],R[200005],eid=1;


void dfs(int cur) {
	L[cur]=eid++;
	ITR(it,E[cur]) if(*it!=P[0][cur]) D[*it]=D[cur]+1, P[0][*it]=cur, dfs(*it);
	R[cur]=eid;
}
int getpar(int cur,int up) {
	int i;
	FOR(i,20) if(up&(1<<i)) cur=P[i][cur];
	return cur;
}

int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}


int N,Q,root;
ll A[101010];
int U,V,X;
ll S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&Q);
	FOR(i,N) scanf("%d",&x), A[i]=x;
	FOR(i,N-1) {
		scanf("%d%d",&x,&y);
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];

	FOR(i,N) bt.add(L[i],L[i],A[i]);
	while(Q--) {
		scanf("%d%d",&i,&U);
		U--;
		if(i==1) {
			root=U;
		}
		else if(i==2) {
			scanf("%d%d",&V,&X);
			V--;
			
			int lu=lca(U,root);
			int lv=lca(V,root);
			int lc=lca(U,V);
			
			if((getpar(U,D[U]-D[root])==root || getpar(V,D[V]-D[root])==root) && D[lc]<=D[root]) {
				bt.add(1,N,X);
			}
			else if(D[lca(lc,root)]<D[lc]) {
				bt.add(L[lc],R[lc]-1,X);
			}
			else {
				if(D[lu]<D[lv]) lu=lv;
				bt.add(1,N,X);
				lv=getpar(root,D[root]-D[lu]-1);
				bt.add(L[lv],R[lv]-1,-X);
			}
		}
		else {
			if(root==U) {
				cout<<bt.total(N)<<endl;
			}
			else if(L[U]<L[root] && L[root]<R[U]) {
				ll tot=bt.total(N);
				V=getpar(root,D[root]-D[U]-1);
				tot-=bt.total(R[V]-1)-bt.total(L[V]-1);
				cout<<tot<<endl;
			}
			else {
				cout<<(bt.total(R[U]-1)-bt.total(L[U]-1))<<endl;
			}
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}