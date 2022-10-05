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

int A;
int H,W;
string S[500],T[500];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>A;
	while(A--) {
		cin>>H>>W;
		FOR(y,H) {
			cin>>S[y];
			T[y]=string(W,'.');
		}
		FOR(x,W) T[0][x]='X';
		int s=0;
		if(W%3==0) s=1;
		else s=0;
		for(x=s;x<W;x+=3) FOR(y,H) T[y][x]='X';
		FOR(y,H) FOR(x,W) if(S[y][x]=='X') T[y][x]='X';
		
		if(H>=2) {
			FOR(x,W) if(x%3!=s&&T[1][x]=='X') {
				if(x) T[1][x-1]='X';
				if(x<W) T[1][x+1]='X';
			}
			FOR(x,W) if(x%3!=s&&T[1][x]=='X') T[0][x]='.';
			
		}
		
		
		
		FOR(y,H) cout<<T[y]<<endl;
		
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}