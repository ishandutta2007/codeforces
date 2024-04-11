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

int N,M;
int mat[401][401];

void solve() {
	int i,j,k,l,r,x,y,z; string s;
	
	cin>>N>>M;
	FOR(x,N) FOR(y,N) if(x!=y) mat[x][y]=1010;
	
	FOR(i,M) {
		cin>>x>>y;
		mat[x-1][y-1]=mat[y-1][x-1]=1;
	}
	if(mat[0][N-1]==1) {
		FOR(x,N) FOR(y,N) if(x!=y) mat[x][y]=(mat[x][y]==1)?1010:1;
	}
	
	FOR(z,N) FOR(x,N) FOR(y,N) mat[x][y]=min(mat[x][y],mat[x][z]+mat[z][y]);
	
	if(mat[0][N-1]>1000) return _P("-1\n");
	_P("%d\n",mat[0][N-1]);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}