
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


int T;
int H,W;
string S[2020];
int D[2020][2020];
vector<int> C;
int hoge(int y,int x) {
	int i,num=0;
	FOR(i,C.size()) if(C[C.size()-1-i]==y*2000+x) break;
	num=i+1;
	FOR(i,num) {
		D[C.back()/2000][C.back()%2000]=num;
		C.pop_back();
	}
	return num;
}
int dfs(int y,int x) {
	//cout<<&y<<endl;
	if(y<0||y>=H||x<0||x>=W) return 0;
	if(D[y][x]<0) return hoge(y,x);
	if(D[y][x]<1<<30) return D[y][x];
	D[y][x]=-1;
	static int k;
	C.push_back(y*2000+x);
	if(S[y][x]=='L') k=dfs(y,x-1);
	if(S[y][x]=='R') k=dfs(y,x+1);
	if(S[y][x]=='U') k=dfs(y-1,x);
	if(S[y][x]=='D') k=dfs(y+1,x);
	if(D[y][x]<0) {
		D[y][x]=k+1;
	}
	return D[y][x];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) {
			cin>>S[y];
			FOR(x,W) D[y][x]=1<<30;
		}
		int my=0,mx=0;
		FOR(y,H) FOR(x,W) {
			k=dfs(y,x);
			if(k>D[my][mx]) my=y,mx=x;
			C.clear();
		}
		cout<<my+1<<" "<<mx+1<<" "<<D[my][mx]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}