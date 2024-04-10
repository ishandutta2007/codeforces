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
string S;
int cost[202020][3];
int from[202020][3];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FORR(c,S) {
		if(c=='B') c=0;
		if(c=='G') c=1;
		if(c=='R') c=2;
	}
	FOR(i,N+1) cost[i][0]=cost[i][1]=cost[i][2]=1<<20;
	
	cost[0][0]=S[0]!=0;
	cost[0][1]=S[0]!=1;
	cost[0][2]=S[0]!=2;
	for(i=1;i<N;i++) {
		cost[i][0]=cost[i][1]=cost[i][2]=1<<20;
		FOR(x,3) FOR(y,3) if(x!=y) {
			if(cost[i][y]>cost[i-1][x]+(S[i]!=y)) {
				cost[i][y]=cost[i-1][x]+(S[i]!=y);
				from[i][y]=x;
			}
		}
	}
	
	x=0;
	if(cost[N-1][1]<cost[N-1][0]) x=1;
	if(cost[N-1][2]<cost[N-1][x]) x=2;
	int ret=cost[N-1][x];
	
	string T;
	for(i=N-1;i>=0;i--) {
		T.push_back("BGR"[x]);
		x=from[i][x];
	}
	reverse(ALL(T));
	
	
	cout<<ret<<endl;
	cout<<T<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}