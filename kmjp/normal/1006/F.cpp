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
ll K;
ll A[21][21];
vector<ll> V[21][21][2];
void solve() {
	int i,j,k,l,r,x,y; string s;
	cin>>H>>W>>K;
	FOR(y,H) FOR(x,W) cin>>A[y][x];
	V[0][0][0].push_back(A[0][0]);
	V[H-1][W-1][1].push_back(A[H-1][W-1]);
	
	int step=H+W-2;
	int L=step/2,R=step-L;
	
	FOR(y,H) FOR(x,W) if(y+x<L) {
		if(y+1<H) FORR(v,V[y][x][0]) V[y+1][x][0].push_back(v^A[y+1][x]);
		if(x+1<W) FORR(v,V[y][x][0]) V[y][x+1][0].push_back(v^A[y][x+1]);
	}
	
	for(y=H-1;y>=0;y--) for(x=W-1;x>=0;x--) if((H-1-y)+(W-1-x)<R) {
		if(y) FORR(v,V[y][x][1]) V[y-1][x][1].push_back(v^A[y-1][x]);
		if(x) FORR(v,V[y][x][1]) V[y][x-1][1].push_back(v^A[y][x-1]);
	}
	
	ll ret=0;
	FOR(y,H) FOR(x,W) if(V[y][x][0].size() && V[y][x][1].size()) {
		map<ll,ll> M;
		FORR(v,V[y][x][0]) M[v]++;
		FORR(v,V[y][x][1]) ret+=M[K^v^A[y][x]];
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}