#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int N,M;
int X[202020],Y[202020];
int added[202020];

const int DI=100;
int mbt[DI+8][DI+8];
int dp[1<<20];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	FOR(i,N) {
		scanf("%d%d",&X[i],&Y[i]);
		X[i]=min(X[i],1<<20);
		Y[i]=min(Y[i],1<<20);
	}
	FOR(i,M) {
		if(i) dp[i]+=dp[i-1];
		scanf("%d%d",&x,&y);
		y--;
		int S=X[y]+Y[y];
		int add;
		if(x==1) {
			added[y]=i;
			add=1;
		}
		else {
			add=-1;
		}
		
		if(S>=DI) {
			for(x=added[y];x<M;x+=S) {
				if(x+X[y]<M) dp[x+X[y]]+=add;
				if(x+S<M) dp[x+S]-=add;
				if(x+X[y]<i&&i<=x+S) dp[i]+=add;
			}
		}
		else {
			j=(added[y]+X[y])%(S);
			k=(added[y]+S)%(S);
			if(j<k) {
				for(x=j;x<k;x++) mbt[S][x]+=add;
			}
			else {
				for(x=0;x<k;x++) mbt[S][x]+=add;
				for(x=j;x<S;x++) mbt[S][x]+=add;
			}
		}
		
		
		int ret=dp[i];
		for(x=1;x<DI;x++) ret+=mbt[x][i%x];
		printf("%d\n",ret);
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}