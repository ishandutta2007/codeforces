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
int A[101010];
vector<int> E[101010];
int C[101010];
ll num[101010][21];
ll ret;

void dfs(int cur,int pre) {
	int i;
	C[cur]=1;
	ret += A[cur];
	FOR(i,20) if(A[cur]&(1<<i)) num[cur][i]++;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		FOR(i,20) {
			ret += (num[cur][i]*(C[e]-num[e][i])+(C[cur]-num[cur][i])*num[e][i])<<i;
			if(A[cur]&(1<<i)) {
				num[cur][i] += C[e]-num[e][i];
			}
			else {
				num[cur][i] += num[e][i];
			}
		}
		C[cur] += C[e];
	}
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
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
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}