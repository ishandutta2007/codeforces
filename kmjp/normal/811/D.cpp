#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W;
string S[101];

int S_LR,S_UD;
int TX,TY;

int vis[101][101];
string from[101][101];


pair<int,int> ask(string s) {
	int r,c;
	cout<<s<<endl;
	cin>>r>>c;
	if(r==TY+1 && c==TX+1) exit(0);
	return {r-1,c-1};
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		FOR(x,W) if(S[y][x]=='F') {
			S[y][x]='.';
			TY=y;
			TX=x;
		}
	}
	
	if(TY==0 && TX==0) return;
	
	S_LR=-1,S_UD=-1;
	if(H==1) S_UD=0;
	if(W==1) S_LR=0;
	
	if(W>1 && S[0][1]=='.') {
		auto a=ask("L");
		if(a.second==1) S_LR=1, ask("R");
		else S_LR=0;
	}
	if(H>1 && S[1][0]=='.') {
		auto a=ask("U");
		if(a.first==1) S_UD=1, ask("D");
		else S_UD=0;
	}
	
	int cy=0,cx=0;
	if(S_LR==-1) {
		while(S[cy][1]=='*') {
			ask(S_UD?"U":"D");
			cy++;
		}
		auto a=ask("L");
		if(a.second==1) {
			S_LR=1;
			ask("R");
		}
		else S_LR=0;
	}
	if(S_UD==-1) {
		while(S[1][cx]=='*') {
			ask(S_LR?"L":"R");
			cx++;
		}
		auto a=ask("U");
		if(a.first==1) {
			S_UD=1;
			ask("D");
		}
		else S_UD=0;
	}
	queue<int> Q;
	Q.push(TY*100+TX);
	vis[TY][TX]=1;
	while(Q.size()) {
		int sy=Q.front()/100;
		int sx=Q.front()%100;
		Q.pop();
		FOR(i,4) {
			int dd[4]={1,0,-1,0};
			int ty=sy+dd[i];
			int tx=sx+dd[i^1];
			if(ty<0 || ty>=H || tx<0 || tx>=W || S[ty][tx]=='*' || vis[ty][tx]) continue;
			vis[ty][tx]=1;
			Q.push(ty*100+tx);
			if(i==0) from[ty][tx]=S_UD?"D":"U";
			if(i==1) from[ty][tx]=S_LR?"R":"L";
			if(i==2) from[ty][tx]=S_UD?"U":"D";
			if(i==3) from[ty][tx]=S_LR?"L":"R";
		}
	}
	while(cy!=TY || cx!=TX) {
		auto p=ask(from[cy][cx]);
		cy=p.first;
		cx=p.second;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}