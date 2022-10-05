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
vector<int> V[16];
ll ma;
map<vector<int>,int> memo[4];

int ID(int x,int y) {
	if(x>y) swap(x,y);
	return x*4+y;
}

ll dfs(int cur,vector<int> C) {
	if(memo[cur].count(C)) return memo[cur][C];
	int i;
	ll ret=0;
	FOR(i,4) {
		int id=ID(cur,i);
		if(i==cur) {
			while(C[id]>=0) ret+=V[id][C[id]--];
		}
		else {
			while(C[id]>2) ret+=V[id][C[id]--]+V[id][C[id]--];
		}
	}
	ll ma=ret;
	FOR(i,4) {
		int id=ID(cur,i);
		if(C[id]>=0) {
			C[id]--;
			ma=max(ma,ret+V[id][C[id]+1]+dfs(i,C));
			C[id]++;
		}
	}
	
	return memo[cur][C]=ma;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>x>>r>>y;
		x--,y--;
		if(x>y) swap(x,y);
		V[x*4+y].push_back(r);
	}
	
	vector<int> cand(16);
	FOR(x,4) FOR(y,4) {
		sort(ALL(V[x*4+y]));
		cand[x*4+y]=(int)V[x*4+y].size()-1;
	}
	
	FOR(i,4) ma=max(ma,dfs(i,cand));
	
	
	cout<<ma<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}