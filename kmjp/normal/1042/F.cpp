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
vector<int> E[1010101];
int D[1010101];
int ret=0;
int K;
vector<int> Ds[1010101];

int dfs(int cur,int pre,int d) {
	D[cur]=d;
	if(E[cur].size()==1) {
		return d;
	}
	FORR(e,E[cur]) if(e!=pre) {
		int a=dfs(e,cur,d+1);
		if(a>=0) Ds[cur].push_back(a);
	}
	sort(ALL(Ds[cur]));
	
	while(Ds[cur].size() && Ds[cur].back()-d>=K) {
		ret++;
		Ds[cur].pop_back();
	}
	
	while(Ds[cur].size()>=2 && Ds[cur][Ds[cur].size()-2]+Ds[cur][Ds[cur].size()-1]-2*d>K) {
		ret++;
		Ds[cur].pop_back();
	}
	if(Ds[cur].empty()) return -1;
	return Ds[cur].back();
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) if(E[i].size()>=2) break;
	
	if(dfs(i,i,0)>=0) ret++;
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}