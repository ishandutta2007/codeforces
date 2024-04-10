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


int T,H,W;
string S[101];

void go(int y,int x) {
	
	int d[3]={-1,0,1};
	int dx,dy;
	for(dy=max(0,y-1);dy<=min(H-1,y+1);dy++) {
		for(dx=max(0,x-1);dx<=min(W-1,x+1);dx++) {
			if(S[dy][dx]=='1') return;
		}
	}
	
	
	S[y][x]='1';
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>H>>W;
		FOR(y,H) S[y]=string(W,'0');
		
		
		
		FOR(x,W) go(0,x);
		for(y=1;y<H;y++) go(y,W-1);
		for(x=W-2;x>=0;x--) go(H-1,x);
		for(y=H-2;y>0;y--) go(y,0);
		
		
		FOR(y,H) cout<<S[y]<<endl;
		cout<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}