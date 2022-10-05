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

template<int um> class UF {
	public:
	vector<int> par,rank;
	UF() {rank=vector<int>(um,0); for(int i=0;i<um;i++) par.push_back(i);}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};
UF<500000> uf;

int N;
int A[303030];
ll S[303030];
vector<int> E[303030];

ll ma[303030];
ll ret;
int ret2;

void dfs(int cur,int pre) {
	ma[cur]=A[cur];
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		if(ma[e]>0) ma[cur]+=ma[e];
	}
}

void dfs2(int cur,int pre) {
	ma[cur]=A[cur];
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur);
		if(ma[e]>0) ma[cur]+=ma[e];
	}
	if(ma[cur]==ret) {
		ret2++;
		ma[cur]=-1LL<<60;
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	
	dfs(0,-1);
	ret=*max_element(ma,ma+N);
	dfs2(0,-1);
	
	cout<<ret*ret2<<" "<<ret2<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}