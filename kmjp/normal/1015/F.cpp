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
string S;
ll dp[202][202][202];
ll mo=1000000007;

int nex[201][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	
	FOR(i,S.size()) {
		FOR(j,2) {
			s=S.substr(0,i);
			s+=('('+j);
			while(s!=S.substr(0,s.size())) s=s.substr(1);
			nex[i][j]=s.size();
		}
	}
	nex[S.size()][0]=S.size();
	nex[S.size()][1]=S.size();
	
	
	dp[0][0][0]=1;
	FOR(i,2*N) {
		FOR(j,S.size()+1) {
			for(int cur=0;cur<=190;cur++) {
				ll v=dp[i][j][cur];
				
				(dp[i+1][nex[j][0]][cur+1]+=v)%=mo;
				if(cur) (dp[i+1][nex[j][1]][cur-1]+=v)%=mo;
			}
		}
	}
	
	cout<<dp[2*N][S.size()][0]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}