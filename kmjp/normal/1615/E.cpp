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
vector<int> E[202020];
vector<int> C;

int dfs(int cur,int pre,int d) {
	vector<int> V;
	if(cur&&E[cur].size()==1) V.push_back(d);
	FORR(e,E[cur]) if(e!=pre) V.push_back(dfs(e,cur,d+1));
	sort(ALL(V));
	int i;
	FOR(i,V.size()-1) C.push_back(V[i]-d-1);
	return V.back();
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	C.push_back(dfs(0,0,0));
	
	ll ret=0;
	if(K>=C.size()) {
		for(i=C.size();i<=K;i++) ret=max(ret,1LL*i*(N-i));
	}
	else {
		sort(ALL(C));
		reverse(ALL(C));
		int R=K;
		int W=0;
		FOR(i,K) W+=C[i];
		int B=N-R-W;
		
		if(B<R) {
			ret=1LL*W*(R-B);
		}
		else {
			ret=1LL<<30;
			for(i=0;i<=B;i++) ret=min(ret,1LL*(N-R-i)*(R-i));
		}
		
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}