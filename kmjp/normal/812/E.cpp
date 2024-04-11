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
int P[101010];
vector<int> E[101010];
int D[101010];
int nim,mad;

void dfs(int cur,int d) {
	mad=max(mad,d);
	D[cur]=d;
	FORR(e,E[cur]) dfs(e,d+1);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>A[i];
	FOR(i,N-1) {
		cin>>x;
		E[x-1].push_back(i+1);
	}
	
	dfs(0,0);
	map<int,int> M;
	int nim=0;
	FOR(i,N) {
		if(D[i]%2==mad%2) {
			nim^=A[i];
		}
		else {
			M[A[i]]++;
		}
	}
	ll ret=0;
	FOR(i,N) if(D[i]%2==mad%2) ret += M[nim^A[i]];
	if(nim==0) {
		ll num[2]={};
		FOR(i,N) {
			if(D[i]%2==mad%2) ret+=num[0],num[0]++;
			else ret+=num[1],num[1]++;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}