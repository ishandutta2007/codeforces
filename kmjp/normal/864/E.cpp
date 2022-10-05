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
int T[101],D[101],P[101];

int dp[2020];
vector<int> from[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	vector<pair<int,int>> cand;
	
	cin>>N;
	FOR(i,N) cin>>T[i]>>D[i]>>P[i], D[i]--, cand.push_back({D[i],i});
	
	sort(ALL(cand));
	FOR(i,2020) dp[i]=-1<<30;
	dp[0]=0;
	FORR(c,cand) {
		int i=c.second;
		for(x=D[i]-T[i];x>=0;x--) if(dp[x+T[i]]<dp[x]+P[i]) {
			dp[x+T[i]]=dp[x]+P[i];
			from[x+T[i]]=from[x];
			from[x+T[i]].push_back(i+1);
		}
	}
	
	int ma=max_element(dp,dp+2020)-dp;
	_P("%d\n",dp[ma]);
	reverse(ALL(from[ma]));
	_P("%d\n",from[ma].size());
	FOR(i,from[ma].size()) _P("%d%c",from[ma][from[ma].size()-1-i],(i==from[ma].size()-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}