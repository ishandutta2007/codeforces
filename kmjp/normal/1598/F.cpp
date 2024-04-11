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


int N;
int S[20];
int dp[1<<20];
vector<int> cand[20];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>s;
		cand[i].push_back(0);
		FORR(c,s) {
			if(c=='(') S[i]++;
			else S[i]--;
			
			if(S[i]<-((int)cand[i].size()-1)) cand[i].push_back(0);
			if(S[i]==-((int)cand[i].size()-1)) cand[i].back()++;
		}
	}
	int mask;
	FOR(mask,1<<N) dp[mask]=-(1<<20);
	dp[0]=0;
	int ret=0;
	FOR(mask,1<<N) if(dp[mask]>=0) {
		int sum=0;
		FOR(i,N) if(mask&(1<<i)) sum+=S[i];
		FOR(i,N) if((mask&(1<<i))==0) {
			int mi=((int)cand[i].size()-1);
			if(sum-mi>0) {
				dp[mask|(1<<i)]=max(dp[mask|(1<<i)],dp[mask]);
			}
			else if(sum-mi==0) {
				dp[mask|(1<<i)]=max(dp[mask|(1<<i)],dp[mask]+cand[i].back());
			}
			
			if(sum<=mi) ret=max(ret,dp[mask]+cand[i][sum]);
		}
		ret=max(ret,dp[mask]);
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}