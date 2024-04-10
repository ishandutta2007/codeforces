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

int N;
int dp[2020][2020];
set<pair<int,int>> E;

void add(int x,int y) {
	if(x>y) swap(x,y);
	E.insert({x+1,y+1});
}

void ask(int v) {
	if(dp[v][v]==-1) {
		cout<<"? "<<v+1<<endl;
		int i;
		FOR(i,N) cin>>dp[v][i];
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	MINUS(dp);
	
	cin>>N;
	
	ask(0);
	vector<int> C[2];
	FOR(i,N) C[dp[0][i]%2].push_back(i);
	
	if(C[1].size()<C[0].size()) swap(C[0],C[1]);
	FORR(e,C[0]) {
		ask(e);
		FOR(i,N) if(dp[e][i]==1) add(e,i);
	}
	
	
	cout<<"!"<<endl;
	FORR(v,E) cout<<v.first<<" "<<v.second<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}