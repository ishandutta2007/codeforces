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
double P[20][20];
double dp[1<<18][18];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(y,N) FOR(x,N) cin>>P[y][x];
	if(N==1) return _P("1.0\n");
	
	dp[1][0]=1;
	for(int mask=2;mask<1<<N;mask++) {
		FOR(x,N) FOR(y,N) if(x!=y && ((mask>>x)&1) && ((mask>>y)&1))
			dp[mask][x] = max(dp[mask][x], dp[mask^(1<<x)][y]*P[y][x] + dp[mask^(1<<y)][x]*P[x][y]);
	}
	
	_P("%.12lf\n",*max_element(dp[(1<<N)-1],dp[(1<<N)-1]+N));
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}