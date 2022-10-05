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
int A[1010];
int nex[1010][8][130];
int V[10];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i+1], A[i+1]--;
	FOR(i,8) nex[N][i][1]=nex[N+1][i][1]=N+1;
	FOR(i,8) nex[N][i][0]=N, nex[N+1][i][0]=N+1;
	for(i=N-1;i>=0;i--) {
		FOR(x,8) {
			nex[i][x][0]=i;
			if(A[i+1]==x) nex[i][x][1]=i+1;
			else nex[i][x][1]=nex[i+1][x][1];
		}
	}
	
	for(i=2;i<=128;i++) {
		FOR(x,N+2) {
			FOR(y,8) nex[x][y][i]=nex[nex[x][y][i-1]][y][1];
		}
	}
	
	int ma=0;
	FOR(i,8) V[i]=i;
	do {
		for(i=125;i>=1;i--) {
			x=0;
			FOR(y,8) x=nex[x][V[y]][i];
			if(x<=N) break;
		}
		
		int len=i,mask;
		ma=max(ma,len*8);
		FOR(mask,256) {
			x=0;
			FOR(y,8) x=nex[x][V[y]][len+((mask&(1<<y))>0)];
			if(x<=N) ma=max(ma,len*8+__builtin_popcount(mask));
		}
		
		
	} while(next_permutation(V,V+8));
	
	
	cout<<ma<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}