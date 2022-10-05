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
vector<ll> C[4];
vector<pair<ll,ll>> D[4];

ll dp[202020][10];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	
	FOR(i,10) dp[0][i]=-1LL<<60;
	dp[0][0]=0;
	
	cin>>N;
	FOR(i,N) {
		FOR(j,10) dp[i+1][j]=-1LL<<60;
		cin>>x;
		FOR(j,4) {
			C[j].clear();
			D[j].clear();
		}
		while(x--) {
			cin>>k>>r;
			C[k].push_back(r);
		}
		FOR(j,4) {
			sort(ALL(C[j]));
			reverse(ALL(C[j]));
		}
		if(C[1].size()>=3) D[3].push_back({C[1][0],C[1][0]+C[1][1]+C[1][2]});
		if(C[1].size()>=2) D[2].push_back({C[1][0],C[1][0]+C[1][1]});
		if(C[1].size()>=1 && C[2].size()>=1) D[2].push_back({max(C[1][0],C[2][0]),C[1][0]+C[2][0]});
		if(C[1].size()>=1) D[1].push_back({C[1][0],C[1][0]});
		if(C[2].size()>=1) D[1].push_back({C[2][0],C[2][0]});
		if(C[3].size()>=1) D[1].push_back({C[3][0],C[3][0]});
		FOR(j,10) {
			dp[i+1][j]=max(dp[i+1][j],dp[i][j]);
			for(x=1;x<=3;x++) FORR(d,D[x]) {
				if(j+x>=10) dp[i+1][(j+x)%10]=max(dp[i+1][(j+x)%10],dp[i][j]+d.first+d.second);
				else dp[i+1][(j+x)%10]=max(dp[i+1][(j+x)%10],dp[i][j]+d.second);
			}
		}
		
	}
	
	cout<<*max_element(dp[N],dp[N]+10)<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}