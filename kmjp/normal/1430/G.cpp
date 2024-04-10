#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,M;
int W[20][20];
ll sum[1<<18];
int A[20];
ll mi[1<<18];
int from[1<<18];
int ng[1<<18];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>x>>y>>r;
		x--,y--;
		W[x][y]=r;
	}
	int mask;
	FOR(mask,1<<N) {
		FOR(j,N) FOR(i,N) if(i!=j&&(mask&(1<<i))&&(mask&(1<<j))&&W[i][j]) ng[mask]=1;
		if(ng[mask]) mi[mask]=1LL<<60;
	}
	for(mask=1;mask<1<<N;mask++) if(mi[mask]<1LL<<60) {
		FOR(i,N) FOR(j,N) if(W[i][j]) {
			if((mask&(1<<i)) && (mask&(1<<j))==0) mi[mask]+=W[i][j];
			if((mask&(1<<i))==0 && (mask&(1<<j))) mi[mask]=1LL<<60;
		}
		int lef=((1<<N)-1)^mask;
		for(int sm=lef; sm>0; sm=(sm-1)&lef) {
			if(ng[sm]==0&&mi[sm|mask]>mi[mask]) {
				mi[sm|mask]=mi[mask];
				from[sm|mask]=mask;
			}
		}
	}
	
	x=(1<<N)-1;
	int cur=100;
	while(x) {
		y=from[x];
		FOR(i,N) if((x^y)&(1<<i)) A[i]=cur;
		cur++;
		x=y;
	}
	FOR(i,N) cout<<A[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}