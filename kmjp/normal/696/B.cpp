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
int V[101010];
vector<int> E[101010];
double T[101010];

void dfs(int cur,double tim) {
	tim+=1;
	T[cur]= tim;
	FORR(r,E[cur]) {
		double el=(V[cur]-1-V[r])*0.5;
		dfs(r,tim+el);
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	for(i=1;i<N;i++) cin>>P[i], P[i]--, E[P[i]].push_back(i);
	for(i=N-1;i>=0;i--) {
		V[i]++;
		if(i) V[P[i]]+=V[i];
	}
	
	dfs(0,0);
	FOR(i,N) _P("%lf%c", T[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}