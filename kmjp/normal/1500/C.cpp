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


int H,W;
vector<int> A[1515],B[1515];
map<vector<int>,int> M;

int T[1515];
set<int> C[1515];
set<int> D[1515];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&H,&W);
	FOR(y,H) {
		A[y].resize(W);
		FOR(x,W) scanf("%d",&A[y][x]);
		M[A[y]]++;
	}
	
	FOR(y,H) {
		B[y].resize(W);
		FOR(x,W) scanf("%d",&B[y][x]);
		M[B[y]]--;
		if(M[B[y]]<0) return _P("-1\n");
	}
	
	vector<int> ret;
	queue<int> Q;
	FOR(x,W) {
		FOR(y,H-1) if(B[y][x]>B[y+1][x]) C[x].insert(y), D[y].insert(x);
		if(C[x].empty()) Q.push(x);
	}
	while(Q.size()) {
		x=Q.front();
		ret.push_back(x);
		Q.pop();
		FOR(y,H-1) if(B[y][x]<B[y+1][x]) {
			FORR(r,D[y]) {
				C[r].erase(y);
				if(C[r].empty()) Q.push(r);
			}
			D[y].clear();
		}
		
	}
	
	if(ret.size()!=W) return _P("-1\n");
	cout<<ret.size()<<endl;
	reverse(ALL(ret));
	FORR(r,ret) cout<<(r+1)<<" ";
	cout<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}