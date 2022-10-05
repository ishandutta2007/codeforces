#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int T,N;
string S;

int nex[202020][26];
int C[26];
int dp[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		FOR(i,26) C[i]=N+1;
		for(i=N-1;i>=0;i--) {
			C[S[i]-'a']=i;
			FOR(j,26) nex[i][j]=C[j];
		}
		FOR(i,N+1) dp[i]=1<<30;
		dp[0]=0;
		int ret=N;
		FOR(i,N) {
			ret=min(ret,dp[i]+N-i);
			FOR(j,26) {
				if(nex[i][j]<N-1) {
					x=nex[nex[i][j]+1][j]+1;
					if(x<=N) {
						dp[x]=min(dp[x],dp[i]+x-i-2);
					}
				}
			}
			dp[i+1]=min(dp[i+1],dp[i]+1);
		}
		ret=min(ret,dp[N]);
		cout<<ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}