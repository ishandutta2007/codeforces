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

template<int MV> class UndirectedEulerPath {
public:
	vector<int> path;
	vector<vector<int>> ret;
	multiset<int> E[MV];
	void add_path(int x,int y) { E[x].insert(y); E[y].insert(x); }
	
	void dfs(int cur) {
		path.push_back(cur);
		if(E[cur].size()) {
			int tar=*E[cur].begin();
			E[cur].erase(E[cur].begin());
			E[tar].erase(E[tar].find(cur));
			dfs(tar);
		}
	}
	
	void GetPath() { // 
		int i;
		FOR(i,MV) {
			if(E[i].size()%2) {
				path.clear();
				dfs(i);
				ret.push_back(path);
			}
		}
		FOR(i,MV) if(E[i].size()) {
			path.clear();
			dfs(i);
			ret.push_back(path);
		}
		
	}

};

UndirectedEulerPath<1010000> uep;
int N,M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		uep.add_path(x,y);
	}
	
	uep.GetPath();
	vector<pair<int,int>> V;
	FORR(v,uep.ret) {
		for(i=0;i+1<v.size();i+=2) V.push_back({v[i],v[i+1]});
		if(v.size()%2) V.push_back({v[v.size()-2],v[v.size()-1]});
	}
	cout<<V.size()<<endl;
	FORR(v,V) cout<<v.first<<" "<<v.second<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}