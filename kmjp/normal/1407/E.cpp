#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
vector<pair<int,int>> E[505050];

int D[505050];
int C[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,M) {
		scanf("%d%d%d",&x,&y,&j);
		E[y-1].push_back({x-1,j});
	}
	FOR(i,N) {
		D[i]=-1;
		C[i]=2;
	}
	
	D[N-1]=0;
	queue<int> Q;
	Q.push(N-1);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR2(e,c,E[x]){
			if(C[e]!=c) {
				C[e]=1-c;
			}
			else if(D[e]==-1) {
				D[e]=D[x]+1;
				Q.push(e);
			}
				
		}
	}
	cout<<D[0]<<endl;
	FOR(i,N) {
		if(C[i]==2) C[i]=0;
		cout<<C[i];
	}
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}