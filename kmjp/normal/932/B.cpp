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


int G[1010101];
int num[10][1010101];
int Q,L,R,K;

int getg(int v) {
	if(G[v]>=0) return G[v];
	if(v<10) return v;
	int a=1;
	while(v) {
		if(v%10) a*=v%10;
		v/=10;
	}
	return getg(a);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(G);
	for(int i=1;i<=1000000;i++) {
		G[i]=getg(i);
		FOR(x,10) {
			num[x][i]=num[x][i-1];
		}
		num[G[i]][i]++;
	}
	
	scanf("%d",&Q);
	while(Q--) {
		scanf("%d%d%d",&L,&R,&K);
		_P("%d\n",num[K][R]-num[K][L-1]);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}