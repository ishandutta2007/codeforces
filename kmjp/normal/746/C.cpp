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

int S,X1,X2;
int T1,T2;
int P,D;

int dp[1010];
int FR[1010];
int FL[1010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>X1>>X2>>T1>>T2;
	cin>>P>>D;
	FOR(i,S+1) dp[i]=1<<30;
	
	x=P;
	y=D;
	FOR(i,2*S) {
		if(x==0) y=1;
		if(x==S) y=-1;
		if(y>0) FR[x]=i*T1;
		else FL[x]=i*T1;
		x+=y;
	}
	
	
	priority_queue<pair<int,int>> Q;
	dp[X1]=0;
	Q.push({0,X1});
	while(Q.size()) {
		auto k=Q.top();
		Q.pop();
		x=k.second;
		y=-k.first;
		if(dp[x]!=y) continue;
		if(x && dp[x-1]>y+T2) {
			dp[x-1]=y+T2;
			Q.push({-dp[x-1],x-1});
		}
		if(x<S && dp[x+1]>y+T2) {
			dp[x+1]=y+T2;
			Q.push({-dp[x+1],x+1});
		}
		if(x>0) {
			r=FL[x];
			while(r<dp[x]) r+=2*S*T1;
			if(dp[x-1]>r+T1) {
				dp[x-1]=r+T1;
				Q.push({-dp[x-1],x-1});
			}
		}
		if(x<S) {
			r=FR[x];
			while(r<dp[x]) r+=2*S*T1;
			if(dp[x+1]>r+T1) {
				dp[x+1]=r+T1;
				Q.push({-dp[x+1],x+1});
			}
		}
		
		
	}
	cout<<dp[X2]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}