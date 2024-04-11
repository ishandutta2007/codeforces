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
int A[202020];
vector<int> E[202020];
ll ret[202020];
map<int,int> M[202020];

void dfs(int cur,int pre) {
	ret[A[cur]]++;
	
	M[cur][A[cur]]=1;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		FORR(m,M[e]) FORR(c,M[cur]) {
			int g=__gcd(m.first,c.first);
			ret[g]+=1LL*m.second*c.second;
		}
		//FORR(m,mp) M[cur][m.first]+=m.second;
		FORR(m,M[e]) M[cur][__gcd(A[cur],m.first)]+=m.second;
		M[e].clear();
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
	
	dfs(0,0);
	for(i=1;i<=200000;i++) if(ret[i]) cout<<i<<" "<<ret[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}