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

int N,K;

template<int MV> class DirectedEulerPath {
public:
	int NV;
	vector<int> path;
	vector<int> E[MV];
	void add_path(int x,int y) { E[x].push_back(y);}
	
	void init(int NV){
		this->NV=NV;
		for(int i=0;i<NV;i++) E[i].clear();
		path.clear();
	}
	void dfs(int cur) {
		while(E[cur].size()) {
			int e=E[cur].back();
			E[cur].pop_back();
			dfs(e);
		}
		path.push_back(cur);
	}
	bool GetPath() {
		assert(NV);
		int te=0,i;
		vector<int> deg(NV);
		FOR(i,NV) {
			te += E[i].size();
			deg[i]+=E[i].size();
			FORR(e,E[i]) deg[e]--;
		}
		int d0=0,s=0;
		FOR(i,NV) {
			if(deg[i]>1 || deg[i]<-1) return false;
			if(deg[i]==0) d0++;
			if(deg[i]==1) s=i;
		}
		if(d0!=NV && d0+2!=NV) return false;
		dfs(s);
		reverse(path.begin(),path.end());
		return path.size()==te+1;
	}
};

DirectedEulerPath<26> uep;
int C[26][26];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	uep.init(K);
	FOR(i,K) {
		FOR(j,K) if(i!=j) uep.add_path(i,j);
		uep.add_path(i,i);
	}
	
	uep.GetPath();
	string S;
	/*
	FOR(i,uep.path.size()-1) C[uep.path[i]][uep.path[i+1]]++;
	FOR(i,K) {
		FOR(j,K) cout<<C[i][j];
		cout<<endl;
	}
	*/
	if(K!=1) uep.path.pop_back();
	
	/*
	FORR(v,uep.path) cout<<(char)(v+'a');
	cout<<endl;
	*/
	FOR(i,N) S.push_back('a'+uep.path[i%(uep.path.size())]);
	cout<<S<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}