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

int T;
int N,M;
char S[101010];
int A[1010][1010];
int B[1010][1010];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&N,&M);
		FOR(y,N) FOR(x,N) scanf("%d",&A[y][x]), A[y][x]--;
		scanf("%s",S);
		int D[3]={};
		int V[3]={0,1,2};
		FOR(i,M) {
			if(S[i]=='R') D[1]++;
			if(S[i]=='L') D[1]--;
			if(S[i]=='U') D[0]--;
			if(S[i]=='D') D[0]++;
			if(S[i]=='I') swap(V[1],V[2]),swap(D[1],D[2]);
			if(S[i]=='C') swap(V[0],V[2]),swap(D[0],D[2]);
		}
		
		
		
		FOR(y,N) {
			FOR(x,N) {
				int C[3]={y,x,A[y][x]};
				int E[3]={C[V[0]]+D[0],C[V[1]]+D[1],C[V[2]]+D[2]};
				FOR(i,3) E[i]=(E[i]%N+N)%N;
				B[E[0]%N][E[1]%N]=E[2]%N;
			}
		}
		FOR(y,N) {
			FOR(x,N) _P("%d ",B[y][x]+1);
			_P("\n");
		}
		_P("\n");
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}