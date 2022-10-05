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
vector<int> E[202020];
int ma;

int dp[101010][2];

void dfs(int cur,int pre) {
	int NC=E[cur].size()-(pre!=-1);
	int m[2]={0,0};
	vector<int> P[2];
	FORR(e,E[cur]) if(e!=pre) {
		dfs(e,cur);
		P[0].push_back(dp[e][0]);
		P[1].push_back(dp[e][1]);
		// not take
		ma=max(ma,max(m[0],m[1])+max(dp[e][0],dp[e][1])+(int)E[cur].size()-2);
		
		// take
		//cout<<"!"<<cur<<ma<<endl;
		ma=max(ma,m[0]+dp[e][0]+1);
		//cout<<"!"<<cur<<ma<<endl;
		m[0]=max(m[0],dp[e][0]);
		m[1]=max(m[1],dp[e][1]);
	}
	
	dp[cur][0]=max(0,max(m[0],m[1])+NC-1);
	dp[cur][1]=1+m[0];
	//cout<<cur<<" "<<dp[cur][0]<<" "<<dp[cur][1]<<endl;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	FOR(i,N) if(E[i].size()>1) {
		dfs(i,-1);
		break;
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}