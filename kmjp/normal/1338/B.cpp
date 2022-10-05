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
vector<int> E[101010];
int D[202020];
int C[2];
int ma;

void dfs(int cur,int pre,int d) {
	if(E[cur].size()==1) C[d]++;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d^1);
}

void dfs2(int cur,int pre,int d) {
	
	int leaf=0;
	FORR(e,E[cur]) if(e!=pre) {
		if(E[e].size()==1) {
			leaf++;
		}
		else {
			ma++;
			dfs2(e,cur,d+1);
		}
	}
	
	if(leaf && d!=1) ma++;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) if(E[i].size()==1) break;
	int root=i;
	dfs(0,0,0);
	
	int mi=1;
	if(C[0]&&C[1]) mi=3;
	dfs2(root,root,0);
	
	
	
	cout<<mi<<" "<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}