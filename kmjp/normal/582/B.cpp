#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,T,M;
map<int,int> MM;
int A[3030];
int pat[26][101][101];
int res[26][101][101];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>T;
	FOR(i,N) cin>>A[i], MM[A[i]]++;
	M=0;
	FORR(r,MM) r.second=M++;
	FOR(i,N) A[i]=MM[A[i]];
	FOR(i,N) FOR(x,A[i]+1) for(y=A[i];y>=x;y--) pat[0][x][A[i]] = max(pat[0][x][A[i]],pat[0][x][y]+1);
	FOR(i,101) FOR(y,M) FOR(x,y) pat[0][x][y] = max(pat[0][x][y],max(pat[0][x+1][y],pat[0][x][y-1]));
	
	FOR(i,25) FOR(y,M) FOR(x,y+1) {
		for(z=x;z<=y;z++) pat[i+1][x][y] = max(pat[i+1][x][y],pat[i][x][z]+pat[i][z][y]);
		if(T&(1<<i)) {
			for(z=x;z<=y;z++) res[i+1][x][y] = max(res[i+1][x][y], res[i][x][z]+pat[i][z][y]);
		}
		else res[i+1][x][y]=res[i][x][y];
	}
	
	cout<<res[25][0][M-1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}