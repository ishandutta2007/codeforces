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
string S;
int L[202020];
int R[202020];
int should[202020];
vector<pair<char,int>> T;
int C[202020];
int dup[202020];

int dfs(int cur) {
	C[cur]=1;
	if(L[cur]) C[cur]+=dfs(L[cur]);
	T.push_back({S[cur-1],cur});
	if(R[cur]) C[cur]+=dfs(R[cur]);
	return C[cur];
}

int dfs2(int cur,int cost) {
	if(cost>K) return 0;
	if(L[cur]) {
		dup[cur]=dfs2(L[cur],cost+1);
	}
	if(dup[cur]==0&&should[cur]) {
		K-=cost;
		dup[cur]=1;
	}
	if(dup[cur]&&R[cur]) dfs2(R[cur],1);
	
	
	return dup[cur];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	FOR(i,N) {
		cin>>L[i+1]>>R[i+1];
	}
	dfs(1);
	for(i=N-2;i>=0;i--) {
		if(T[i].first<T[i+1].first) {
			should[T[i].second]=1;
		}
		if(T[i].first==T[i+1].first) {
			should[T[i].second]=should[T[i+1].second];
		}
	}
	dfs2(1,1);
	FOR(i,N) {
		cout<<T[i].first;
		if(dup[T[i].second]) {
			cout<<T[i].first;
		}
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}