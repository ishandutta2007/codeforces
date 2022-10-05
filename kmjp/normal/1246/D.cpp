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
int P[101010];
vector<int> E[101010];
int D[101010];
int MD[101010],MV[101010];


vector<int> Vs;
vector<int> step;

void dfs(int cur) {
	vector<vector<int>> C;
	Vs.push_back(cur);
	FORR(e,E[cur]) {
		C.push_back({MD[e],MV[e],e});
	}
	sort(ALL(C));
	int i,j;
	FOR(i,C.size()) {
		dfs(C[i][2]);
		if(i<C.size()-1) {
			FOR(j,C[i][0]-D[cur]) step.push_back(C[i+1][2]);
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x;
		P[i+1]=x;
		E[x].push_back(i+1);
		D[i+1]=D[x]+1;
		MD[i+1]=D[i+1];
		MV[i+1]=D[i+1];
	}
	
	for(i=N-1;i>=0;i--) {
		FORR(e,E[i]) {
			if(MD[e]>MD[i]) MD[i]=MD[e],MV[i]=MV[e];
		}
	}
	
	dfs(0);
	
	FORR(v,Vs) cout<<v<<" ";
	cout<<endl;
	cout<<step.size()<<endl;
	FORR(s,step) cout<<s<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}