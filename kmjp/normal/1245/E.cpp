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

int A[10][10];
int id[10][10];
double dp[100],best[100];
int to[100];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	int N=10;
	MINUS(to);
	FOR(y,N) {
		FOR(x,N) {
			if(y%2==0) {
				id[y][x]=y*10+x;
			}
			else {
				id[y][x]=y*10+9-x;
			}
		}
		FOR(x,N) {
			cin>>r;
			if(r>0) to[id[y][x]]=id[y-r][x];
		}
	}
	
	for(i=1;i<100;i++) {
		if(i<6) {
			dp[i]=6.0;
			FOR(j,i) dp[i]+=dp[j];
			dp[i]/=i;
			best[i]=dp[i];
		}
		else {
			dp[i]=6.0;
			FOR(j,6) dp[i]+=best[i-1-j];
			dp[i]/=6;
			best[i]=dp[i];
			if(to[i]>=0) {
				best[i]=min(best[i],dp[to[i]]);
			}
		}
	}
	_P("%.12lf\n",dp[99]);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}