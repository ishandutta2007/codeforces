#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
pair<ll,int> WW[50101];
pair<ll,int> HH[50101];
ll W[50101];
ll H[50101];
int WP[50101],HP[50101],pos[50101];

ll dp2[3][50501];
ll dp[50501];

void update(int i) {
	if(i>N) return;
	dp2[0][i]=dp2[1][i]=dp2[2][i]=-1LL<<50;
	if(i) if(WP[i-1]!=HP[i-1]) dp2[0][i]=W[i-1]*H[i-1];
	if(i>1) if(WP[i-1]!=HP[i-2] && WP[i-2]!=HP[i-1]) dp2[1][i]=W[i-1]*H[i-2]+W[i-2]*H[i-1];
	if(i>2) {
		if(WP[i-1]!=HP[i-2] && WP[i-2]!=HP[i-3] && WP[i-3]!=HP[i-1]) dp2[2][i]=max(dp2[2][i],W[i-1]*H[i-2]+W[i-2]*H[i-3]+W[i-3]*H[i-1]);
		if(WP[i-1]!=HP[i-3] && WP[i-2]!=HP[i-1] && WP[i-3]!=HP[i-2]) dp2[2][i]=max(dp2[2][i],W[i-1]*H[i-3]+W[i-2]*H[i-1]+W[i-3]*H[i-2]);
		if(WP[i-1]!=HP[i-3] && WP[i-2]!=HP[i-2] && WP[i-3]!=HP[i-1]) dp2[2][i]=max(dp2[2][i],W[i-1]*H[i-3]+W[i-2]*H[i-2]+W[i-3]*H[i-1]);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	FOR(i,N) cin>>WW[i].first, WW[i].second=i;
	FOR(i,N) cin>>HH[i].first, HH[i].second=i;
	sort(WW,WW+N);
	sort(HH,HH+N);
	
	FOR(i,N) W[i]=WW[N-1-i].first, WP[i]=WW[N-1-i].second;
	FOR(i,N) H[i]=HH[N-1-i].first, HP[i]=HH[N-1-i].second, pos[HH[N-1-i].second]=i;
	FOR(i,N) update(i+1);
	
	dp[0]=dp[1]=dp[2]=-1LL<<60;
	
	while(Q--) {
		cin>>x>>y;
		x--,y--;
		swap(HP[pos[x]],HP[pos[y]]);
		swap(pos[x],pos[y]);
		FOR(i,3) update(pos[x]+1+i), update(pos[y]+1+i);
		
		for(i=1;i<=N;i++) dp[i+3]=max(max(dp[i+2]+dp2[0][i],dp[i+1]+dp2[1][i]),dp[i]+dp2[2][i]);
		cout<<dp[N+3]<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}