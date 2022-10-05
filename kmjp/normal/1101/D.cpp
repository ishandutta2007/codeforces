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

const int prime_max = 200000;
int NP,prime[100000],divp[prime_max];

int N;
vector<int> C[202020];
vector<int> E[202020];
map<int,int> M[202020];
int ret;


void dfs(int cur,int pre) {
	FORR(c,C[cur]) M[cur][c]=1;
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		
		FORR(c,C[cur]) {
			ret=max(ret,M[cur][c]+M[e][c]);
			M[cur][c]=max(M[cur][c],M[e][c]+1);
		}
		
	}
	
	FORR(c,C[cur]) ret=max(ret,M[cur][c]);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N;
	FOR(i,N) {
		cin>>x;
		for(j=2;j*j<=200000;j++) if(x%j==0) {
			C[i].push_back(j);
			while(x%j==0) x/=j;
		}
		if(x>1) C[i].push_back(x);
		sort(ALL(C[i]));
	}
	
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,-1);
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}