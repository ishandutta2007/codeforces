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
vector<int> E[202020];
int P[202020][20];
int D[202020];

void dfs(int cur,int pre,int d) {
	P[cur][0]=pre;
	D[cur]=d;
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0,0);
	
	FOR(i,18) FOR(j,N) P[j][i+1]=P[P[j][i]][i];
	while(M--) {
		vector<pair<int,int>> V;
		cin>>x;
		while(x--) {
			cin>>y;
			y--;
			if(y) y=P[y][0];
			V.push_back({D[y],y});
		}
		sort(ALL(V));
		int ok=1;
		FOR(i,(int)V.size()-1) {
			x=V[i].second;
			y=V[i+1].second;
			
			for(j=18;j>=0;j--) if(D[y]-D[x]>=1<<j) y=P[y][j];
			if(x!=y) ok=0;
			
		}
		
		if(ok) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}