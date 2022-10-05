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
int A[505][505];
int C[1010];
vector<int> E[1010];
int K;

int dfs(vector<int> V) {
	if(V.size()==1) return V[0];
	int cur=K++;
	
	int ma=0;
	FORR(a,V) FORR(b,V) ma=max(ma,A[a][b]);
	vector<int> X,Y;
	C[cur]=ma;
	
	map<int,int> vis;
	FORR(a,V) if(vis[a]==0) {
		vector<int> cand;
		FORR(b,V) if(A[a][b]!=ma) {
			cand.push_back(b);
			vis[b]=1;
		}
		E[dfs(cand)].push_back(cur);
	}
	return cur;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>A[y][x];
	vector<int> V;
	FOR(i,N) {
		V.push_back(i);
		C[i]=A[i][i];
		A[i][i]=0;
	}
	K=N;
	int root=dfs(V);
	
	cout<<K<<endl;
	FOR(i,K) cout<<C[i]<<" ";
	cout<<endl;
	cout<<(root+1)<<endl;
	FOR(i,K) FORR(e,E[i]) cout<<(i+1)<<" "<<(e+1)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}