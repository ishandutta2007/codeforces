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
int B[101010],C[101010];

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
	
	bool GetPath() { // 
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

	vector<int> GetPath(int root) { //
		dfs(root);
		reverse(path.begin(),path.end());
		return path;
	}
};

vector<int> ret;
vector<int> D;
UndirectedEulerPath<202020> uep;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) cin>>B[i];
	FOR(i,N-1) cin>>C[i];
	FOR(i,N-1) {
		if(B[i]>C[i]) return _P("-1\n");
		D.push_back(B[i]);
		D.push_back(C[i]);
	}
	sort(ALL(D));
	D.erase(unique(ALL(D)),D.end());
	FOR(i,N-1) {
		B[i]=lower_bound(ALL(D),B[i])-D.begin();
		C[i]=lower_bound(ALL(D),C[i])-D.begin();
		uep.add_path(B[i],C[i]);
	}
	
	if(!uep.GetPath()) return _P("-1\n");
	FORR(r,uep.path) cout<<D[r]<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}