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
int A[505][505];
int B[505][505];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>s;
		FOR(x,W) A[y][x]=s[x]=='B';
	}
	FOR(y,H) FOR(x,W) B[y][x]=A[y][x]^A[y+1][x]^A[y][x+1]^A[y+1][x+1];
	int ret=0;
	FOR(y,H-1) FOR(x,W-1) {
		if(B[y][x]&&B[H-1][x]&&B[y][W-1]&&B[H-1][W-1]) {
			ret+=3;
			B[y][x]=B[H-1][x]=B[y][W-1]=B[H-1][W-1]=0;
		}
	}
	FOR(y,H) FOR(x,W) ret+=B[y][x];
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}