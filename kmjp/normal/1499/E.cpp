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


int A,B;
string S,T;
ll dp[1010][1010][2][2][2];
const ll mo=998244353;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S>>T;
	A=S.size();
	B=T.size();
	ll ret=0;
	FOR(x,A+1) FOR(y,B+1) {
		dp[x][y][0][0][0]++;
		FOR(i,2) FOR(j,2) FOR(k,2) {
			ll v=dp[x][y][i][j][k];
			if(v==0) continue;
			if(i==0&&j==0) {
				if(x<A) (dp[x+1][y][1][0][0]+=v)%=mo;
				if(y<B) (dp[x][y+1][0][1][1]+=v)%=mo;
			}
			else if(k==0) {
				if(x<A&&S[x-1]!=S[x]) (dp[x+1][y][i|1][j][0]+=v)%=mo;
				if(y<B&&S[x-1]!=T[y]) (dp[x][y+1][i][j|1][1]+=v)%=mo;
			}
			else {
				if(x<A&&T[y-1]!=S[x]) (dp[x+1][y][i|1][j][0]+=v)%=mo;
				if(y<B&&T[y-1]!=T[y]) (dp[x][y+1][i][j|1][1]+=v)%=mo;
			}
		}
		ret+=dp[x][y][1][1][0]+dp[x][y][1][1][1];
	}
	cout<<ret%mo<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}