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

int N,M;
int A[10][101010];
vector<int> V[101010];
int ok[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(y,M) {
		FOR(x,N) scanf("%d",&A[y][x]);
		FOR(x,N-1) V[A[y][x]].push_back(A[y][x+1]);
		V[A[y][N-1]].push_back(N+1+y);
	}
	FOR(i,N+1) {
		if(V[i].size()) {
			if(*min_element(ALL(V[i]))==*max_element(ALL(V[i]))) ok[i]=1;
		}
	}
	
	ll ret=0;
	int cur=0;
	for(i=N-1;i>=0;i--) {
		if(ok[A[0][i]]) cur++;
		else cur=1;
		ret+=cur;
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}