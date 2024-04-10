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

int N,M;
int C[301010];
ll X[301010];
vector<int> E[303030];
int P[21][300005],D[300005];
int L[303030],R[303030],ret[303030];

struct Node {
	Node *L, *R;
	ll val;
};
Node nodes[303030*50];
Node* root[303030];

Node* getnext() {
	static int nex;
	return &nodes[nex++];
}

Node* build(int L,int R) {
	Node* n=getnext();
	if(L==R) {
		return n;
	}
	else {
		int M=(L+R)/2;
		n->L=build(L,M);
		n->R=build(M+1,R);
		return n;
	}
}
Node* update(Node* cur,int L,int R,int id) {
	Node* n=getnext();
	*n=*cur;
	if(L==R) {
		n->val^=X[id];
	}
	else {
		int M=(L+R)/2;
		if(id<=M) {
			n->L=update(n->L,L,M,id);
		}
		else {
			n->R=update(n->R,M+1,R,id);
		}
		n->val = n->L->val ^ n->R->val;
	}
	return n;
	
	
}

void dfs(int cur) {
	if(cur) {
		root[cur]=update(root[P[0][cur]],1,N,C[cur]);
	}
	
	FORR(e,E[cur]) if(e!=P[0][cur]) D[e]=D[cur]+1, P[0][e]=cur, dfs(e);
}
int lca(int a,int b) {
	int ret=0,i,aa=a,bb=b;
	if(D[aa]>D[bb]) swap(aa,bb);
	for(i=19;i>=0;i--) if(D[bb]-D[aa]>=1<<i) bb=P[i][bb];
	for(i=19;i>=0;i--) if(P[i][aa]!=P[i][bb]) aa=P[i][aa], bb=P[i][bb];
	return (aa==bb)?aa:P[0][aa];               // vertex
}


int search(Node* a,Node* b,Node* c,Node* d,int L,int R) {
	if(L==R) return L;
	int M=(L+R)/2;
	if(a->L->val^b->L->val^c->L->val^d->L->val) return search(a->L,b->L,c->L,d->L,L,M);
	else return search(a->R,b->R,c->R,d->R,M+1,R);
	
}

int query(Node* a,Node* b,Node* c,Node* d,int RL,int RR,int TL,int TR) {
	if(RL>RR) return -1;
	if(RL==TL&&RR==TR) {
		if(a->val^b->val^c->val^d->val) {
			return search(a,b,c,d,TL,TR);
		}
		else {
			return -1;
		}
	}
	int M=(RL+RR)/2;
	if(TR<=M) return query(a->L,b->L,c->L,d->L,RL,M,TL,TR);
	if(TL>M) return query(a->R,b->R,c->R,d->R,M+1,RR,TL,TR);
	int ret=query(a->L,b->L,c->L,d->L,RL,M,TL,M);
	if(ret==-1) ret=query(a->R,b->R,c->R,d->R,M+1,RR,M+1,TR);
	return ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	srand(time(NULL));
	FOR(i,N) {
		X[i+1]=rand()*(1LL<<30)+rand();
	}
	E[0].push_back(1);
	E[1].push_back(0);
	
	FOR(i,N) cin>>C[i+1];
	FOR(i,N-1) {
		cin>>x>>y;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	N++;
	root[0]=build(1,N);
	dfs(0);
	FOR(i,19) FOR(x,N) P[i+1][x]=P[i][P[i][x]];
	
	while(M--) {
		int U,V,L,R;
		cin>>U>>V>>L>>R;
		int lc=lca(U,V);
		int p=P[0][lc];
		cout<<query(root[U],root[V],root[lc],root[p],1,N,L,R)<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}