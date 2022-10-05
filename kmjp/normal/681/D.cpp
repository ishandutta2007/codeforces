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
int P[101010];
vector<int> C[101010];
vector<int> R;
int A[101010];
int T[101010];

int dfs(int cur) {
	int pt=0;
	FORR(r,C[cur]) pt += dfs(r);
	if(cur==0) return 0;
	A[T[cur]]++;
	pt++;
	if(A[cur]>0) {
		if(pt!=A[cur]) {
			_P("-1\n");
			exit(0);
		}
		R.push_back(cur);
		pt=0;
	}
	return pt;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y;
		P[y]=x;
		C[x].push_back(y);
	}
	for(i=1;i<=N;i++) if(P[i]==0) C[0].push_back(i);
	for(i=1;i<=N;i++) cin>>T[i];
	dfs(0);
	
	_P("%d\n",R.size());
	FORR(r,R) _P("%d\n",r);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}