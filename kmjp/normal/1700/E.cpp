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
vector<int> A[404040];
int RY[404040],RX[404040];
int ok[404040];
int d[4]={0,1,0,-1};


int isng(int y,int x) {
	if(y<0||y>=H||x<0||x>=W) return 0;
	if(A[y][x]==0) return 0;
	int i;
	FOR(i,4) {
		int ty=y+d[i];
		int tx=x+d[i^1];
		if(ty>=0&&ty<H&&tx>=0&&tx<W&&A[ty][tx]<A[y][x]) return 0;
	}
	return 1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		A[y].resize(W);
		FOR(x,W) {
			cin>>A[y][x];
			A[y][x]--;
			RY[A[y][x]]=y;
			RX[A[y][x]]=x;
		}
	}
	
	int mi=404040;
	int ng=0;
	FOR(y,H) FOR(x,W) {
		if(isng(y,x)) mi=min(mi,A[y][x]);
		ng+=isng(y,x);
	}
	
	if(ng==0) {
		cout<<0<<endl;
		return;
	}
	vector<pair<int,int>> S,T;
	FOR(y,H) FOR(x,W) S.push_back({y,x});
	T={{RY[mi],RX[mi]}};
	FOR(i,4) {
		int ty=RY[mi]+d[i];
		int tx=RX[mi]+d[i^1];
		if(ty>=0&&ty<H&&tx>=0&&tx<W) T.push_back({ty,tx});
	}
	int num=0;
	unordered_set<ll> did;
	vector<pair<int,int>> C;
	FORR(a,S) FORR(b,T) {
		ll ap=a.first*W+a.second;
		ll bp=b.first*W+b.second;
		C={a,b};
		if(did.count((bp<<30)+ap)) continue;
		did.insert((ap<<30)+bp);
		FOR(i,4) {
			int ty=a.first+d[i];
			int tx=a.second+d[i^1];
			if(ty>=0&&ty<H&&tx>=0&&tx<W) C.push_back({ty,tx});
		}
		FOR(i,4) {
			int ty=b.first+d[i];
			int tx=b.second+d[i^1];
			if(ty>=0&&ty<H&&tx>=0&&tx<W) C.push_back({ty,tx});
		}
		sort(ALL(C));
		C.erase(unique(ALL(C)),C.end());
		FORR2(y,x,C) ng-=isng(y,x);
		swap(A[a.first][a.second],A[b.first][b.second]);
		FORR2(y,x,C) ng+=isng(y,x);
		if(ng==0) num++;
		FORR2(y,x,C) ng-=isng(y,x);
		swap(A[a.first][a.second],A[b.first][b.second]);
		FORR2(y,x,C) ng+=isng(y,x);
	}
	
	if(num) {
		cout<<"1 "<<num<<endl;
	}
	else {
		cout<<2<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}