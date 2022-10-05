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
ll A[201010];
int T[202020][2];
int B[201010],C[201010];
vector<int> E[201010];
ll ret;

void dfs(int cur,int pre) {
	if(pre!=cur) A[cur]=min(A[cur],A[pre]);
	
	int F[2]={};
	if(B[cur]>C[cur]) F[0]++;
	if(B[cur]<C[cur]) F[1]++;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		F[0]+=T[e][0];
		F[1]+=T[e][1];
	}
	
	ret+=2*min(F[0],F[1])*A[cur];
	T[cur][0]=F[0]-min(F[0],F[1]);
	T[cur][1]=F[1]-min(F[0],F[1]);
	
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>A[i]>>B[i]>>C[i];
	}
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0);
	if(T[0][0]||T[0][1]) {
		cout<<"-1"<<endl;
	}
	else {
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}