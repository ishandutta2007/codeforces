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

void check(int N,vector<pair<int,int>> V) {
	int MP[N][N]={};
	
	FORR2(y,x,V) {
		int i;
		FOR(i,N) MP[y][i]=MP[i][x]=1;
		FOR(i,N) {
			int y2=y+i-x;
			if(y2>=0&&y2<N) MP[y2][i]=1;
		}
	}
	FORR2(y,x,V) MP[y][x]=2;
	int i,j;
	
	FOR(i,N) {
		FOR(j,N) cout<<MP[i][j];
		cout<<endl;
	}
	
	FOR(i,N) FOR(j,N) assert(MP[i][j]);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	
	vector<pair<int,int>> V;
	if(N%3==0) {
		FOR(i,N/3) V.push_back({N/3-1-i,i});
		FOR(i,N/3) V.push_back({(N/3-1)*2-i,N/3+i});
	}
	else {
		FOR(i,N/3+1) V.push_back({N/3-i,i});
		FOR(i,N/3) V.push_back({(N/3)*2-i,N/3+1+i});
	}
	
	//check(N,V);
	cout<<V.size()<<endl;
	FORR2(y,x,V) cout<<y+1<<" "<<x+1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}