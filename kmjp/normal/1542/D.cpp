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
int E[505],O[505];

ll ret;
ll dp[505][505][2];
const ll mo=998244353;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<pair<int,int>> P;
	FOR(i,N) {
		cin>>s;
		if(s=="-") {
			E[i]=-1;
		}
		else {
			cin>>E[i];
			P.push_back({E[i],i});
		}
	}
	sort(ALL(P));
	FOR(i,P.size()) O[P[i].second]=i;
	FOR(i,P.size()) {
		ZERO(dp);
		dp[0][0][0]=1;
		FOR(x,N) {
			FOR(y,x+1) {
				dp[x+1][y][0]=dp[x][y][0];
				dp[x+1][y][1]=dp[x][y][1];
			}
			FOR(y,x+1) {
				if(E[x]==-1) {
					(dp[x+1][max(0,y-1)][0]+=dp[x][y][0])%=mo;
					if(y<=1) {
						(dp[x+1][0][0]+=dp[x][y][1])%=mo;
					}
					else {
						(dp[x+1][y-1][1]+=dp[x][y][1])%=mo;
					}
					
				}
				else if(O[x]<i) {
					(dp[x+1][y+1][0]+=dp[x][y][0])%=mo;
					(dp[x+1][y+1][1]+=dp[x][y][1])%=mo;
				}
				else if(O[x]==i) {
					(dp[x+1][y+1][1]+=dp[x][y][0])%=mo;
					(dp[x+1][y+1][1]+=dp[x][y][1])%=mo;
				}
				else {
					(dp[x+1][y][0]+=dp[x][y][0])%=mo;
					(dp[x+1][y][1]+=dp[x][y][1])%=mo;
				}
			}
		}
		ll pat=0;
		FOR(x,N+1) pat+=dp[N][x][1];
		(ret+=pat%mo*P[i].first)%=mo;
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}