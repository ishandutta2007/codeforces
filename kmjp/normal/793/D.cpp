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

int memo[82][82][82][82];
int path[82][82];

int N,K,M;

int hoge(int L,int C,int R,int K) {
	if(K==1) return 0;
	if(memo[L+1][C+1][R+1][K]!=-1) return memo[L+1][C+1][R+1][K];
	if(C-L<K && R-C<K) return 1<<20;
	int ret=1<<20, i;
	if(C-L>=K) {
		for(i=L+1;i<C;i++) if(path[C][i]<1<<20) ret=min(ret,path[C][i]+hoge(L,i,C,K-1));
	}
	if(R-C>=K) {
		for(i=C+1;i<R;i++) if(path[C][i]<1<<20) ret=min(ret,path[C][i]+hoge(C,i,R,K-1));
	}
	return memo[L+1][C+1][R+1][K]=ret;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(memo);
	cin>>N>>K>>M;
	FOR(y,N) FOR(x,N) path[y][x]=1<<20;
	
	FOR(i,M) {
		cin>>x>>y>>j;
		x--,y--;
		path[x][y]=min(path[x][y],j);
	}
	
	int mi=1<<20;
	FOR(i,N) mi=min(mi,hoge(-1,i,N,K));
	if(mi>=1<<20) mi=-1;
	cout<<mi<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}