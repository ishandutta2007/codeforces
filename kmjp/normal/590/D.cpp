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

int N,K,S;
int Q[1010];

int from[151][150*161],to[151][150*161];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K>>S;
	FOR(i,N) cin>>Q[i];
	
	FOR(x,N) FOR(y,150*80) from[x][y]=1<<29;
	from[0][0]=0;
	for(i=N-1;i>=0;i--) {
		for(x=K;x>=0;x--) for(y=150*80;y>=0;y--) {
			to[x][y]=1<<29;
			if(from[x][y]<1<<29) {
				// take
				if(x<K) to[x+1][y] = min(to[x+1][y],from[x][y]+Q[i]);
				// nottake
				to[x][y+x] = min(to[x][y+x],from[x][y]);
			}
		}
		swap(from,to);
	}
	
	int mi=1<<29;
	FOR(i,min(S+1,N*(N-1)/2+1)) mi=min(mi,from[K][i]);
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}