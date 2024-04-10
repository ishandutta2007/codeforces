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



int N,Q;
int P[202020],TP[202020],TG[202020];
char C[202020];
vector<int> E[202020];
int D[202020],TD;
set<int> MD;
int id;
int L[202020],R[202020];
set<int> ng;
int add[202020][2][26];
int dp[202020][26];
int sum[202020];

int update(int x,int c,int dif) {
	int t=L[x];
	x=TP[x];
	
	if(L[E[x][0]]<=t && t<R[E[x][0]]) add[x][0][c]+=dif;
	else add[x][1][c]+=dif;
	
	while(1) {
		sum[x]-=dp[x][c];
		if(E[x].size()==1) {
			dp[x][c]=dp[TG[E[x][0]]][c]+add[x][0][c];
		}
		else {
			dp[x][c]=max(dp[TG[E[x][0]]][c]+add[x][0][c],dp[TG[E[x][1]]][c]+add[x][1][c]);
		}
		sum[x]+=dp[x][c];
		
		if(sum[x]>TD-D[x]) ng.insert(x);
		else ng.erase(x);
		
		if(x==0) break;
		x=TP[x];
	}
	
}

void dfs(int cur,int depth) {
	D[cur]=depth;
	L[cur]=id++;
	TG[cur]=cur;
	if(cur) {
		if(E[P[cur]].size()==1) TP[cur]=TP[P[cur]];
		else TP[cur]=P[cur];
	}
	
	if(E[cur].size()) {
		FORR(e,E[cur]) dfs(e,depth+1);
	}
	else {
		MD.insert(D[cur]);
	}
	R[cur]=id;
	
	
	if(E[cur].size()==1) TG[cur]=TG[E[cur][0]];
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N-1) {
		cin>>P[i+1]>>C[i+1];
		P[i+1]--;
		E[P[i+1]].push_back(i+1);
	}
	
	dfs(0,0);
	if(MD.size()>1) {
		FOR(i,Q) cout<<"Fou"<<endl;
		return;
	}
	TD=*MD.begin();
	FOR(i,N) if(i && C[i]!='?') update(i,C[i]-'a',1);
	while(Q--) {
		cin>>x>>s;
		x--;
		if(C[x]!='?') update(x,C[x]-'a',-1);
		C[x]=s[0];
		if(C[x]!='?') update(x,C[x]-'a',1);
		
		if(ng.size()) {
			cout<<"Fou"<<endl;
			
		}
		else {
			int sum=TD;
			FOR(j,26) sum-=dp[0][j];
			ll ret=0;
			FOR(j,26) ret+=(sum+dp[0][j])*(j+1);
			cout<<"Shi "<<ret<<endl;
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}