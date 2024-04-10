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

int N,M,Q;
int W[1<<12];
int C[1<<12];
char S[13];
int CS[1<<12][1300];
int K;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d%d",&N,&M,&Q);
	FOR(i,N) scanf("%d",&W[i]);
	FOR(i,M) {
		scanf("%s",S);
		x=0;
		FOR(j,N) if(S[j]=='1') x|=1<<j;
		C[x]++;
	}
	
	FOR(i,1<<N) FOR(j,1<<N) {
		x=0;
		FOR(y,N) if(((i>>y)&1)==((j>>y)&1)) x+=W[y];
		CS[i][x] += C[j];
	}
	
	FOR(i,1<<N) FOR(x,1210) CS[i][x+1]+=CS[i][x];
	
	FOR(i,Q) {
		scanf("%s%d",S,&K);
		x=0;
		FOR(j,N) if(S[j]=='1') x|=1<<j;
		_P("%d\n",CS[x][K]);
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}