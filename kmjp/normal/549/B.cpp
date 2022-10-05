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

int N;
string mat[101];
int A[101];
int C[101],T[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) {
		cin>>mat[y];
		FOR(x,N) mat[y][x]-='0';
	}
	
	FOR(i,N) cin>>A[i], A[i]=-A[i];
	
	srand(time(NULL));
	FOR(i,101010) {
		
		vector<int> V;
		FOR(i,N) if(A[i]==0) V.push_back(i);
		
		if(V.empty()) {
			x=0;
			FOR(i,N) x+=C[i];
			_P("%d\n",x);
			FOR(i,N) if(C[i]) _P("%d ",i+1);
			_P("\n");
			return;
		}
		
		x=V[rand()%V.size()];
		
		FOR(y,N) {
			if(mat[x][y]) {
				if(C[x]) A[y]--;
				else A[y]++;
			}
		}
		C[x]^=1;
	}
	_P("-1\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}