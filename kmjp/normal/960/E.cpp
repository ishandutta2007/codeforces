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
int D[202020];
ll V[202020];
int C[202020][2];
vector<int> E[202020];
ll ret;
ll mo=1000000007;

void dfs(int cur,int pre,int d) {
	D[cur]=d;
	C[cur][d]=1;
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur,d^1);
		C[cur][0]+=C[e][0];
		C[cur][1]+=C[e][1];
	}
	
}
void dfs2(int cur,int pre) {
	int CC[2]={C[0][0],C[0][1]};
	CC[D[cur]]--;
	
	FORR(e,E[cur]) if(e!=pre) {
		dfs2(e,cur);
		
		ll ot=N-C[e][0]-C[e][1];
		(ret+=(V[cur]*ot%mo)*(C[e][D[cur]]-C[e][D[cur]^1]+mo))%=mo;
		
		CC[0]-=C[e][0];
		CC[1]-=C[e][1];
	}
	(ret+=(V[cur]*(N-CC[0]-CC[1])%mo)*(CC[D[cur]]-CC[D[cur]^1]+mo))%=mo;
	(ret+=(V[cur]*N%mo))%=mo;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>V[i];
		V[i]=(V[i]+mo)%mo;
	}
	
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	dfs(0,0,0);
	dfs2(0,0);
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}