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

int N;
vector<int> E[201010];

int vis[201010];
int NV[201010];

ll A[202020];
ll ret=0;
vector<pair<ll,ll>> V;

template<typename V> struct LeChaoTree {
	static const V inf=3LL<<60;
	const ll range=1<<20;
	const bool cmptype=true; //true:max false:min
	struct node {
		node(V a=0,V b=-inf) : A(a),B(b){ le=ri=NULL;}
		V val(ll x) { return A*x+B;}
		V A,B;  // Ax+B
		node *le, *ri;
	};
	
	node* root;
	LeChaoTree() { root=new node(0,-inf);}
	
	void add(node* n, V a,V b,ll L,ll R) {
		ll M=(L+R)/2;
		
		bool lef=(n->val(L) > a*L+b);
		bool mid=(n->val(M) > a*M+b);
		bool ri=(n->val(R) > a*R+b);
		
		if(lef&&ri) return;
		if(!lef&&(!ri || R-L==1)) {
			n->A=a;
			n->B=b;
			return;
		}
		
		if(R-L==1) return;
		if(!n->ri) n->ri=new node();
		if(!n->le) n->le=new node();
		add(n->ri,a,b,M,R);
		add(n->le,a,b,L,M);
	}
	
	void add(V a,V b) { 
		if(!cmptype) a=-a,b=-b;
		add(root,a,b,0,range);
	}
	
	V query(ll x) {
		V ret=-inf;
		node* cur=root;
		ll L=0, R=range;
		while(cur) {
			ret=max(ret,cur->val(x));
			ll m=(L+R)/2;
			if(x<m) cur=cur->le, R=m;
			else cur=cur->ri, L=m;
			
		}
		
		if(!cmptype) ret=-ret;
		return ret;
	}
};
LeChaoTree<ll>* lct;

int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) NV[cur]+=dfs(e,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) {
		int c = dfs2(e,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e];
		if(NV[e]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

void dfs3(int cur,int pre,ll S,ll T,ll w,ll S2,ll T2,ll d) {
	T+=A[cur];
	S+=++w*A[cur];
	V.push_back({T,S});
	T2+=A[cur];
	S2+=T2;
	d++;
	//cout<<"!"<<cur<<" "<<S<<" "<<T<<" "<<w<<" "<<d<<" "<<S2<<" "<<T2<<" "<<lct->query(d)<<endl;
	ret=max(ret,lct->query(d)+S2);
	ret=max(ret,S);
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) dfs3(e,cur,S,T,w,S2,T2,d);
}

void split(int cur) {
	int TNV = dfs(cur,-1);
	if(TNV==0) return;
	int center=dfs2(cur,-1,TNV);
	//cout<<"go"<<center<<endl;
	lct=new LeChaoTree<ll>();
	lct->add(A[center],A[center]);
	FORR(e,E[center]) if(vis[e]==0) {
		dfs3(e,center,A[center],A[center],1,0,0,0);
		FORR(v,V) lct->add(v.first,v.second);
		V.clear();
	}
	reverse(ALL(E[center]));
	lct=new LeChaoTree<ll>();
	lct->add(A[center],A[center]);
	FORR(e,E[center]) if(vis[e]==0) {
		dfs3(e,center,A[center],A[center],1,0,0,0);
		FORR(v,V) lct->add(v.first,v.second);
		V.clear();
	}
	
	
	
	vis[center]=1;
	FORR(e,E[center]) if(vis[e]==0) split(e);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) cin>>A[i];
	split(0);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}