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

int N,Q;
vector<vector<int>> V;
map<pair<int,int>,int> M;
int ret[101010];

template<int um> class UF_pop {
	public:
	vector<int> par,rank; vector<vector<int>> hist;
	UF_pop() {par=rank=vector<int>(um,0); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):operator[](par[x]);}
	void pop() {
		if(hist.size()) {
			auto a=hist.back();
			hist.pop_back();
			par[a[0]]=a[1]; rank[a[0]]=a[2];
			par[a[3]]=a[4]; rank[a[3]]=a[5];
		}
	}
	void operator()(int x,int y) {
		x=operator[](x); y=operator[](y);
		hist.push_back({x,par[x],rank[x],y,par[y],rank[y]});
		if(x==y) return;
		if(rank[x]<rank[y]) par[x]=y;
		else rank[x]+=(rank[x]==rank[y]), par[y]=x;
	}
};

void dfs(int L,int R,UF_pop<201010>& uf,vector<vector<int>> V) {
	vector<vector<int>> LV,RV;
	int nums=0;
	int M=(L+R)/2;
	int con=0;
	
	if(V.empty()) return;
	
	FORR(v,V) {
		if(v[2]<=L && R<=v[3]) {
			uf(v[0]*2,v[1]*2+1);
			uf(v[0]*2+1,v[1]*2);
			if(uf[v[0]*2]==uf[v[0]*2+1]) con=1;
			if(uf[v[1]*2]==uf[v[1]*2+1]) con=1;
			nums+=2;
		}
		else {
			if(v[2]<M) LV.push_back({v[0],v[1],max(L,v[2]),min(M,v[3])});
			if(v[3]>M) RV.push_back({v[0],v[1],max(M,v[2]),min(R,v[3])});
		}
	}
	
	int i;
	if(con) {
		for(int i=L;i<R;i++) ret[i]=1;
	}
	else {
		dfs(L,M,uf,LV);
		dfs(M,R,uf,RV);
	}
	while(nums--) uf.pop();
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,Q) {
		cin>>x>>y;
		x--,y--;
		if(x>y) swap(x,y);
		
		if(M.count({x,y})==0) {
			M[{x,y}]=i;
		}
		else {
			V.push_back({x,y,M[{x,y}],i});
			M.erase({x,y});
		}
	}
	FORR(r,M) V.push_back({r.first.first,r.first.second,r.second,Q});
	
	UF_pop<201010> uf;
	dfs(0,Q,uf,V);
	
	FOR(i,Q) {
		if(ret[i]) cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}