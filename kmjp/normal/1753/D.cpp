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


int H,W;
ll A,B;
string S[303030];
vector<ll> dp[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>A>>B;
	priority_queue<pair<ll,int>> Q;
	FOR(y,H) {
		cin>>S[y];
		dp[y].resize(W);
		FOR(x,W) {
			if(S[y][x]=='.') {
				dp[y][x]=0;
				Q.push({0,y*W+x});
			}
			else {
				dp[y][x]=1LL<<60;
			}
		}
	}
	while(Q.size()) {
		ll co=-Q.top().first;
		int cy=Q.top().second/W;
		int cx=Q.top().second%W;
		Q.pop();
		if(dp[cy][cx]!=co) continue;
		
		if(cx>=2&&S[cy][cx-2]=='L'&&chmin(dp[cy][cx-2],co+B)) Q.push({-(co+B),cy*W+cx-2});
		if(cx+2<W&&S[cy][cx+2]=='R'&&chmin(dp[cy][cx+2],co+B)) Q.push({-(co+B),cy*W+cx+2});
		if(cy>=2&&S[cy-2][cx]=='U'&&chmin(dp[cy-2][cx],co+B)) Q.push({-(co+B),(cy-2)*W+cx});
		if(cy+2<H&&S[cy+2][cx]=='D'&&chmin(dp[cy+2][cx],co+B)) Q.push({-(co+B),(cy+2)*W+cx});
		if(cy+1<H&&cx+1<W&&(S[cy+1][cx+1]=='D'||S[cy+1][cx+1]=='R')&&chmin(dp[cy+1][cx+1],co+A)) Q.push({-(co+A),(cy+1)*W+cx+1});
		if(cy-1>=0&&cx+1<W&&(S[cy-1][cx+1]=='U'||S[cy-1][cx+1]=='R')&&chmin(dp[cy-1][cx+1],co+A)) Q.push({-(co+A),(cy-1)*W+cx+1});
		if(cy+1<H&&cx-1>=0&&(S[cy+1][cx-1]=='D'||S[cy+1][cx-1]=='L')&&chmin(dp[cy+1][cx-1],co+A)) Q.push({-(co+A),(cy+1)*W+cx-1});
		if(cy-1>=0&&cx-1>=0&&(S[cy-1][cx-1]=='U'||S[cy-1][cx-1]=='L')&&chmin(dp[cy-1][cx-1],co+A)) Q.push({-(co+A),(cy-1)*W+cx-1});
	}
	ll mi=1LL<<60;
	FOR(y,H) FOR(x,W) {
		if(y) mi=min(mi,dp[y-1][x]+dp[y][x]);
		if(x) mi=min(mi,dp[y][x-1]+dp[y][x]);
	}
	if(mi==1LL<<60) mi=-1;
	cout<<mi<<endl;
		
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}