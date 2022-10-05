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
ll P[2020][2020];
ll dist[2020];
int vis[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	ll mi=1LL<<60;
	for(i=0;i<N;i++) {
		for(j=i+1;j<N;j++) {
			cin>>P[i][j];
			P[j][i]=P[i][j];
			mi=min(mi,P[i][j]);
		}
	}
	
	FOR(x,N) {
		dist[x]=1LL<<60;
		FOR(y,N) if(x!=y) {
			P[x][y]-=mi;
			dist[x]=min(dist[x],P[x][y]*2);
		}
	}
	FOR(i,N) {
		int id=-1;
		FOR(x,N) if(vis[x]==0 && (id==-1 || dist[x]<dist[id])) id=x;
		vis[id]=1;
		FOR(y,N) dist[y]=min(dist[y],dist[id]+P[id][y]);
	}
	FOR(i,N) cout<<dist[i]+(N-1)*mi<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}