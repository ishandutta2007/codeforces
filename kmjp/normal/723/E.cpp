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

template<int MV> class UndirectedEulerPath {
public:
	vector<int> path;
	multiset<int> E[MV];
	void add_path(int x,int y) { E[x].insert(y); E[y].insert(x); }
	
	void dfs(int cur) {
		while(E[cur].size()) {
			int tar=*E[cur].begin();
			E[cur].erase(E[cur].begin());
			E[tar].erase(E[tar].find(cur));
			dfs(tar);
		}
		path.push_back(cur);
	}
	
	bool GetPath() {
		int fo=-1,odd=0,i,np=0;
		FOR(i,MV) {
			np += E[i].size();
			if(E[i].size()%2) odd++, fo=(fo==-1)?i:fo;
		}
		if(odd!=0 && odd!=2) return false;
		dfs(odd?fo:0);
		reverse(path.begin(),path.end());
		return path.size()==np/2+1;
	}
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	int T,N,M;
	
	cin>>T;
	while(T--) {
		int mat[203][203]={};
		int E[203]={};
		ZERO(mat);
		UF<220> uf;
		
		cin>>N>>M;
		int ret=N;
		UndirectedEulerPath<205> uep;
		
		FOR(i,M) {
			cin>>x>>y;
			x--;
			y--;
			mat[x][y]=mat[y][x]=1;
			E[x]++;
			E[y]++;
			uf(x,y);
			uep.add_path(x,y);
		}
		
		int pre=-1;
		FOR(i,N) if(uep.E[i].size()%2==1) {
			ret--;
			if(pre==-1) {
				pre=i;
			}
			else {
				uep.add_path(pre,i);
				uf(pre,i);
				pre=-1;
			}
		}
		
		
		FOR(i,N) if(uf[i]!=uf[0]) {
			uep.add_path(0,i);
			uep.add_path(0,i);
			uf(0,i);
		}
		
		
		uep.GetPath();
		_P("%d\n",ret);
		FOR(i,(int)uep.path.size()-1) {
			if(mat[uep.path[i]][uep.path[i+1]]) {
				_P("%d %d\n",uep.path[i]+1,uep.path[i+1]+1);
				mat[uep.path[i]][uep.path[i+1]]=mat[uep.path[i+1]][uep.path[i]]=0;
			}
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}