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
pair<int,int> P[202020];
ll dp[202020];
int from[202020];
int T[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>P[i].first;
		P[i].second=i;
	}
	sort(P,P+N);
	FOR(i,N+1) dp[i]=1LL<<60;
	dp[0]=0;
	
	FOR(i,N) {
		for(k=3;k<=5;k++) if(i+k<=N) {
			if(dp[i]+P[i+k-1].first-P[i].first<dp[i+k]) {
				dp[i+k]=dp[i]+P[i+k-1].first-P[i].first;
				from[i+k]=k;
			}
		}
	}
	
	x=1;
	y=N;
	while(y) {
		r=from[y];
		FOR(k,r) {
			y--;
			T[P[y].second]=x;
		}
		x++;
	}
	x--;
	cout<<dp[N]<<" "<<x<<endl;
	FOR(i,N) cout<<T[i]<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}