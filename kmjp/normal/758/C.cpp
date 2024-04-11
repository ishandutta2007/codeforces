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
ll K,X,Y;
ll num[105][105];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K>>X>>Y;
	
	if(N==1) {
		FOR(x,M) num[0][x] = K/M;
		K%=M;
		FOR(x,M) if(K) num[0][x]++, K--;
	}
	else {
		FOR(y,N) FOR(x,M) {
			if(y==0 || y==N-1) num[y][x] = K/((2*N-2)*M);
			else num[y][x] = K/((2*N-2)*M)*2;
		}
		K%=((2*N-2)*M);
		FOR(y,N) FOR(x,M) if(K) num[y][x]++, K--;
		for(y=N-2;y>=0;y--) FOR(x,M) if(K) num[y][x]++, K--;
	}
	
	ll ma=-1, mi=1LL<<60;
	FOR(y,N) FOR(x,M) ma=max(ma,num[y][x]);
	FOR(y,N) FOR(x,M) mi=min(mi,num[y][x]);
	
	cout<<ma<<" "<<mi<<" "<<num[X-1][Y-1]<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}