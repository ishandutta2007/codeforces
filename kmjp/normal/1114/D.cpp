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
int C[5050];
int memo[5050][5050][2];

int dfs(int L,int R,int T) {
	if(L==0 && R==N-1) return 0;
	if(memo[L][R][T]>=0) return memo[L][R][T];
	memo[L][R][T]=101010;
	if(L) {
		if(T==0) memo[L][R][T]=min(memo[L][R][T],dfs(L-1,R,0)+(C[L]!=C[L-1]));
		if(T==1) memo[L][R][T]=min(memo[L][R][T],dfs(L-1,R,0)+(C[R]!=C[L-1]));
	}
	if(R<N-1) {
		if(T==0) memo[L][R][T]=min(memo[L][R][T],dfs(L,R+1,1)+(C[L]!=C[R+1]));
		if(T==1) memo[L][R][T]=min(memo[L][R][T],dfs(L,R+1,1)+(C[R]!=C[R+1]));
	}
	return memo[L][R][T];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>C[i];
	int mi=101010;
	MINUS(memo);
	FOR(i,N) mi=min(mi,dfs(i,i,0));
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}