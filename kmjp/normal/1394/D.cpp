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
ll T[202020],H[202020];
vector<int> E[202020];

ll dp[202020][2];

void dfs(int cur,int pre) {
	int in=0,out=0;
	ll ret=0;
	vector<ll> dif;
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		if(H[e]>H[cur]) {
			out++;
			ret+=dp[e][0];
		}
		else if(H[cur]>H[e]) {
			in++;
			ret+=dp[e][1];
		}
		else {
			out++;
			ret+=dp[e][0];
			dif.push_back(dp[e][1]-dp[e][0]);
		}
	}
	
	sort(ALL(dif));
	dp[cur][0]=dp[cur][1]=1LL<<60;
	for(int num=0;num<=dif.size();num++) {
		
		if(cur==0) {
			dp[cur][0]=min(dp[cur][0],ret+T[cur]*max(in,out));
		}
		else {
			if(H[cur]>=H[pre]) {
				dp[cur][0]=min(dp[cur][0],ret+T[cur]*max(in+1,out));
			}
			if(H[pre]>=H[cur]) {
				dp[cur][1]=min(dp[cur][1],ret+T[cur]*max(in,out+1));
			}
			
		}
		//cout<<cur<<" "<<in<<" "<<out<<" "<<dp[cur][0]<<" "<<dp[cur][1]<<endl;
		if(num<dif.size()) {
			out--;
			in++;
			ret+=dif[num];
		}
	}
	
	
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>T[i];
	FOR(i,N) cin>>H[i];
	FOR(i,N-1) {
		cin>>x>>y;
		x--,y--;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	dfs(0,0);
	cout<<dp[0][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}