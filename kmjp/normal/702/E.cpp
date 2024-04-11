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
ll K;
int F[101010][41];
ll W[101010][41];
ll S[101010][41];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) cin>>F[i][0];
	FOR(i,N) cin>>W[i][0], S[i][0]=W[i][0];
	
	FOR(i,40) {
		FOR(x,N) F[x][i+1]=F[F[x][i]][i];
		FOR(x,N) W[x][i+1]=min(W[x][i],W[F[x][i]][i]);
		FOR(x,N) S[x][i+1]=S[x][i]+S[F[x][i]][i];
	}
	
	FOR(i,N) {
		ll X=K;
		ll mi=1LL<<40;
		ll tot=0;
		int cur=i;
		FOR(j,40) if(X&(1LL<<j)) {
			mi=min(mi,W[cur][j]);
			tot+=S[cur][j];
			cur=F[cur][j];
		}
		cout<<tot<<" "<<mi<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}