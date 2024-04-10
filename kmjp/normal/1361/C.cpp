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
int A[1010101],B[1010101];
int X[1010101],Y[1010101];
int vis[1010101];

template<int MV> class UndirectedEulerPath {
public:
	vector<int> path;
	vector<int> E[MV];
	
	void dfs(int cur,int from=-1,int to=-1) {
		while(E[cur].size()) {
			int tar=E[cur].back();
			E[cur].pop_back();
			if(vis[tar/2]==0) {
				vis[tar/2]=1;
				if(tar%2) {
					dfs(X[tar/2],tar,tar^1);
				}
				else {
					dfs(Y[tar/2],tar,tar^1);
				}
			}
		}
		if(from>=0) {
			path.push_back(to);
			path.push_back(from);
		}
	}
	
	bool GetPath() { // 
		int fo=-1,odd=0,i,np=0,c=-1;;
		FOR(i,MV) {
			np += E[i].size();
			if(E[i].size()%2) odd++, fo=(fo==-1)?i:fo;
			if(E[i].size()) c=i;
		}
		if(odd) return false;
		dfs(odd?fo:c);
		reverse(path.begin(),path.end());
		return path.size()==np;
	}
};

UndirectedEulerPath<1<<20> uep;

void solve() {
	int i,j,k,l,r,x,y; string s;

	scanf("%d",&N);
	FOR(i,N) scanf("%d%d",&A[i],&B[i]);
	
	for(i=19;i>=0;i--) {
		FOR(j,1<<20) uep.E[j].clear();
		ZERO(vis);
		uep.path.clear();
		FOR(j,N) {
			X[j]=A[j]&((1<<(i+1))-1);
			Y[j]=B[j]&((1<<(i+1))-1);
			uep.E[X[j]].push_back(2*j);
			uep.E[Y[j]].push_back(2*j+1);
			
		}
		if(uep.GetPath()) {
			auto p=uep.path;
			if(p.size()==2*N) {
				
				_P("%d\n",i+1);
				FORR(a,p) _P("%d ",a+1);
				_P("\n");
				return;
			}
		}
	}
	_P("0\n");
	FOR(i,2*N) _P("%d ",i+1);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}