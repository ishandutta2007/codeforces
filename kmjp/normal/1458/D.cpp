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

int T,N;
string S;

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
	
	bool GetPath(int root=-1) {
		assert(NV);
		int te=0,i;
		vector<int> deg(NV);
		FOR(i,NV) {
			sort(ALL(E[i]));
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
		s=root;
		dfs(s);
		reverse(path.begin(),path.end());
		return path.size()==te+1;
	}
};

DirectedEulerPath<1202020> dep;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		int cur=0;
		int mi=0,ma=0;
		FORR(c,S) {
			if(c=='0') cur++;
			else cur--;
			mi=min(mi,cur);
			ma=max(ma,cur);
		}
		dep.init(ma-mi+1);
		cur=-mi;
		FORR(c,S) {
			if(c=='0') {
				dep.add_path(cur,cur+1);
				cur++;
			}
			else {
				dep.add_path(cur,cur-1);
				cur--;
			}
		}
		assert(dep.GetPath(-mi));
		string R;
		FOR(i,N) {
			if(dep.path[i]<dep.path[i+1]) R+='0';
			else R+='1';
		}
		cout<<R<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}