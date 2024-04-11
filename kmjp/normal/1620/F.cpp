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

int T;
int N;
int P[1010101];

pair<int,int> from[1010101][2][2];
int dp[1010101][2][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&N);
		FOR(i,N) scanf("%d",&P[i]);
		
		FOR(i,N) dp[i][0][0]=dp[i][0][1]=dp[i][1][0]=dp[i][1][1]=1LL<<30;
		dp[0][0][0]=dp[0][0][1]=-1LL<<30;
		
		int pos,sig,ns;
		FOR(i,N-1) FOR(pos,2) FOR(sig,2) if(dp[i][pos][sig]<1<<30) {
			if(pos==0) {
				x=(sig?-P[i]:P[i]);
				y=dp[i][pos][sig];
			}
			else {
				x=dp[i][pos][sig];
				y=(sig?-P[i]:P[i]);
			}
			FOR(ns,2) {
				int v=ns?-P[i+1]:P[i+1];
				
				if(v>x) {
					if(chmin(dp[i+1][0][ns],y)) from[i+1][0][ns]={pos,sig};
				}
				else if(v>y) {
					if(chmin(dp[i+1][1][ns],x)) from[i+1][1][ns]={pos,sig};
				}
			}
		}
		pos=sig=-1;
		FOR(x,2) FOR(y,2) if(dp[N-1][x][y]<1<<30) pos=x, sig=y;
		if(pos==-1) {
			cout<<"NO"<<endl;
		}
		else {
			for(i=N-1;i>=0;i--) {
				if(sig) P[i]=-P[i];
				auto p=from[i][pos][sig];
				pos=p.first;
				sig=p.second;
			}
			cout<<"YES"<<endl;
			FOR(i,N) cout<<P[i]<<" ";
			cout<<endl;
		}
		
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}