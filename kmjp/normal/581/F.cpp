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

int N,D;
vector<int> E[5050];
int mi[5050];
int ma[5050];
int dp[5050][7100];

void dfs(int cur,int pre) {
	
	// last
	if(E[cur].size()==1) {
		dp[cur][3000+1]=0;
		mi[cur]=ma[cur]=1;
	}
	else {
		dp[cur][3000+0]=0;
		mi[cur]=ma[cur]=0;
		int x,y;
		FORR(tar,E[cur]) if(tar!=pre) {
			int tmp[7000];
			FOR(x,7000) tmp[x]=10000000;
			dfs(tar,cur);
			for(x=mi[cur];x<=ma[cur];x++) if(dp[cur][3000+x]<1000000) {
				for(y=mi[tar];y<=ma[tar];y++) if(dp[tar][3000+y]<1000000) {
					if(x+y<=D/2 && x+y>=-D/2) tmp[3000+x+y]=min(tmp[3000+x+y],dp[cur][3000+x]+dp[tar][3000+y]);
					if(x-y<=D/2 && x-y>=-D/2) tmp[3000+x-y]=min(tmp[3000+x-y],dp[cur][3000+x]+dp[tar][3000+y]+1);
				}
			}
			
			mi[cur]=max(-D/2, min(mi[cur]+mi[tar],mi[cur]-ma[tar]));
			ma[cur]=min(D/2,max(ma[cur]-mi[tar],ma[cur]+ma[tar]));
			for(x=mi[cur];x<=ma[cur];x++) dp[cur][3000+x]=tmp[3000+x];
		}
	}
	int x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	memset(dp,0x7f,sizeof(dp));
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	int st=N+1;
	FOR(i,N) {
		if(E[i].size()==1) D++;
		else st=min(st,i);
	}
	if(D==2) return _P("1\n");
	dfs(st,-1);
	cout<<dp[st][3000]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}