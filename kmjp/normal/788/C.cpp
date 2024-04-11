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

int N,K;
int A[1011];
vector<int> V;
int dist[20202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&K);
	FOR(i,K) {
		scanf("%d",&x);
		A[x]=1;
	}
	
	FOR(i,20200) dist[i]=1<<30;
	queue<int> Q;
	FOR(i,1001) if(A[i]) {
		V.push_back(i-N);
		dist[10000+(i-N)]=1;
		Q.push(10000+(i-N));
	}
	
	while(Q.size()) {
		x = Q.front();
		Q.pop();
		int co=dist[x];
		if(x==10000) return _P("%d\n",dist[x]);
		FORR(r,V) {
			y = x + r;
			if(y>=0 && y<=20000 && dist[y]>co+1) {
				dist[y]=co+1;
				Q.push(y);
			}
		}
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