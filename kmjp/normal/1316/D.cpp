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

int N;
int X[1010][1010],Y[1010][1010];
string S[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	queue<int> Q;
	cin>>N;
	FOR(y,N) {
		S[y].resize(N,'.');
		
		FOR(x,N) {
			cin>>Y[y][x]>>X[y][x];
			Y[y][x]--;
			X[y][x]--;
			if(y==Y[y][x]&&x==X[y][x]) {
				S[y][x]='X';
				Q.push(y*1000+x);
			}
		}
	}
	while(Q.size()) {
		int cy=Q.front()/1000;
		int cx=Q.front()%1000;
		Q.pop();
		
		if(cy&&Y[cy-1][cx]==Y[cy][cx]&&X[cy-1][cx]==X[cy][cx]&&S[cy-1][cx]=='.') {
			S[cy-1][cx]='D';
			Q.push((cy-1)*1000+cx);
		}
		if(cy<N-1&&Y[cy+1][cx]==Y[cy][cx]&&X[cy+1][cx]==X[cy][cx]&&S[cy+1][cx]=='.') {
			S[cy+1][cx]='U';
			Q.push((cy+1)*1000+cx);
		}
		if(cx&&Y[cy][cx-1]==Y[cy][cx]&&X[cy][cx-1]==X[cy][cx]&&S[cy][cx-1]=='.') {
			S[cy][cx-1]='R';
			Q.push(cy*1000+cx-1);
		}
		if(cx<N-1&&Y[cy][cx+1]==Y[cy][cx]&&X[cy][cx+1]==X[cy][cx]&&S[cy][cx+1]=='.') {
			S[cy][cx+1]='L';
			Q.push(cy*1000+cx+1);
		}
	}
	FOR(y,N) FOR(x,N) {
		if(Y[y][x]==-2) {
			FOR(i,4) {
				int dd[4]={1,0,-1,0};
				int ty=y+dd[i];
				int tx=x+dd[i^1];
				if(ty>=0&&ty<N&&tx>=0&&tx<N&&Y[ty][tx]==-2) {
					if(i==0) S[y][x]='D';
					if(i==1) S[y][x]='R';
					if(i==2) S[y][x]='U';
					if(i==3) S[y][x]='L';
				}
			}
		}
		if(S[y][x]=='.') return _P("INVALID\n");
	}
	cout<<"VALID"<<endl;
	FOR(y,N) cout<<S[y]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}