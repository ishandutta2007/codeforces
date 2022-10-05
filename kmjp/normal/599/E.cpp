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

int N,M,Q;
int mat[15][15];
ll dp[15][15][1<<13];
int U[30],V[30];
int A[101],B[101],C[101];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	FOR(i,M) cin>>U[i]>>V[i], U[i]--, V[i]--;
	FOR(i,Q) {
		cin>>A[i]>>B[i]>>C[i], A[i]--, B[i]--, C[i]--;
		if(A[i]==B[i]) {
			if(A[i]!=C[i]) return _P("0\n");
			i--;
			Q--;
		}
	}
	
	for(int mask=1;mask<1<<N;mask++) {
		FOR(i,N) if(mask & (1<<i)) {
			if(__builtin_popcount(mask)==1) {
				dp[i][0][mask] = 1;
			}
			else {
				for(int root=mask; root>0; root=(root-1)&mask) if(root&(1<<i)) {
					int add = mask ^ root;
					
					FOR(j,N) if(add&(1<<j)) {
						int ng=0;
						FOR(x,M) {
							if((root&(1<<U[x])) && (add&(1<<V[x])) && (i!=U[x] || j!=V[x])) break;
							if((root&(1<<V[x])) && (add&(1<<U[x])) && (i!=V[x] || j!=U[x])) break;
						}
						if(x<M) continue;
						FOR(x,Q) if(i!=C[x]) {
							if(root & (1<<C[x])) {
								if(!(root&(1<<A[x])) || !(root&(1<<B[x]))) break;
							}
							else if(add & (1<<C[x])) {
								if(!(add&(1<<A[x])) || !(add&(1<<B[x]))) break;
							}
							else {
								if((mask&(1<<A[x])) && (mask&(1<<B[x]))) break;
							}
						}
						
						if(x==Q) dp[i][j][mask] += dp[i][j][root]*dp[j][N][add];
					}
				}
			}
			FOR(j,N) dp[i][j+1][mask] += dp[i][j][mask];
		}
	}
	
	cout<<dp[0][N][(1<<N)-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}