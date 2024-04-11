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
string S,T;
int A,B;
const ll mo=1000000007;

int ok[555];
ll dp[555][555];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>Q;
	while(Q--) {
		cin>>S>>T;
		A=S.size();
		B=T.size();
		ZERO(ok);
		for(i=0;i+B<=A;i++) ok[i]=S.substr(i,B)==T;
		ZERO(dp);
		dp[0][0]=1;
		FOR(i,A) {
			if(ok[i]==0) {
				FOR(x,A+1) (dp[i+1][x]+=dp[i][x])%=mo;
			}
			else {
				FOR(y,B) if(ok[i+y]) {
					FOR(x,A+1) (dp[i+y+B][x+1]+=dp[i][x])%=mo;
				}
			}
		}
		FOR(i,A+1) if(dp[A][i]) {
			cout<<i<<" "<<dp[A][i]<<endl;
			break;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}