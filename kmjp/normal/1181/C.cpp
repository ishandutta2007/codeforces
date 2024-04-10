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
string S[1010];
int R[1010][1010];
int D[1010][1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W;
	FOR(y,H) {
		cin>>S[y];
		R[y][W-1]=1;
		for(x=W-2;x>=0;x--) {
			R[y][x]=1;
			if(S[y][x]==S[y][x+1]) R[y][x]+=R[y][x+1];
		}
	}
	FOR(x,W) D[H-1][x]=1;
	for(y=H-2;y>=0;y--) {
		FOR(x,W) {
			D[y][x]=1;
			if(S[y][x]==S[y+1][x]) D[y][x]+=D[y+1][x];
		}
	}
	ll ret=0;
	FOR(y,H) FOR(x,W) {
		int sy=y+D[y][x];
		if(sy>=H || D[y][x]!=D[sy][x]) continue;
		int ty=sy+D[sy][x];
		if(ty>=H || D[ty][x]<D[y][x]) continue;
		int mi=101010;
		for(int y2=y;y2<y+D[y][x]*3;y2++) mi=min(mi,R[y2][x]);
		ret+=mi;
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}