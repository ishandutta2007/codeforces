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

int T,N,M;
int vis[303030];
vector<int> E[303030];
ll p2[303030];
ll mo=998244353;
int pat[2];

void dfs(int cur,int col) {
	if(vis[cur]!=-1) {
		if(vis[cur]!=col) pat[0]=pat[1]=-1<<30;
		return;
	}
	
	vis[cur]=col;
	pat[col]++;
	FORR(e,E[cur]) dfs(e,col^1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=1;
	FOR(i,301000) p2[i+1]=p2[i]*2%mo;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		FOR(i,N) {
			E[i].clear();
			vis[i]=-1;
		}
		FOR(i,M) {
			cin>>x>>y;
			E[x-1].push_back(y-1);
			E[y-1].push_back(x-1);
		}
		ll ret=1;
		FOR(i,N) if(vis[i]==-1) {
			pat[0]=pat[1]=0;
			dfs(i,0);
			
			if(pat[0]<0 || pat[1]<0) ret=0;
			else {
				(ret*=(p2[pat[0]]+p2[pat[1]]))%=mo;
			}
		}
		cout<<ret%mo<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}