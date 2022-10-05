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


int T,H,W,R,C;
string S[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W>>R>>C;
		int can=0;
		FOR(y,H) {
			cin>>S[y];
			FORR(c,S[y]) if(c=='B') can=1;
		}
		if(can==0) {
			cout<<-1<<endl;
			continue;
		}
		int ny=0,nx=0;
		FOR(y,H) ny+=S[y][C-1]=='B';
		FOR(x,W) nx+=S[R-1][x]=='B';
		
		if(S[R-1][C-1]=='B') {
			cout<<0<<endl;
		}
		else if(ny||nx) {
			cout<<1<<endl;
		}
		else {
			cout<<2<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}