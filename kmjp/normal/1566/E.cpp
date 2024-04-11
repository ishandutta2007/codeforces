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
set<int> E[202020];
vector<int> num;
int bud[202020];

void dfs(int cur,int pre) {
	int ok=0;
	E[cur].erase(pre);
	
	vector<int> del;
	FORR(e,E[cur]) {
		dfs(e,cur);
		
		if(E[e].size()==0) {
			ok++;
		}
		else {
			if(bud[e]) del.push_back(e);
		}
	}
	
	FORR(e,del) E[cur].erase(e);
	if(ok) {
		num.push_back(ok);
		bud[cur]=1;
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) E[i].clear();
		FOR(i,N-1) {
			cin>>x>>y;
			E[x-1].insert(y-1);
			E[y-1].insert(x-1);
		}
		num.clear();
		dfs(0,0);
		
		int sum=0;
		FORR(a,num) sum+=a;
		sum-=num.size()-1;
		cout<<sum<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}