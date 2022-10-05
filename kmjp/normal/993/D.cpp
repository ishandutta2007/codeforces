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
pair<int,int> P[51];
double dp[52][52][52];

int ok(double a) {
	int i;
	vector<double> V;
	FOR(i,N) V.push_back(P[i].first-P[i].second*a);
	
	int x,y,z;
	FOR(x,52) FOR(y,52) FOR(z,52) dp[x][y][z]=1e9;
	dp[0][0][0]=0;
	double mi=1e9;
	FOR(i,N) {
		FOR(x,52) FOR(y,52) {
			int z=i-2*x-y;
			if(z<0) break;
			if(y) dp[x+1][y-1][z]=min(dp[x+1][y-1][z],dp[x][y][z]);
			dp[x][y][z+1]=min(dp[x][y][z+1],dp[x][y][z]+V[i]);
		}
		if(i<N-1 && P[i].first!=P[i+1].first) {
			FOR(x,52) FOR(y,52) {
				int z=i-2*x-y+1;
				if(z>0) dp[x][y+z][0]=min(dp[x][y+z][0],dp[x][y][z]);
			}
		}
	}
	FOR(x,52) FOR(y,52) FOR(z,52) if(2*x+y+z==N) mi=min(mi,dp[x][y][z]);
	
	return mi<=0;
	
}



void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i].first;
	FOR(i,N) cin>>P[i].second;
	sort(P,P+N);
	reverse(P,P+N);
	
	double L=0,R=1e9;
	FOR(i,60) {
		double M=(L+R)/2;
		if(ok(M)) R=M;
		else L=M;
	}
	cout<<(ll)(1000*L+0.99)<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}