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

int Q;
string T,S[11];
int N,M;
int dp[111];
pair<int,int> ret[111];
int from[111];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>T>>N;
		M=T.size();
		FOR(i,N) cin>>S[i];
		FOR(i,M+1) dp[i]=500;
		dp[0]=0;
		FOR(i,M) if(dp[i]<500) {
			int ma=-1;
			FOR(j,N) if(i+S[j].size()<=M&&T.substr(i,S[j].size())==S[j]) {
				if(ma==-1||S[ma].size()<S[j].size()) ma=j;
			}
			if(ma>=0) {
				ret[i]={ma+1,i+1};
				for(j=1;j<=S[ma].size();j++) {
					if(dp[i+j]>dp[i]+1) {
						dp[i+j]=dp[i]+1;
						from[i+j]=i;
					}
				}
			}
		}
		
		
		if(dp[M]>=500) {
			cout<<-1<<endl;
		}
		else {
			cout<<dp[M]<<endl;
			x=M;
			while(x) {
				x=from[x];
				cout<<ret[x].first<<" "<<ret[x].second<<endl;
			}
		}
		
	}
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}