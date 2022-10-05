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

int H,W,Q;
pair<int,int> P[101][101];
int val[101][101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(y,H) FOR(x,W) P[y][x]={y,x};
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>y;
			y--;
			FOR(x,W-1) swap(P[y][x],P[y][x+1]);
		}
		else if(i==2) {
			cin>>x;
			x--;
			FOR(y,H-1) swap(P[y][x],P[y+1][x]);
		}
		else if(i==3) {
			cin>>y>>x>>k;
			auto r=P[y-1][x-1];
			val[r.first][r.second]=k;
		}
	}
	
	FOR(y,H) FOR(x,W) _P("%d%s",val[y][x],(x==W-1)?"\n":" ");
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}